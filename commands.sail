$include <prelude.sail>

/* R-TYPE commands */
enum rop = {ADD, AND, OR, XOR, MUL, DIV, REM} /* NOP = ADDI, x0, x0, 0 */

/* I-TYPE commands */
enum iop = {ADDI, SLTI, ANDI, ORI, XORI, JALR, LW}

/* S-TYPE commands */
enum sop = {SW}

/* B-TYPE commands */
enum bop = {BEQ, BNE}

/* U-TYPE commands */
enum uop = {LUI, AUIPC}

/* J-TYPE commands */
enum jop = {JAL}

/* mappings */

mapping encdec_rop : rop <-> bits(3) {
    ADD <-> 0b000,
    AND <-> 0b001,
    OR  <-> 0b010,
    XOR <-> 0b011,
    MUL <-> 0b100,
    DIV <-> 0b101,
    REM <-> 0b111
}

mapping encdec_iop : iop <-> bits(3) {
    ADDI    <-> 0b000,
    SLTI    <-> 0b001,
    ANDI    <-> 0b010,
    ORI     <-> 0b011,
    XORI    <-> 0b100,
    JALR    <-> 0b101,
    LW      <-> 0b111
}

mappìng encdec_sop : sop <-> bits(1) {
    SW <-> 0b0
}

mapping encdec_bop : bop <-> bits(1) {
    BEQ <-> 0b0,
    BNE <-> 0b1
}

mapping encdec_uop : uop <-> bits(1) {
    LUI     <-> 0b0,
    AUIPC   <-> 0b1
}

mapping encdec_jop : jop <-> bits(1) {
    JAL <-> 0b0
}