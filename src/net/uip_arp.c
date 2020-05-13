/**
 * \addtogroup uip
 * @{
 */

/**
 * \defgroup uiparp uIP Address Resolution Protocol
 * @{
 *
 * The Address Resolution Protocol ARP is used for mapping between IP
 * addresses and link level addresses such as the Ethernet MAC
 * addresses. ARP uses broadcast queries to ask for the link level
 * address of a known IP address and the host which is configured with
 * the IP address for which the query was meant, will respond with its
 * link level address.
 *
 * \note This ARP implementation only supports Ethernet.
 */

/**
 * \file
 * Implementation of the ARP Address Resolution Protocol.
 * \author Adam Dunkels <adam@dunkels.com>
 *
 */

/*
 * Copyright (c) 2001-2003, Adam Dunkels.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This file is part of the uIP TCP/IP stack.
 *
 * $Id: uip_arp.c,v 1.17 2014/05/22 03:42:34 kevinwu Exp $
 *
 */


#include "uip_arp.h"

#ifndef __BOOTLOADER__
#ifdef CFG_ZEROCONF_AUTOIP_INCLUDED
#include "appl/persistence.h"
#endif /* CFG_ZEROCONF_AUTOIP_INCLUDED */
#endif /* __BOOTLOADER__ */

#ifdef CFG_ZEROCONF_AUTOIP_INCLUDED
#include "utils/net.h"
#ifdef CFG_ZEROCONF_MDNS_INCLUDED
#include "appl/mdns.h"
#endif /* CFG_ZEROCONF_MDNS_INCLUDED */
#endif /* CFG_ZEROCONF_AUTOIP_INCLUDED */

#pragma pack(1)
/**定义ARP相关的格式
 * ethhdr源和目的的MAC地址
 * hwtype:硬件类型，1表示为以太网类型
 * protocol：协议类型表示为映射的地址的类型
 * hwlen：硬件地址长度
 * protolen：协议地址长度
 * opcode：操作码，1表示ARP请求，2表示ARP应答，3表示RARP请求，4表示RARP应答
 * shwaddr：发送端MAC地址
 * sipaddr：发送端IP地址
 * dhwaddr：接收端MAC地址
 * dipaddr：接收端IP地址
*/
struct arp_hdr {
  struct uip_eth_hdr ethhdr;
  u16_t hwtype;
  u16_t protocol;
  u8_t hwlen;
  u8_t protolen;
  u16_t opcode;
  struct uip_eth_addr shwaddr;
  uip_ipaddr_t sipaddr;
  struct uip_eth_addr dhwaddr;
  uip_ipaddr_t dipaddr;
};
/**以太网帧格式
 * ethhdr源和目的的MAC地址
 * vhl：协议版本号4bit和首部长度4bit
 * tos：服务类型8bit
 * len：数据包的总长度16bit，单位为字节长度
 * ipid：标识符16bit
 * ipoffset：偏移位置
 * ttl：生存时间
 * proto：协议
 * ipchksum：校验值
 * srcipaddr 源IP地址
 * destipaddr 目的IP地址
*/
struct ethip_hdr 
{
  struct uip_eth_hdr ethhdr;
  /* IP header. */
  u8_t vhl,
    tos,
    len[2],
    ipid[2],
    ipoffset[2],
    ttl,
    proto;
  u16_t ipchksum;
  uip_ipaddr_t srcipaddr, destipaddr;
};
#pragma pack()

#define ARP_REQUEST 1
#define ARP_REPLY   2

#define ARP_HWTYPE_ETH 1

#pragma pack(1)
/**定义ARP实例结构体
 * ipaddr：IP地址
 * ethaddr：MAC地址
 * time:
*/
struct arp_entry {
  uip_ipaddr_t ipaddr;
  struct uip_eth_addr ethaddr;
  u8_t time;
};
#pragma pack()
//定义物理层广播地址
static const struct uip_eth_addr CODE broadcast_ethaddr =
    {{0xff,0xff,0xff,0xff,0xff,0xff}};
static const u16_t CODE broadcast_ipaddr[2] = {0xffff,0xffff};
#ifdef CFG_ZEROCONF_MDNS_INCLUDED
static const struct uip_eth_addr CODE mdns_ethaddr =
    {{0x01,0x00,0x5e,0x00,0x00,0xfb}};
