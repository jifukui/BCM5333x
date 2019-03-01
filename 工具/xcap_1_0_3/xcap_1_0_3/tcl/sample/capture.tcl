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
    set m [expr ($n-($offset*2))/2]
    for {set i 0} {$i<$m} {incr i} {
        if {[expr $i%16] == 0} {
            if {$i != 0} {
                puts ""
            }
            puts -nonewline [format "%04x: " $i]
        }
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

set ifindex 3

set k [xcap init]
puts "init xcap, result $k"
set k [xcap startif $ifindex]
puts "startif $ifindex, result $k"

set k [xcap setfilter $ifindex "ip"]
puts "setfilter $ifindex, result $k"

set k [xcap setlocalmac $ifindex "000000000011"]
puts "setlocalmac $ifindex, result $k"

puts "receiving igmp packet"
for {set i 0} {$i<101} {incr i} {
    after 1000
    set pkt [xcap recvpkt $ifindex]
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

    set proto [string range $pkt 46 47]
    puts "proto = $proto, ok"

    print_packet $pkt
}

for {set i 0} {$i<1} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}

set k [xcap free]
puts "free result $k"

for {set i 0} {$i<1} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}
