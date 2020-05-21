/*
 * $Id: sal_console.c,v 1.10 Broadcom SDK $
 *
 * $Copyright: Copyright 2016 Broadcom Corporation.
 * This program is the proprietary software of Broadcom Corporation
 * and/or its licensors, and may only be used, duplicated, modified
 * or distributed pursuant to the terms and conditions of a separate,
 * written license agreement executed between you and Broadcom
 * (an "Authorized License").  Except as set forth in an Authorized
 * License, Broadcom grants no license (express or implied), right
 * to use, or waiver of any kind with respect to the Software, and
 * Broadcom expressly reserves all rights in and to the Software
 * and all intellectual property rights therein.  IF YOU HAVE
 * NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE
 * IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE
 * ALL USE OF THE SOFTWARE.  
 *  
 * Except as expressly set forth in the Authorized License,
 *  
 * 1.     This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof,
 * and to use this information only in connection with your use of
 * Broadcom integrated circuit products.
 *  
 * 2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS
 * PROVIDED "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY,
 * OR OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 * 
 * 3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL,
 * INCIDENTAL, SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER
 * ARISING OUT OF OR IN ANY WAY RELATING TO YOUR USE OF OR INABILITY
 * TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS OF
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR USD 1.00,
 * WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING
 * ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.$
 *
 */

#include <stdarg.h>

#include "system.h"
#include "bsp_config.h"
#include "ns16550.h"
/**串口寄存器读取8位数据*/
#define UART_READREG(r)    SYS_REG_READ8((CFG_UART_BASE+(r)))
/**串口寄存器写8位数据*/
#define UART_WRITEREG(r,v) SYS_REG_WRITE8((CFG_UART_BASE+(r)), v)

#if CFG_CONSOLE_ENABLED
STATIC char lastchar;
#endif /* CFG_CONSOLE_ENABLED */

extern void sal_console_init(void);
extern void sal_debugf(const char *fmt, ...);

#if CFG_CONSOLE_ENABLED

/*  *********************************************************************
    *  C library platform denpent uart driver 
    *
    *  put_char and get_char 
    *
    ********************************************************************* */
/**串口输出字符*/
char put_char(char c) 
{

   while ((UART_READREG(R_UART_LSR) & LSR_TXRDY) == 0) 
   {
         ;
   };
   UART_WRITEREG(R_UART_DATA, c);

   return c;   
}
/**串口得到数据*/
char get_char(void){

  char c;

  do 
  {
     POLL();
  } while (!(UART_READREG(R_UART_LSR) & LSR_RXRDY));

  c = (char)(UART_READREG(R_UART_DATA) & 0xFF);

  return c;
}

/*  *********************************************************************
    *  um_console_write()
    *
    *  Console output function
    *
    ********************************************************************* */
/**串口写数据*/
static int um_console_write(const char *buffer,int length)
{
    int blen = length;
    const char *bptr = buffer;
    while (blen > 0) 
    {            
        put_char(*bptr);
        bptr++;
        blen--;
    }
    return 0;
}



/*  *********************************************************************
    *  um_console_print()
    *
    *  Console output function
    *
    ********************************************************************* */
/**串口读取输出数据*/
int um_console_print(const char *str)
{
    int count = 0;
    int len;
    char *p;

    /* Convert CR to CRLF as we write things out */
    while ((p = sal_strchr(str,'\n'))) {
        um_console_write(str,p-str);
        um_console_write("\r\n",2);
        count += (p-str);
        str = p + 1;
    }

    len = sal_strlen(str);
    um_console_write(str, len);
    count += len;

    return count;
}
/**串口的初始化*/
void sal_console_init(void)
{

}

#endif /* CFG_CONSOLE_ENABLED */
/**串口输出数据用户接口函数*/
void sal_printf(const char *fmt, ...)
{
#ifndef JIFUKUI_DEBUG
	return;
#else
#if CFG_CONSOLE_ENABLED
    va_list arg_ptr;
    char buf[256];

    va_start(arg_ptr, fmt);
    vsprintf(buf, fmt, arg_ptr);
    va_end(arg_ptr);

    um_console_print(buf);
#else
    UNREFERENCED_PARAMETER(fmt);
#endif
#endif
}


int cdk_printf(const char *fmt, ...)
{
#if CFG_CONSOLE_ENABLED
    va_list arg_ptr;
    char buf[256];

    va_start(arg_ptr, fmt);
    vsprintf(buf, fmt, arg_ptr);
    va_end(arg_ptr);

    um_console_print(buf);
#else
    UNREFERENCED_PARAMETER(fmt);
#endif
    return SYS_OK;
}

void sal_debugf(const char *fmt, ...)
{
#if CFG_CONSOLE_ENABLED
    va_list arg_ptr;
    char buf[256];

    va_start(arg_ptr, fmt);
    vsprintf(buf, fmt, arg_ptr);
    va_end(arg_ptr);

    um_console_print(buf);
#endif /* CFG_CONSOLE_ENABLED */
}
void sal_assert(const char *expr, const char *file, uint16 line) REENTRANT
{
#if CFG_CONSOLE_ENABLED
    sal_printf("ERROR: Assertion failed: (%s) at %s:%u\n", expr, file, line);
#endif /* CFG_CONSOLE_ENABLED */
    for(;;);
}
/***/
BOOL sal_char_avail(void)
{
#if CFG_CONSOLE_ENABLED
    /**如果定义串口使能根据串口的线状态寄存器的状态是否准备好返回此参数*/
    return (UART_READREG(R_UART_LSR) & LSR_RXRDY) ? 1 : 0;
#else
    return FALSE;
#endif
}
/***/
char sal_getchar(void)
{
#if CFG_CONSOLE_ENABLED

    lastchar = get_char();
    switch (lastchar) {
        case 0x7f:
        case '\b':
            break;
        case '\r':
        case '\n':
            um_console_write("\r\n",2);
            break;
        default:
            if (lastchar >= ' ') 
            {
                um_console_write(&lastchar,1);
            }
            break;
    }

    return lastchar;
#else
    for(;;) 
    {
        POLL();
    }
    return 0;
#endif
}

/**获取串口得到的最后一个数据*/
char sal_get_last_char(void)
{
#if CFG_CONSOLE_ENABLED
    return lastchar;
#else
    return 0;
#endif
}
/**输出字符
 * c：为需要输出的字符
*/
char sal_putchar(char c)
{
#if CFG_CONSOLE_ENABLED
    switch (c) {
        case '\b':
            um_console_write("\b \b",3);
        break;
        case '\r':
        case '\n':
            um_console_write("\r\n",2);
        break;
        default:
            um_console_write(&c,1);
        break;
    }
#endif
    return c;
}