static const u16_t CODE mdns_ipaddr[2] = {0xe000,0x00fb};
#endif /* CFG_ZEROCONF_MDNS_INCLUDED */
/**ARP地址表*/
static struct arp_entry arp_table[UIP_ARPTAB_SIZE];
static uip_ipaddr_t ipaddr;
static u8_t i, c;

static u8_t arptime;
static u8_t tmpage;

#define BUF   ((struct arp_hdr *)&uip_buf[0])
#define IPBUF ((struct ethip_hdr *)&uip_buf[0])


#ifdef CFG_ZEROCONF_AUTOIP_INCLUDED
#define AUTOIP_STATE_DISABLED   0
#define AUTOIP_STATE_INIT       1
#define AUTOIP_STATE_PROBE      2
#define AUTOIP_STATE_ANNOUNCE   3
#define AUTOIP_STATE_CONFLICT   4
#define AUTOIP_STATE_FAILED     5
#define AUTOIP_STATE_COMPLETE   6



#define AUTOIP_PROBE_WAIT           1000000     /* 1 second */
#define AUTOIP_PROBE_NUM            3           /* number of probe packets */
#define AUTOIP_PROBE_MIN            1000000     /* min delay */
#define AUTOIP_PROBE_MAX            2000000     /* max delay */
#define AUTOIP_ANNOUNCE_WAIT        2000000     /* 2 seconds */
#define AUTOIP_ANNOUNCE_NUM         2           /* number of announce packets */
#define AUTOIP_ANNOUNCE_INTERVAL    2000000     /* time between announce packets */
#define AUTOIP_MAX_CONFLICTS        10
#define AUTOIP_RATE_LIMIT_INTERVAL  60000000    /* 60 seconds */
#define AUTOIP_DEFEND_INTERVAL      10000000    /* 10 seconds */

/**自动IP信息
 * state:
 * renew:
 * mac_addr:
 * probe_count
 * first_probe
 * last_probe
 * next_probe_interval
 * conflict_count
 * ipaddr
 * ip
 * netmask
 * gateway
*/
struct autoip_info {
  char      state;
  BOOL      renew;
  u8_t      mac_addr[6];

  u8_t      probe_count;
  tick_t    first_probe;
  tick_t    last_probe;
  tick_t    next_probe_interval;
  u8_t      announce_count;
  tick_t    last_announce;
  tick_t    next_announce_interval;
  u8_t      conflict_count;
  uip_ipaddr_t ipaddr;

  u8_t      ip[4];
  u8_t      netmask[4];
  u8_t      gateway[4];
};

STATIC struct autoip_info aip;

void uip_autoip_in(void);


#endif /* CFG_ZEROCONF_AUTOIP_INCLUDED */

/*-----------------------------------------------------------------------------------*/
/**
 * Initialize the ARP module.
 *
 */
/*-----------------------------------------------------------------------------------*/
/**ARP的初始化*/
void uip_arp_init(BOOL start)
{
  UNREFERENCED_PARAMETER(start);
  //初始化ARP表
  for(i = 0; i < UIP_ARPTAB_SIZE; ++i) 
  {
    sal_memset(&arp_table[i].ipaddr, 0, 4);
  }
#ifdef CFG_ZEROCONF_AUTOIP_INCLUDED
  uip_autoip_init();
#endif /* CFG_ZEROCONF_AUTOIP_INCLUDED */
}
#ifndef __BOOTLOADER__
/*-----------------------------------------------------------------------------------*/
/**
 * Periodic ARP processing function.
 *
 * This function performs periodic timer processing in the ARP module
 * and should be called at regular intervals. The recommended interval
 * is 10 seconds between the calls.
 *
 */
