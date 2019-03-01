proc print_data {packet offset len desc} {
    set n [string length $packet]
    set m [expr $n/2]
    set nextoff [expr $offset+$len]
    if {$m < $nextoff} {
        return $packet
    }
    puts -nonewline "00: "
    for {set i 0} {$i<$len} {incr i} {
        set a [expr ($offset+$i)*2]
        set b [expr $a+1]
        puts -nonewline [string range $packet $a $b]
        puts -nonewline " "
    }
    for {set i $len} {$i<6} {incr i} {
        puts -nonewline "   "
    }
    puts "     $desc"
    return $nextoff
}

proc print_packet_eth {packet offset desc} {
    puts " ===> $desc"
    set offset [print_data $packet $offset 6 "Destination mac"]
    set offset [print_data $packet $offset 6 "Source mac"]
    set offset [print_data $packet $offset 2 "Ethernet type"]
    return $offset
}

proc print_packet_ip {packet offset desc} {
    puts " ===> $desc"
    set offset [print_data $packet $offset 1 "version, header length"]
    set offset [print_data $packet $offset 1 "Tos/DSCP"]
    set offset [print_data $packet $offset 2 "Total length"]
    set offset [print_data $packet $offset 2 "Identification"]
    set offset [print_data $packet $offset 2 "Flags & fragment"]
    set offset [print_data $packet $offset 1 "Ttl"]
    set offset [print_data $packet $offset 1 "Protocol"]
    set offset [print_data $packet $offset 2 "Checksum"]
    set offset [print_data $packet $offset 4 "Source ip"]
    set offset [print_data $packet $offset 4 "Destination ip"]
    return $offset
}

proc print_remain_data {packet offset} {
    puts " ===> Data"
    set n [string length $packet]
    set m [expr $n-$offset]
    for {set i 0} {$i<$m} {incr i} {
        set a [expr ($offset+$i)*2]
        set b [expr $a+1]
        puts -nonewline [string range $packet $a $b]
        puts -nonewline " "
    }
    puts ""
}

proc print_packet {packet} {
    set offset 0
    set offset [print_packet_eth $packet $offset "Ethernet header"]
    set offset [print_packet_ip $packet $offset "IP header"]
    print_remain_data $packet $offset
}

load tclcmd.dll
xcap setmode local

set k [xcap list]
puts "$k"

set k [xcap init]
puts "init xcap, result $k"
set k [xcap startif 2]
puts "startif 2, result $k"

set k [xcap setfilter 2 "ip"]
puts "setfilter 2, result $k"

set k [xcap setlocalmac 2 "001c23431e85"]
puts "setlocalmac 2, result $k"

puts "sending icmp request"
xcap sendpkt 2 0015F23D50D6001C23431E85080045000040000100004001F6F1C0A80179C0A8010108005F5D00010001313233343536373839306162636465666768696A6B6C6D6E6F707172737475767778797A
after 1000

puts "receiving icmp reponse"
for {set i 0} {$i<10} {incr i} {
    after 1000
    set k [xcap recvpkt 2]
    puts $k
    print_packet $k

    set ethtype [string range $k 24 29]
    if {![string equal -nocase $ethtype "080045"]} {
        puts "wrong ethtype $ethtype"
        continue;
    }
    puts "ethtype = $ethtype, ok"

    set srcip [string range $k 52 59]
    if {![string equal -nocase $srcip "c0a80101"]} {
        puts "wrong srcip $srcip"
        continue;
    }
    puts "srcip = $srcip, ok"

    set dstip [string range $k 60 67]
    if {![string equal -nocase $dstip "c0a80179"]} {
        puts "wrong dstip $dstip"
        continue;
    }
    puts "dstip = $dstip, ok"

    set proto [string range $k 46 47]
    if {![string equal -nocase $proto "01"]} {
        puts "wrong icmpop $proto"
        continue;
    }
    puts "proto = $proto, ok"

    set icmpop [string range $k 68 69]
    if {![string equal -nocase $icmpop "00"]} {
        puts "wrong icmpop $icmpop"
        continue;
    }
    puts "icmpop = $icmpop, ok"

    break;
}

set k [xcap free]
puts "free result $k"

for {set i 0} {$i<1} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}
