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

proc print_packet_igmp {packet offset desc} {
    puts " ===> $desc"
    set offset [print_data $packet $offset 1 "Type"]
    set offset [print_data $packet $offset 1 "Code"]
    set offset [print_data $packet $offset 2 "Checksum"]
    set offset [print_data $packet $offset 4 "Address"]
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
    set offset [print_packet_igmp $packet $offset "IGMP header"]
    print_remain_data $packet $offset
}

load tclcmd.dll
xcap setmode client
#xcap setlocalmac 3 "000000000022"

puts "receiving igmp packet"
for {set i 0} {$i<101} {incr i} {
    after 1000
    set pkt [xcap recvpkt 3]
    #puts $pkt

    set n [string length $pkt]
    if {$n < 42} {
        puts "wrong packet $pkt"
        continue;
    }

    set ethtype [string range $pkt 24 29]
    if {![string equal -nocase $ethtype "080045"]} {
        puts "wrong ethtype $ethtype"
        continue;
    }
    puts "ethtype = $ethtype, ok"

    set dstip [string range $pkt 60 67]
    if {![string equal -nocase $dstip "EA050607"]} {
        puts "wrong dstip $dstip"
        continue;
    }
    puts "dstip = $dstip, ok"

    set proto [string range $pkt 46 47]
    if {![string equal -nocase $proto "02"]} {
        puts "not igmp $proto"
        continue;
    }
    puts "proto = $proto, ok"

    set igmptype [string range $pkt 68 69]
    puts "igmptype = $igmptype, ok"

    print_packet $pkt

    if {[string equal -nocase $igmptype "11"]} {
        puts "Query group address : $dstip"
    }
    if {[string equal -nocase $igmptype "12"]} {
        puts "Report v1"
    }
    if {[string equal -nocase $igmptype "16"]} {
        puts "Report v2"
    }
    if {[string equal -nocase $igmptype "22"]} {
        puts "Report v3"
    }
}

for {set i 0} {$i<1} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}