/*-----------------------------------------------------------------------------------*/
/**arp定时处理程序*/
void uip_arp_timer(void)
{
  struct arp_entry *tabptr;

  ++arptime;
  for(i = 0; i < UIP_ARPTAB_SIZE; ++i) 
  {
    tabptr = &arp_table[i];
    //对于IP地址全为零且时间值大于定义的最大的arp的时间值的处理，清空这个arp表s
    if(uip_ipaddr_cmp(&tabptr->ipaddr, &uip_all_zeroes_addr) &&arptime - tabptr->time >= UIP_ARP_MAXAGE) 
    {
      sal_memset(&tabptr->ipaddr, 0, 4);
    }
  }

}
#endif /* !__BOOTLOADER__ */

extern void uip_arp_update(uip_ipaddr_t *ipaddr, struct uip_eth_addr *ethaddr);
/*-----------------------------------------------------------------------------------*/
/**arp表更新
 * 对于IP地址已经存在的更新MAC地址和时间值
 * 对于IP地址不存在的如果当前ARP表有空闲进行添加对于ARP表没有空闲删除最老的那个
 * ipaddr：为ip地址
 * ethaddr：为以太网地址
*/
void uip_arp_update(uip_ipaddr_t *ipaddr, struct uip_eth_addr *ethaddr)
{
  register struct arp_entry *tabptr = arp_table;
  /* Walk through the ARP mapping table and try to find an entry to
     update. If none is found, the IP -> MAC address mapping is
     inserted in the ARP table. */
  for(i = 0; i < UIP_ARPTAB_SIZE; ++i) 
  {
    tabptr = &arp_table[i];

    /**对于串入的IP地址存在于IP地址表的处理
     * 更新ARP表
    */
    if(!uip_ipaddr_cmp(&tabptr->ipaddr, &uip_all_zeroes_addr)) 
    {
      if(uip_ipaddr_cmp(ipaddr, &tabptr->ipaddr)) 
      {
        sal_memcpy(tabptr->ethaddr.addr, ethaddr->addr, 6);
        tabptr->time = arptime;
        return;
      }
    }
  }
  /**找到第一个IP地址全为0的ARP表的表项*/
  for(i = 0; i < UIP_ARPTAB_SIZE; ++i) 
  {
    tabptr = &arp_table[i];
    if(uip_ipaddr_cmp(&tabptr->ipaddr, &uip_all_zeroes_addr)) 
    {
      break;
    }
  }
  /**对于已经使用的表项超出最大范围的处理
   * 找出注册时间最早的表项
  */
  if(i == UIP_ARPTAB_SIZE) 
  {
    tmpage = 0;
    c = 0;
    for(i = 0; i < UIP_ARPTAB_SIZE; ++i) 
    {
      tabptr = &arp_table[i];
      if(arptime - tabptr->time > tmpage) 
      {
        tmpage = arptime - tabptr->time;
        c = i;
      }
    }
    i = c;
    tabptr = &arp_table[i];
  }
  /**更新IP地址和MAC地址的对应和时间值*/
  uip_ipaddr_copy(&tabptr->ipaddr, ipaddr);
  sal_memcpy(tabptr->ethaddr.addr, ethaddr->addr, 6);
  tabptr->time = arptime;
}
/*-----------------------------------------------------------------------------------*/
#ifdef CFG_ARP_AUTO_REFRESH_INCLUDED
/**
 * ARP processing for incoming IP packets
 *
 * This function should be called by the device driver when an IP
 * packet has been received. The function will check if the address is
 * in the ARP cache, and if so the ARP cache entry will be
 * refreshed. If no ARP cache entry was found, a new one is created.
 *
 * This function expects an IP packet with a prepended Ethernet header
 * in the uip_buf[] buffer, and the length of the packet in the global
 * variable uip_len.
 */
