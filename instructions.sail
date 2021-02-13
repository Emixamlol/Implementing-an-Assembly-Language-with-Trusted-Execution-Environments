$include <prelude.sail>

/* R-TYPE instructions */
enum rop = {ADD, AND, OR, XOR, MUL, DIV, REM} /* NOP = ADDI, x0, x0, 0 */

/* I-TYPE instructions */
enum iop = {ADDI, SLTI, ANDI, ORI, XORI, JALR, LW}

/* S-TYPE instructions */
enum sop = {SW}

/* B-TYPE instructions */
enum bop = {BEQ, BNE}

/* U-TYPE instructions */
enum uop = {LUI, AUIPC}

/* J-TYPE instructions */
enum jop = {JAL}

/* mappings */

mapping encdec_rop : rop <-> bits(3) = {
    ADD <-> 0b000,
    AND <-> 0b111,
    OR  <-> 0b110,
    XOR <-> 0b100,
    MUL <-> 0b000,
    DIV <-> 0b100,
    REM <-> 0b110
}

mapping encdec_iop : iop <-> bits(3) = {
    ADDI    <-> 0b000,
    SLTI    <-> 0b010,
    ANDI    <-> 0b111,
    ORI     <-> 0b110,
    XORI    <-> 0b100,
    JALR    <-> 0b000,
    LW      <-> 0b010
}

mapping encdec_sop : sop <-> bits(3) = {
    SW <-> 0b010
}

mapping encdec_bop : bop <-> bits(3) = {
    BEQ <-> 0b000,
    BNE <-> 0b001
}

mapping encdec_uop : uop <-> bits(1) = {
    LUI     <-> 0b0,
    AUIPC   <-> 0b1
}

mapping encdec_jop : jop <-> bits(1) = {
    JAL <-> 0b0
}