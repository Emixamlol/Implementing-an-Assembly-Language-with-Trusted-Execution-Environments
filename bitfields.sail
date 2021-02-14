$include <prelude.sail>

/* type declarations */
type xlen : Int = 32
type xlenbits : Type = bits(xlen)
type regbits : Type = bits(5)

/* bitfield declarations */
bitfield rt : xlenbits = {
    SIGN : 31,
    FUNCT7 : 31 .. 25,
    RS2 : 24 .. 20,
    RS1 : 19 .. 15,
    FUNCT3 : 14 .. 12,
    RD : 11 .. 7,
    OPCODE : 6 .. 0
}

bitfield it : xlenbits = {
    SIGN : 31,
    IMM : 31 .. 20,
    RS1 : 19 .. 15,
    FUNCT3 : 14 .. 12,
    RD : 11 .. 7,
    OPCODE : 6 .. 0
}

bitfield st : xlenbits = {
    SIGN : 31,
    IMM2 : 31 .. 25,
    RS2 : 24 .. 20,
    RS1 : 19 .. 15,
    FUNCT3 : 14 .. 12,
    IMM1 : 11 .. 7,
    OPCODE : 6 .. 0
}

bitfield bt : xlenbits = {
    SIGN : 31,
    IMM4 : 31,
    IMM2 : 30 .. 25,
    RS2 : 24 .. 20,
    RS1 : 19 .. 15,
    FUNCT3 : 14 .. 12,
    IMM1 : 11 .. 8,
    IMM3 : 7,
    OPCODE : 6 .. 0
}

bitfield ut : xlenbits = {
    SIGN : 31,
    IMM : 31 .. 12,
    RD : 11 .. 7,
    OPCODE : 6 .. 0
}

bitfield jt : xlenbits = {
    SIGN : 31,
    IMM4 : 31,
    IMM1 : 30 .. 21,
    IMM2 : 20,
    IMM3 : 19 .. 12,
    RD : 11 .. 7,
    OPCODE : 6 .. 0
}