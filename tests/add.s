    .text               # put this into the text section
    .align  2           # align to a multiple of 4
    .globl  _start

_start:
    lb x0, 0(x0) # begin enclave
    lui a0, 1 # a0 = 1
    lui a1, 1 # a1 = 1
    add a3, a0, a1; # a3 = a0 + a1
    lh x0, 0(x0) # end enclave
    ebreak
    