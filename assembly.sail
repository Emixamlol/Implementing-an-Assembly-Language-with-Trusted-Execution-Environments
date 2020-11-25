default Order dec

$include <prelude.sail>
$include "instructions.sail"

type regbits = bits(5)

scattered union ast /* begin scattered ast definition */
val decode : bits(32) -> option(ast) effect pure /* decode function */

/* R-TYPE instruction */
union clause ast = RTYPE : (regbits, regbits, regbits, rop)

function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ 0b000 @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, ADD))

function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ 0b111 @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, AND))

function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ 0b110 @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, OR))

function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ 0b100 @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, XOR))

function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ 0b000 @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, MUL))

function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ 0b100 @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, DIV))

function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ 0b110 @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, REM))

/* I-TYPE instruction */
union clause ast = ITYPE : (bits(12), regbits, regbits, iop)

/* S-TYPE instruction */
union clause ast = STYPE : (bits(7), regbits, regbits, bits(5), sop)

/* B-TYPE instruction */
union clause ast = BTYPE : (bits(1), bits(6), regbits, regbits, bits(4), bits(1), bop)

/* U-TYPE instruction */
union clause ast = UTYPE : (bits(20), regbits, uop)

/* J-TYPE instruction */
union clause ast = JTYPE : (bits(1), bits(10), bits(1), bits(9), regbits, jop)


end ast /* end scattered ast definition */