/*-----------------------------------------------------------------------------------*/
/**对于ip包进入的处理
 * 从缓冲区中取出第一个数据包
*/
void uip_arp_ipin(void)
{
  /* Only insert/update an entry if the source IP address of the
     incoming IP packet comes from a host on the local network. */
  /**判读输入的IP地址和本设备是否同处于一个网段对于是一个网段的进行ARP表的更新*/
  if((IPBUF->srcipaddr.u16[0] & uip_netmask.u16[0]) !=(uip_hostaddr.u16[0] & uip_netmask.u16[0])) 
  {
    return;
  }
  if((IPBUF->srcipaddr.u16[1] & uip_netmask.u16[1]) !=(uip_hostaddr.u16[1] & uip_netmask.u16[1])) 
  {
    return;
  }
  uip_arp_update(&IPBUF->srcipaddr, &IPBUF->ethhdr.src);

  return;
}
#endif /* CFG_ARP_AUTO_REFRESH_INCLUDED */
/*-----------------------------------------------------------------------------------*/
/**
 * ARP processing for incoming ARP packets.
 *
 * This function should be called by the device driver when an ARP
 * packet has been received. The function will act differently
 * depending on the ARP packet type: if it is a reply for a request
 * that we previously sent out, the ARP cache will be filled in with
 * the values from the ARP reply. If the incoming ARP packet is an ARP
 * request for our IP address, an ARP reply packet is created and put
 * into the uip_buf[] buffer.
 *
 * When the function returns, the value of the global variable uip_len
 * indicates whether the device driver should send out a packet or
 * not. If uip_len is zero, no packet should be sent. If uip_len is
 * non-zero, it contains the length of the outbound packet that is
 * present in the uip_buf[] buffer.
 *
 * This function expects an ARP packet with a prepended Ethernet
 * header in the uip_buf[] buffer, and the length of the packet in the
 * global variable uip_len.
 */
/*-----------------------------------------------------------------------------------*/
/**此函数是针对ARP数据包的处理*/
void uip_arp_arpin(void)
{

  if(uip_len < sizeof(struct arp_hdr)) 
  {
    uip_len = 0;
    return;
  }
  uip_len = 0;

#ifdef CFG_ZEROCONF_AUTOIP_INCLUDED
    if (aip.state == AUTOIP_STATE_INIT || aip.state == AUTOIP_STATE_PROBE) 
    {
        uip_autoip_in();
        return;
    }
#endif /* CFG_ZEROCONF_AUTOIP_INCLUDED */
  /**对ARP数据包中的操作码进行处理*/
  switch(BUF->opcode) 
  {
    //ARP请求的处理
  case UIP_HTONS(ARP_REQUEST):
    /* ARP request. If it asked for our address, we send out a
       reply. */
      /**对于请求的目的ip地址是设备本身的IP地址的处理*/
    if(uip_ipaddr_cmp(&BUF->dipaddr, &uip_hostaddr)) 
    {
      /* First, we register the one who made the request in our ARP
     table, since it is likely that we will do more communication
     with this host in the future. */
      //更新请求包中的源ip地址和MAC地址到ARP表中
      uip_arp_update(&BUF->sipaddr, &BUF->shwaddr);

      BUF->opcode = UIP_HTONS(ARP_REPLY);

      sal_memcpy(BUF->dhwaddr.addr, BUF->shwaddr.addr, 6);
      sal_memcpy(BUF->shwaddr.addr, uip_ethaddr.addr, 6);
      sal_memcpy(BUF->ethhdr.src.addr, uip_ethaddr.addr, 6);
      sal_memcpy(BUF->ethhdr.dest.addr, BUF->dhwaddr.addr, 6);

      uip_ipaddr_copy(&BUF->dipaddr, &BUF->sipaddr);
      uip_ipaddr_copy(&BUF->sipaddr, &uip_hostaddr);

      BUF->ethhdr.type = UIP_HTONS(UIP_ETHTYPE_ARP);
      uip_len = sizeof(struct arp_hdr);
    }
    break;
  //ARP回复的处理，更新ARP表
  case UIP_HTONS(ARP_REPLY):
    /* ARP reply. We insert or update the ARP table if it was meant
       for us. */
    if(uip_ipaddr_cmp(&BUF->dipaddr, &uip_hostaddr)) 
    {
      uip_arp_update(&BUF->sipaddr, &BUF->shwaddr);
    }
    break;
  }

  return;
}
/*-----------------------------------------------------------------------------------*/
/**
 * Prepend Ethernet header to an outbound IP packet and see if we need
 * to send out an ARP request.
 *
 * This function should be called before sending out an IP packet. The
 * function checks the destination IP address of the IP packet to see
 * what Ethernet MAC address that should be used as a destination MAC
 * address on the Ethernet.
 *
 * If the destination IP address is in the local network (determined
 * by logical ANDing of netmask and our IP address), the function
 * checks the ARP cache to see if an entry for the destination IP
 * address is found. If so, an Ethernet header is prepended and the
 * function returns. If no ARP cache entry is found for the
 * destination IP address, the packet in the uip_buf[] is replaced by
 * an ARP request packet for the IP address. The IP packet is dropped
 * and it is assumed that they higher level protocols (e.g., TCP)
 * eventually will retransmit the dropped packet.
 *
 * If the destination IP address is not on the local network, the IP
 * address of the default router is used instead.
 *
 * When the function returns, a packet is present in the uip_buf[]
 * buffer, and the length of the packet is in the global variable
 * uip_len.
 */
