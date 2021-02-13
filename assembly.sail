default Order dec

$include <prelude.sail>
$include "instructions.sail"

val print_str = {c: "print_endline"} : string -> unit
val print_int = {c: "print_int"} : int -> unit
val print_bits = {c: "print_bits"} : forall ('n : Int) . bits('n) -> unit

overload print = {print_str, print_int, print_bits}

/* types */
type xlen : Int = 32
type xlenbits : Type = bits(xlen)
type regbits = bits(5)

scattered union ast /* begin scattered ast definition */
val decode : xlenbits -> option(ast) effect pure /* decode function */
val execute : ast -> unit effect {rmem, rreg, wreg} /* execute function */

/* R-TYPE instructions */
union clause ast = RTYPE : (regbits, regbits, regbits, rop)

/* ADD */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(ADD) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, ADD))

function clause execute (RTYPE (rs2, rs1, rd, ADD)) = {
    print("execute ADD\n")
}

/* AND */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(AND) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, AND))

function clause execute (RTYPE (rs2, rs1, rd, AND)) = {
    print("execute AND\n")
}

/* OR */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(OR) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, OR))

function clause execute (RTYPE (rs2, rs1, rd, OR)) = {
    print("execute OR\n")
}

/* XOR */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(XOR) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, XOR))

function clause execute (RTYPE (rs2, rs1, rd, XOR)) = {
    print("execute XOR\n")
}

/* MUL */
function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(MUL) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, MUL))

function clause execute (RTYPE (rs2, rs1, rd, MUL)) = {
    print("execute MUL\n")
}

/* DIV */
function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(DIV) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, DIV))

function clause execute (RTYPE (rs2, rs1, rd, DIV)) = {
    print("execute DIV\n")
}

/* REM */
function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(REM) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, REM))

function clause execute (RTYPE (rs2, rs1, rd, REM)) = {
    print("execute REM\n")
}

/* I-TYPE instructions */
union clause ast = ITYPE : (bits(12), regbits, regbits, iop)

/* ADDI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(ADDI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ADDI))

function clause execute (ITYPE (imm, rs1, rd, ADDI)) = {
    print("execute ADDI\n")
}

/* SLTI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(SLTI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, SLTI))

function clause execute (ITYPE (imm, rs1, rd, SLTI)) = {
    print("execute SLTI\n")
}

/* ANDI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(ANDI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ANDI))

function clause execute (ITYPE (imm, rs1, rd, ANDI)) = {
    print("execute ANDI\n")
}

/* ORI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(ORI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ORI))

function clause execute (ITYPE (imm, rs1, rd, ORI)) = {
    print("execute ORI\n")
}

/* XORI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(XORI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, XORI))

function clause execute (ITYPE (imm, rs1, rd, XORI)) = {
    print("execute XORI\n")
}

/* JALR */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(JALR) @ rd : regbits @ 0b1100111
    = Some(ITYPE(imm, rs1, rd, JALR))

function clause execute (ITYPE (imm, rs1, rd, JALR)) = {
    print("execute JALR\n")
}

/* LW */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(LW) @ rd : regbits @ 0b0000011
    = Some(ITYPE(imm, rs1, rd, LW))

function clause execute (ITYPE (imm, rs1, rd, LW)) = {
    print("execute LW\n")
}

/* S-TYPE instructions */
union clause ast = STYPE : (bits(7), regbits, regbits, bits(5), sop)

function clause decode imm2 : bits(7) @ rs2 : regbits @ rs1 : regbits @ encdec_sop(SW) @ imm1 : bits(5) @ 0b0100011
    = Some(STYPE(imm2, rs2, rs1, imm1, SW))

function clause execute (STYPE (imm2, rs2, rs1, imm1, SW)) = {
    print("execute SW\n")
}

/* B-TYPE instructions */
union clause ast = BTYPE : (bits(1), bits(6), regbits, regbits, bits(4), bits(1), bop)

/* BEQ */
function clause decode imm4 : bits(1) @ imm2 : bits(6) @ rs2 : regbits @ rs1 : regbits @ encdec_bop(BEQ) @ imm1 : bits(4) @ imm3 : bits(1) @ 0b1100011
    = Some(BTYPE(imm4, imm2, rs2, rs1, imm1, imm3, BEQ))

function clause execute (BTYPE (imm4, imm2, rs2, rs1, imm1, imm3, BEQ)) = {
    print("execute BEQ\n")
}

/* BNE */
function clause decode imm4 : bits(1) @ imm2 : bits(6) @ rs2 : regbits @ rs1 : regbits @ encdec_bop(BNE) @ imm1 : bits(4) @ imm3 : bits(1) @ 0b1100011
    = Some(BTYPE(imm4, imm2, rs2, rs1, imm1, imm3, BNE))

function clause execute (BTYPE (imm4, imm2, rs2, rs1, imm1, imm3, BNE)) = {
    print("execute BNE\n")
}

/* U-TYPE instructions */
union clause ast = UTYPE : (bits(20), regbits, uop)

/* LUI */
function clause decode imm : bits(20) @ rd : regbits @ 0b0110111
    = Some(UTYPE(imm, rd, LUI))

function clause execute (UTYPE (imm, rd, LUI)) = {
    print("execute LUI\n")
}

/* AUIPC */
function clause decode imm : bits(20) @ rd : regbits @ 0b0010111
    = Some(UTYPE(imm, rd, AUIPC))

function clause execute (UTYPE (imm, rd, AUIPC)) = {
    print("execute AUIPC\n")
}

/* J-TYPE instructions */
union clause ast = JTYPE : (bits(1), bits(10), bits(1), bits(8), regbits, jop)

function clause decode imm4 : bits(1) @ imm1 : bits(10) @ imm2 : bits(1) @ imm3 : bits(8) @ rd : regbits @ 0b1101111
    = Some(JTYPE(imm4, imm1, imm2, imm3, rd, JAL))

function clause execute (J-TYPE (imm4, imm1, imm2, imm3, rd, JAL)) = {
    print("execute JAL\n")
}


end ast /* end scattered ast definition */