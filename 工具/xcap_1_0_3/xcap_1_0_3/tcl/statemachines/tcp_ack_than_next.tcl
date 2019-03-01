
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
xcap setdata 13 9  2 14 2 $window int
xcap setdata 13 10 2 14 2 $window int
xcap setdata 13 11 2 14 2 $window int
#xcap setdata 13 11 2 18 2 100 int

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
    if {![string equal -nocase $srcip "c0a8c801"]} {
        puts "src($srcip) is not c0a8c801"
        continue
    }
    set dstip [string range $k 60 67]
    if {![string equal -nocase $dstip "c0a8c8fe"]} {
        puts "dst($dstip) is not c0a8c8fe"
        continue
    }
    set flags [string range $k 94 95]
    if {![string equal -nocase $flags "10"]} {
        if {![string equal -nocase $flags "18"]} {
            puts "flags($flags) is not 10 or 18"
            continue
        }
    }
    set s_port [string range $k 68 71]
    set d_port [string range $k 72 75]
    set s_port [expr 0x$s_port+0]
    set d_port [expr 0x$d_port+0]
    set seq [string range $k 76 83]
    puts "seq = $seq"
    puts " ----> [expr 0x$seq+0]"
    set seq [expr 0x$seq+0]
    puts " ----> $seq"
    set ack [string range $k 84 91]
    puts "ack = $ack"
    puts " ----> [expr 0x$ack+0]"
    set ack [expr 0x$ack+0]
    puts " ----> $ack"
    set rst [xcap setdata 26 8 2 0 2 $d_port int]
    set rst [xcap setdata 26 8 2 2 2 $s_port int]
    set rst [xcap setdata 26 8 2 4 4 $ack int]
    set rst [xcap setdata 26 8 2 8 4 $seq int]
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