/*-----------------------------------------------------------------------------------*/
/**arp输出的处理*/
void uip_arp_out(void)
{
  struct arp_entry *tabptr = arp_table;

  /* Find the destination IP address in the ARP table and construct
     the Ethernet header. If the destination IP addres isn't on the
     local network, we use the default router's IP address instead.

     If not ARP table entry is found, we overwrite the original IP
     packet with an ARP request for the IP address. */

  /* First check if destination is a local broadcast. */
  //对于目的地址是广播地址的处理，设置目的的以太网地址为广播地址
  if(uip_ipaddr_cmp(&IPBUF->destipaddr, &uip_broadcast_addr)) 
  {
    sal_memcpy(IPBUF->ethhdr.dest.addr, broadcast_ethaddr.addr, 6);
  } 
  //对于目的地址是224开始的处理，设置以太网的地址为0x01,0x00,0x5e和目的IP地址的后3个字节
  else if(IPBUF->destipaddr.u8[0] == 224) 
  {
    /* Multicast. */
    IPBUF->ethhdr.dest.addr[0] = 0x01;
    IPBUF->ethhdr.dest.addr[1] = 0x00;
    IPBUF->ethhdr.dest.addr[2] = 0x5e;
    IPBUF->ethhdr.dest.addr[3] = IPBUF->destipaddr.u8[1];
    IPBUF->ethhdr.dest.addr[4] = IPBUF->destipaddr.u8[2];
    IPBUF->ethhdr.dest.addr[5] = IPBUF->destipaddr.u8[3];
#ifdef CFG_ZEROCONF_MDNS_INCLUDED
  } 
  //对于支持MDNS的处理
  else if (uip_ipaddr_cmp(&IPBUF->destipaddr, (uip_ipaddr_t *)mdns_ipaddr)) 
  {
    sal_memcpy(IPBUF->ethhdr.dest.addr, mdns_ethaddr.addr, 6);
#endif /* CFG_ZEROCONF_MDNS_INCLUDED */
  } 
  /**对于正常的IP地址的处理*/
  else 
  {
    //对于目的地址和设备地址不在一个局域网的处理，设置ip地址为
    if(!uip_ipaddr_maskcmp(&IPBUF->destipaddr, &uip_hostaddr, &uip_netmask)) 
    {
      /* Destination address was not on the local network, so we need to
     use the default router's IP address instead of the destination
     address when determining the MAC address. */
      uip_ipaddr_copy(&ipaddr, &uip_draddr);
    } 
    //对于IP地址和设备的IP地址处于同一个网段的处理，设置ip地址为传入的目的ip地址
    else 
    {
      uip_ipaddr_copy(&ipaddr, &IPBUF->destipaddr);
    }
    //根据设备地址在ARP表中查找指定ip的物理地址
    for(i = 0; i < UIP_ARPTAB_SIZE; ++i) 
    {
      if(uip_ipaddr_cmp(&ipaddr, &tabptr->ipaddr)) 
      {
        break;
      }
      tabptr++;
    }
    //对于没有在ARP表中找到
    if(i == UIP_ARPTAB_SIZE) 
    {
      //设置目的以太网地址为fffffff
      sal_memset(BUF->ethhdr.dest.addr, 0xff, 6);
      sal_memset(BUF->dhwaddr.addr, 0x00, 6);
      sal_memcpy(BUF->ethhdr.src.addr, uip_ethaddr.addr, 6);
      sal_memcpy(BUF->shwaddr.addr, uip_ethaddr.addr, 6);

      uip_ipaddr_copy(&BUF->dipaddr, &ipaddr);
      uip_ipaddr_copy(&BUF->sipaddr, &uip_hostaddr);
      //设置操作码为ARP请求
      BUF->opcode = UIP_HTONS(ARP_REQUEST); /* ARP request. */
      //设置硬件类型为以太网类型
      BUF->hwtype = UIP_HTONS(ARP_HWTYPE_ETH);
      //设置映射的协议为以太网协议
      BUF->protocol = UIP_HTONS(UIP_ETHTYPE_IP);
      //设置硬件地址长度
      BUF->hwlen = 6;
      //设置协议地址长度
      BUF->protolen = 4;
      //设置数据头的协议类型为ARP协议
      BUF->ethhdr.type = UIP_HTONS(UIP_ETHTYPE_ARP);
      //设置数据为指向TCP应用数据
      uip_appdata = &uip_buf[UIP_TCPIP_HLEN + UIP_LLH_LEN];
      //设置发送数据的数据长度
      uip_len = sizeof(struct arp_hdr);
      return;
    }

    /* Build an ethernet header. */
    sal_memcpy(IPBUF->ethhdr.dest.addr, tabptr->ethaddr.addr, 6);
  }
  //设置需要发送数据的源物理地址
  sal_memcpy(IPBUF->ethhdr.src.addr, uip_ethaddr.addr, 6);
  //设置IP数据包的协议类型为以太网协议
  IPBUF->ethhdr.type = UIP_HTONS(UIP_ETHTYPE_IP);
  //设置发送数据的数据长度
  uip_len += sizeof(struct uip_eth_hdr);
}
/*-----------------------------------------------------------------------------------*/


