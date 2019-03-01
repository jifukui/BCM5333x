
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

puts "sending rip request"
xcap sendpkt $ifindex 01005E000009001C23431E85080045000034000100004011D88DC0A80179E00000090208020800205861010200000000000000000000000000000000000000000010
after 1000

puts "receiving rip reponse"
for {set i 0} {$i<10} {incr i} {
    after 1000
    set k [xcap recvpkt $ifindex]
    puts "-->$k"

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
        if {![string equal -nocase $dstip "e0000009"]} {
            puts "wrong dstip $dstip"
            continue;
        }
    }
    puts "dstip = $dstip, ok"

    set proto [string range $k 46 47]
    if {![string equal -nocase $proto "11"]} {
        puts "wrong proto $proto"
        continue;
    }
    puts "proto = $proto, ok"

    set port [string range $k 68 75]
    if {![string equal -nocase $port "02080208"]} {
        puts "wrong port $port"
        continue;
    }
    puts "port = $port, ok"

    set vercmd [string range $k 84 87]
    if {![string equal -nocase $vercmd "0202"]} {
        puts "wrong vercmd $vercmd"
        continue;
    }
    puts "vercmd = $vercmd, ok"

    break;
}

if {[string equal -nocase $mode "local"]} {
    xcap free
}

for {set i 0} {$i<5} {incr i} {
    puts "this window will be closed in [expr 10-$i] seconds"
    after 1000
}
