default Order dec

$include <prelude.sail>
$include "instructions.sail"

type regbits = bits(5)

scattered union ast /* begin scattered ast definition */
val decode : bits(32) -> option(ast) effect pure /* decode function */

/* R-TYPE instructions */
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

/* I-TYPE instructions */
union clause ast = ITYPE : (bits(12), regbits, regbits, iop)

function clause decode imm : bits(12) @ rs1 : regbits @ 0b000 @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ADDI))

function clause decode imm : bits(12) @ rs1 : regbits @ 0b010 @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, SLTI))

function clause decode imm : bits(12) @ rs1 : regbits @ 0b111 @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ANDI))

function clause decode imm : bits(12) @ rs1 : regbits @ 0b110 @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ORI))

function clause decode imm : bits(12) @ rs1 : regbits @ 0b100 @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, XORI))

function clause decode imm : bits(12) @ rs1 : regbits @ 0b000 @ rd : regbits @ 0b1100111
    = Some(ITYPE(imm, rs1, rd, JALR))

function clause decode imm : bits(12) @ rs1 : regbits @ 0b010 @ rd : regbits @ 0b0000011
    = Some(ITYPE(imm, rs1, rd, LW))

/* S-TYPE instructions */
union clause ast = STYPE : (bits(7), regbits, regbits, bits(5), sop)

function clause decode imm2 : bits(7) @ rs2 : regbits @ rs1 : regbits @ 0b010 @ imm1 : bits(5) @ 0b0100011
    = Some(STYPE(imm2, rs2, rs1, imm1, SW))

/* B-TYPE instructions */
union clause ast = BTYPE : (bits(1), bits(6), regbits, regbits, bits(4), bits(1), bop)

function clause decode imm4 : bits(1) @ imm2 : bits(6) @ rs2 : regbits @ rs1 : regbits @ 0b000 @ imm1 : bits(4) @ imm3 : bits(1) @ 0b1100011
    = Some(BTYPE(imm4, imm2, rs2, rs1, imm1, imm3, BEQ))

function clause decode imm4 : bits(1) @ imm2 : bits(6) @ rs2 : regbits @ rs1 : regbits @ 0b001 @ imm1 : bits(4) @ imm3 : bits(1) @ 0b1100011
    = Some(BTYPE(imm4, imm2, rs2, rs1, imm1, imm3, BNE))

/* U-TYPE instructions */
union clause ast = UTYPE : (bits(20), regbits, uop)

function clause decode imm : bits(20) @ rd : regbits @ 0b0110111
    = Some(UTYPE(imm, rd, LUI))

function clause decode imm : bits(20) @ rd : regbits @ 0b0010111
    = Some(UTYPE(imm, rd, AUIPC))

/* J-TYPE instructions */
union clause ast = JTYPE : (bits(1), bits(10), bits(1), bits(8), regbits, jop)

function clause decode imm4 : bits(1) @ imm1 : bits(10) @ imm2 : bits(1) @ imm3 : bits(8) @ rd : regbits @ 0b1101111
    = Some(JTYPE(imm4, imm1, imm2, imm3, rd, JAL))


end ast /* end scattered ast definition */