#ifdef CFG_ZEROCONF_AUTOIP_INCLUDED

/**自动IP的初始化过程
 * 设置自动获取IP的状态值
 * 初始化IP地址,子网掩码，网关的值为0
*/
void uip_autoip_init(void)
{

    /* Reset state and IP address */
    aip.state = AUTOIP_STATE_DISABLED;
    sal_memset(&aip.ipaddr, 0x00, 4);
    sal_memset(&aip.netmask, 0x00, 4);
    sal_memset(&aip.gateway, 0x00, 4);
}
/**设置IP地址，即在获取IP地址失败的时候设置的IP地址*/
void uip_autoip_renew(void)
{
    u8_t    ip2 = 0;

    /* Select a new (random) IPv4 Link-Local address */
    /* The range is 169.254.1.0 ~ 169.254.254.255 */
    aip.ipaddr.u8[0] = 169;
    aip.ipaddr.u8[1] = 254;
    while (ip2 == 0) 
    {
        ip2 = sal_rand() % 255;
    }
    aip.ipaddr.u8[2] = ip2;
    aip.ipaddr.u8[3] = sal_rand() % 256;
}

/**开始自动获取IP地址*/
void uip_autoip_start(void)
{
    tick_t  interval;
    u8_t autoip[4];
    BOOL valid;
    /* check the last auto ip configuration */
    //判断自动IP地址是否被设置
    get_autoip_addr(&valid, autoip);
    //对于参数被设置且自动ip地址的前两位不是169和254设置自动ip地址为内存中的自动ip地址
    if (valid && ((autoip[0] == 169) && (autoip[1] == 254))) 
    {
        /* Check if the last configuration is Link-Local address */
        /* valid IPv4 link local address */
        uip_ipaddr_copy(&aip.ipaddr, (uip_ipaddr_t *) autoip);
    } 
    //使用MAC地址的后两位作为IP地址
    else 
    {
        /* Refer the MAC address as the initial IP address */
        aip.ipaddr.u8[0] = 169;
        aip.ipaddr.u8[1] = 254;
        aip.ipaddr.u8[2] = uip_ethaddr.addr[4];
        aip.ipaddr.u8[3] = uip_ethaddr.addr[5];
    }
    //设置自动IP地址的状态
    aip.state = AUTOIP_STATE_INIT;
    /* add random delay for first probe packet */
    //设置间隔时间
    interval = SAL_USEC_TO_TICKS(AUTOIP_PROBE_WAIT);
    aip.last_probe = sal_get_ticks();
    aip.next_probe_interval = (sal_rand() % interval);
    aip.probe_count = 0;
    aip.conflict_count = 0;
}


