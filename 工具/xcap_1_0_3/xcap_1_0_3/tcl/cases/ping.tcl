
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

puts "sending icmp request"
xcap sendpkt $ifindex 0015F23D50D6001C23431E85080045000040000100004001F6F1C0A80179C0A8010108005F5D00010001313233343536373839306162636465666768696A6B6C6D6E6F707172737475767778797A
after 1000

puts "receiving icmp reponse"
for {set i 0} {$i<10} {incr i} {
    after 1000
    set k [xcap recvpkt $ifindex]
    puts $k

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
        puts "wrong proto $proto"
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

if {[string equal -nocase $mode "local"]} {
    xcap free
}

for {set i 0} {$i<10} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}
