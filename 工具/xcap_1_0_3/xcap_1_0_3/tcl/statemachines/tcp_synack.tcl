
load tclcmd.dll

set ifindex 4
#if { $argc > 0 } {
#    set ifindex [lindex $argv 0]
#}
set mode client
#if { $argc > 1 } {
#    set mode [lindex $argv 1]
#}
#if {[string equal -nocase $mode "local"]} {
#    xcap setmode local
#    set k [xcap init]
#    puts "init xcap, result $k"
#    set k [xcap startif $ifindex]
#    puts "startif $ifindex, result $k"
#}

#set m [xcap getdata 1 4 2 4 4 hex]
#set m [xcap setdata 1 4 2 4 4 "aabbccdd" hex]


xcap clearpkt $ifindex
set window 30000

set srcaddr "c0a8c802"
set dstaddr "c0a8c821"
#set srcaddr "c0a80005"
#set dstaddr "c0a80021"

for {set i 0} {$i<1000000} {incr i} {
    set k [xcap recvpkt $ifindex]
    #puts $k

    if {[string equal -nocase $k "error"]} {
        puts "no packet"
        after 1000
        continue
    }
    if {[string equal -nocase $k ""]} {
        puts "no packet"
        after 1000
        continue
    }

    set ethtype [string range $k 24 29]
    if {![string equal -nocase $ethtype "080045"]} {
        puts "$ethtype not IP"
        continue
    }
    set pro [string range $k 46 47]
    if {![string equal -nocase $pro "06"]} {
        puts "protocol($pro) is not TCP"
    }
    set srcip [string range $k 52 59]
    if {![string equal -nocase $srcip $srcaddr]} {
        puts "src($srcip) is not $srcaddr"
        continue
    }
    set dstip [string range $k 60 67]
    if {![string equal -nocase $dstip $dstaddr]} {
        puts "dst($dstip) is not $dstaddr"
        continue
    }
    set fin 0
    set dlen 1
    set flags [string range $k 94 95]
    if {![string equal -nocase $flags "02"]} {
        puts "flags($flags) is not 02"
        if {![string equal -nocase $flags "10"]} {
            puts "flags($flags) is not 10"
            puts "flags($flags) is not 18"
            if {![string equal -nocase $flags "18"]} {
                continue
            }
        } else {
            set dlen 0
            set fin 1
        }
    }
    set seq [string range $k 76 83]
    set ack [string range $k 84 91]
    puts "seq = $seq"
    puts "ack = $ack"
    puts " ----> [expr 0x$seq+1]"
    puts " ----> [expr 0x$ack+0]"
    set seq2 [expr 0x$seq+0]
    set seq [expr 0x$seq+1]
    set ack [expr 0x$ack+0]
    puts " ----> $seq"
    puts " ----> $ack"
    set rst [xcap setdata 13 15 2 8 4 $seq int]
    set rst [xcap setdata 13 15 2 4 4 $ack int]
    set rst [xcap setdata 13 16 2 8 4 $seq int]
    set rst [xcap setdata 13 16 2 4 4 $ack int]
    set rst [xcap setdata 13 17 2 8 4 $seq2 int]
    set rst [xcap setdata 13 17 2 4 4 $ack int]
    set rst [xcap setdata 13 18 2 8 4 $seq2 int]
    set rst [xcap setdata 13 18 2 4 4 $ack int]
    puts "setdata = $rst"

    continue

    #puts "unknown packet"
}

#if {[string equal -nocase $mode "local"]} {
#    xcap free
#}

for {set i 0} {$i<10} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}