/* ARP packet receive handler while requesting an Link-Local Address */
/**自动IP地址的输入*/
void uip_autoip_in(void)
{
  switch(BUF->opcode) 
  {
      //对于请求时ARP请求的处理
    case UIP_HTONS(ARP_REQUEST):
        /* ARP request.
          * If the sender IP is our requested IP address,
          * or if the sender IP is zero address, target IP is our requested address
          *   and the sender hardware address is not ours,
          *   it is considered as a conflict event.
          */
        if(uip_ipaddr_cmp(&BUF->sipaddr, &aip.ipaddr)) 
        {
          aip.state = AUTOIP_STATE_CONFLICT;
        } 
        else if (uip_ipaddr_cmp(&BUF->sipaddr, &uip_all_zeroes_addr) && uip_ipaddr_cmp(&BUF->dipaddr, &aip.ipaddr)) 
        {
          if (sal_memcmp(BUF->shwaddr.addr, uip_ethaddr.addr, 6) == 0) 
          {
              aip.state = AUTOIP_STATE_CONFLICT;
          }
        }
    break;
    case UIP_HTONS(ARP_REPLY):
        /* ARP reply. If the sender IP is our requested address, it is a conflict event. */
        if(uip_ipaddr_cmp(&BUF->sipaddr, &aip.ipaddr)) 
        {
          aip.state = AUTOIP_STATE_CONFLICT;
        } 
        else 
        {
          uip_arp_update(&BUF->sipaddr, &BUF->shwaddr);
        }
    break;
  }

  return;
}


void uip_autoip_out(BOOL probe)
{
    /* Send Probe/Announce packets */
    sal_memset(BUF->ethhdr.dest.addr, 0xff, 6);
    sal_memset(BUF->dhwaddr.addr, 0x00, 6);
    sal_memcpy(BUF->ethhdr.src.addr, uip_ethaddr.addr, 6);
    sal_memcpy(BUF->shwaddr.addr, uip_ethaddr.addr, 6);

    uip_ipaddr_copy(&BUF->dipaddr, &aip.ipaddr);
    if (probe) 
    {
        /* Probe packet. Sender IP is zero */
        sal_memset(&BUF->sipaddr, 0x00, 4);
    } 
    else 
    {
        /* Announce packet. */
        uip_ipaddr_copy(&BUF->sipaddr, &aip.ipaddr);
    }
    BUF->opcode = UIP_HTONS(ARP_REQUEST); /* ARP request. */
    BUF->hwtype = UIP_HTONS(ARP_HWTYPE_ETH);
    BUF->protocol = UIP_HTONS(UIP_ETHTYPE_IP);
    BUF->hwlen = 6;
    BUF->protolen = 4;
    BUF->ethhdr.type = UIP_HTONS(UIP_ETHTYPE_ARP);

    uip_appdata = &uip_buf[UIP_TCPIP_HLEN + UIP_LLH_LEN];

    uip_len = sizeof(struct arp_hdr);
}


