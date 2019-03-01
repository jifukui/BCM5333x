
load tclcmd.dll

for {set i 0} {$i<$argc} {incr i} {
    puts "[lindex $argv $i]"
}


xcap startif 4

set k [xcap help]

puts $k



for {set i 0} {$i<5} {incr i} {
    puts "send packet"
    xcap sendpkt 4 5 1 $i
    after 1000
}

xcap stopif 4


for {set i 0} {$i<5} {incr i} {
    puts "this window will be closed in [expr 5-$i] seconds"
    after 1000
}
