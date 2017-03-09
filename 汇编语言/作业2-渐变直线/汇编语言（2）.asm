move.b #255, A1
move.b #51,A0
move.b A1, (A2)
inc A2
sub #5,A1
dec A0
ble 16397
jmp 16388

move.b #51,A0
move.b A1, (A2)
inc A2
add #5,A1
dec A0
ble 16408
jmp 16399

jmp 16384
