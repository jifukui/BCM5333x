
load tclcmd.dll

set ifindex 2
if { $argc > 0 } {
    set ifindex [lindex $argv 0]
}
set mode local
if { $argc > 1 } {
    set mode [lindex $argv 1]
}
if {[string equal -nocase $mode "local"]} {
    xcap setmode local
    set k [xcap init]
    puts "init xcap, result $k"
    set k [xcap startif $ifindex]
    puts "startif $ifindex, result $k"
}

set brasmac "FFFFFFFFFFFF"
set mymac "000000000011"
set padi "8863110900000000"
set padr "8863111900000000"

proc genpkt { pkt } {
    global brasmac
    global mymac
    return $brasmac$mymac$pkt
}

puts "sending pppoe PADI"
xcap sendpkt $ifindex [genpkt $padi]

for {set i 0} {$i<10} {incr i} {
    after 1000
    set k [xcap recvpkt $ifindex]
    #puts $k

    set ethtype [string range $k 24 31]
    if {[string equal -nocase $ethtype "88631107"]} {
        puts "received pppoe PADO"
        set brasmac [string range $k 12 23]
        puts "sending pppoe PADR"
        xcap sendpkt $ifindex [genpkt $padr]
        continue;
    }

    if {[string equal -nocase $ethtype "88631165"]} {
        set sid [string range $k 32 35]
        puts "received pppoe PADS, session-id=$sid"
        #continue;
        break;
    }

    #puts "unknown packet"
}

if {[string equal -nocase $mode "local"]} {
    xcap free
}

for {set i 0} {$i<10} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}

