
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

set servermac "FFFFFFFFFFFF"
set mymac "000000000011"
set discover "080045000110000100004011E587C0A8090AC0A809FA0044004300FC529901010600DF20C27800008000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000063825363350101FF"
set request ""

proc genpkt { pkt } {
    global servermac
    global mymac
    return $servermac$mymac$pkt
}

puts "sending dhcp discover"
xcap sendpkt $ifindex [genpkt $discover]

for {set i 0} {$i<10} {incr i} {
    after 1000
    set k [xcap recvpkt $ifindex]
    #puts $k

    set ethtype [string range $k 24 29]
    if {![string equal -nocase $ethtype "080045"]} {
        #puts "unknown packet"
        continue;
    }

    set cmd [string range $k 84 85]
    if {![string equal -nocase $cmd "02"]} {
        #puts "unknown packet"
        continue;
    }

    set cmd2 [string range $k 564 569]
    if {[string equal -nocase $cmd2 "530102"]} {
        puts "received dhcp offer"
        set brasmac [string range $k 12 23]
        puts "sending dhcp request"
        xcap sendpkt $ifindex [genpkt $request]
        continue;
    }

    set cmd2 [string range $k 564 569]
    if {[string equal -nocase $cmd2 "530105"]} {
        puts "received dhcp ack"
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