void uip_autoip_appcall(void)
{
    tick_t interval;
    if (aip.state == AUTOIP_STATE_DISABLED) {
        return;
    }
    uip_len = 0;

    switch (aip.state) 
    {
        case AUTOIP_STATE_INIT:
            if (SAL_TIME_EXPIRED(aip.last_probe, aip.next_probe_interval) > 0) {
                uip_autoip_out(TRUE);
                /* record the first probe time */
                aip.first_probe = sal_get_ticks();
                aip.last_probe = aip.first_probe;
                aip.probe_count++;
                aip.state = AUTOIP_STATE_PROBE;
                /* schedule next probe time */
                aip.next_probe_interval = (sal_rand() %
                    SAL_USEC_TO_TICKS(AUTOIP_PROBE_MAX - AUTOIP_PROBE_MIN)) +
                    SAL_USEC_TO_TICKS(AUTOIP_PROBE_MIN);
            }
            break;
        case AUTOIP_STATE_PROBE:
            if (aip.probe_count < AUTOIP_PROBE_NUM) {
                if (SAL_TIME_EXPIRED(aip.last_probe, aip.next_probe_interval)) {
                    uip_autoip_out(TRUE);
                    aip.last_probe = sal_get_ticks();
                    aip.probe_count++;
                    if (aip.probe_count >= AUTOIP_PROBE_NUM) {
                        /* schedule next announce time */
                        aip.next_announce_interval =
                            SAL_USEC_TO_TICKS(AUTOIP_ANNOUNCE_WAIT);
                        aip.announce_count = 0;
                    } else {
                        /* schedule next probe time */
                        aip.next_probe_interval = (sal_rand() %
                            SAL_USEC_TO_TICKS(AUTOIP_PROBE_MAX -
                                AUTOIP_PROBE_MIN)) +
                            SAL_USEC_TO_TICKS(AUTOIP_PROBE_MIN);
                    }
                }
            } else {
                if (SAL_TIME_EXPIRED(aip.last_probe,
                        aip.next_announce_interval)) {
                    uip_autoip_out(FALSE);
                    aip.last_announce = sal_get_ticks();
                    aip.next_announce_interval =
                        SAL_USEC_TO_TICKS(AUTOIP_ANNOUNCE_INTERVAL);
                    aip.announce_count++;
                    aip.state = AUTOIP_STATE_ANNOUNCE;
                }
            }
            break;
        case AUTOIP_STATE_ANNOUNCE:
            if (SAL_TIME_EXPIRED(aip.last_announce, aip.next_announce_interval)) {
                uip_autoip_out(FALSE);
                aip.announce_count++;
                aip.last_announce = sal_get_ticks();
                if (aip.announce_count >= AUTOIP_ANNOUNCE_NUM) {
                    aip.state = AUTOIP_STATE_COMPLETE;
                    aip.ip[0] = aip.ipaddr.u8[0];
                    aip.ip[1] = aip.ipaddr.u8[1];
                    aip.ip[2] = aip.ipaddr.u8[2];
                    aip.ip[3] = aip.ipaddr.u8[3];
                    aip.netmask[0] = 0xff;
                    aip.netmask[1] = 0xff;
                    aip.netmask[2] = 0;
                    aip.netmask[3] = 0;
                    aip.gateway[0] = 0;
                    aip.gateway[1] = 0;
                    aip.gateway[2] = 0;
                    aip.gateway[3] = 0;
                    net_dhcp_configured((const u8_t *)aip.ip,
                                (const u8_t *)aip.netmask,
                                (const u8_t *)aip.gateway);
                    /* Save the current configuration */
                    set_autoip_addr(TRUE, aip.ip);
#if defined(__BOOTLOADER__) && CFG_PERSISTENCE_SUPPORT_ENABLED
                    persistence_save_current_settings("autoip");
#endif /* __BOOTLOADER__ */
                }
            }
            break;
        case AUTOIP_STATE_CONFLICT:
            aip.conflict_count++;
            if (aip.conflict_count >= AUTOIP_MAX_CONFLICTS) {
                aip.state = AUTOIP_STATE_FAILED;
            } else {
                /* elect new ip address */
                uip_autoip_renew();
                aip.state = AUTOIP_STATE_INIT;
                aip.next_probe_interval = SAL_USEC_TO_TICKS(AUTOIP_PROBE_WAIT);
                aip.last_probe = sal_get_ticks();
                aip.probe_count = 0;
            }
            break;
        case AUTOIP_STATE_FAILED:
            interval = SAL_USEC_TO_TICKS(AUTOIP_RATE_LIMIT_INTERVAL);
            if (SAL_TIME_EXPIRED(aip.first_probe, interval)) {
                /* select a new ip address */
                uip_autoip_renew();
                aip.state = AUTOIP_STATE_INIT;
                /* add random delay for first probe packet */
                interval = SAL_USEC_TO_TICKS(AUTOIP_PROBE_WAIT);
                aip.next_probe_interval = (sal_rand() % interval);
                aip.probe_count = 0;
                aip.conflict_count = 0;
            }
            break;
        case AUTOIP_STATE_COMPLETE:
            break;
        default:
            break;
    }
}

#endif /* CFG_ZEROCONF_AUTOIP_INCLUDED */

/** @} */
/** @} */
