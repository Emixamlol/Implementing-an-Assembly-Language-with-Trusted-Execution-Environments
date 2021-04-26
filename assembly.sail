$include <prelude.sail>
$include "./instructions.sail"

scattered union ast /* begin scattered ast definition */
val decode : xlenbits -> option(ast) effect pure /* decode function */
val execute : ast -> unit effect {rreg, wreg, rmem, wmem} /* execute function */

/* R-TYPE instructions */
union clause ast = RTYPE : (regbits, regbits, regbits, rop)

/* ADD */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(ADD) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, ADD))

function clause execute (RTYPE (rs2, rs1, rd, ADD)) = {
    let rs1_val = rREG(rs1) in
    let rs2_val = rREG(rs2) in
    let result  = rs1_val + rs2_val in
    wREG(rd) = result;
    inc_PC();
}

/* AND */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(AND) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, AND))

function clause execute (RTYPE (rs2, rs1, rd, AND)) = {
    let rs1_val = rREG(rs1) in
    let rs2_val = rREG(rs2) in
    let bitwise_AND = rs1_val & rs2_val in
    match bitwise_AND {
        0b1 => wREG(rd) = 0b1,
        _   => wREG(rd) = 0b0
    };
    inc_PC();
}

/* OR */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(OR) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, OR))

function clause execute (RTYPE (rs2, rs1, rd, OR)) = {
    let rs1_val = rREG(rs1) in
    let rs2_val = rREG(rs2) in
    let bitwise_OR = rs1_val | rs2_val in
    match bitwise_OR {
        0b1 => wREG(rd) = 0b1,
        _   => wREG(rd) = 0b0
    };
    inc_PC();
}

/* XOR */
function clause decode 0b0000000 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(XOR) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, XOR))

function clause execute (RTYPE (rs2, rs1, rd, XOR)) = {
    let rs1_val = rREG(rs1) in
    let rs2_val = rREG(rs2) in
    let bitwise_XOR = rs1_val ^ rs2_val in
    match bitwise_XOR {
        0b1 => wREG(rd) = 0b1,
        _   => wREG(rd) = 0b0
    };
    inc_PC();
}

/* MUL */
function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(MUL) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, MUL))

function clause execute (RTYPE (rs2, rs1, rd, MUL)) = {
    let multiplicand = rREG(rs1) in
    let multiplier = rREG(rs2) in
    let product = multiplicand * multiplier in
    let len = sizeof(xlen) - 1 in
    let result  = product[len .. 0] in
    wREG(rd) = result;
    inc_PC();
}

/* DIV */
function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(DIV) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, DIV))

function clause execute (RTYPE (rs2, rs1, rd, DIV)) = {
    let dividend = rREG(rs1) in
    let divisor = rREG(rs2) in
    let (div, rem) = dividend / divisor in
    let len = sizeof(xlen) - 1 in
    let result = div[len .. 0] in
    wREG(rd) = result;
    inc_PC();
}

/* REM */
function clause decode 0b0000001 @ rs2 : regbits @ rs1 : regbits @ encdec_rop(REM) @ rd : regbits @ 0b0110011
    = Some(RTYPE(rs2, rs1, rd, REM))

function clause execute (RTYPE (rs2, rs1, rd, REM)) = {
    let dividend = rREG(rs1) in
    let divisor = rREG(rs2) in
    let (div, rem) = dividend / divisor in
    let len = sizeof(xlen) - 1 in
    let result = rem[len .. 0] in
    wREG(rd) = result;
    inc_PC();
}

/* I-TYPE instructions */
union clause ast = ITYPE : (bits(12), regbits, regbits, iop)

/* ADDI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(ADDI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ADDI))

function clause execute (ITYPE (imm, rs1, rd, ADDI)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in
    let result  = rs1_val + imm_ext in
    wREG(rd) = result;
    inc_PC();
}

/* SLTI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(SLTI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, SLTI))

function clause execute (ITYPE (imm, rs1, rd, SLTI)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in
    if (rs1_val < imm_ext) then {wREG(rd) = 0b1} else {wREG(rd) = 0b0};
    inc_PC();
}

/* ANDI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(ANDI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ANDI))

function clause execute (ITYPE (imm, rs1, rd, ANDI)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in
    let bitwise_AND = rs1_val & imm_ext in
    match bitwise_AND {
        0b1 => wREG(rd) = 0b1,
        _   => wREG(rd) = 0b0
    };
    inc_PC();
}

/* ORI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(ORI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, ORI))

function clause execute (ITYPE (imm, rs1, rd, ORI)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in
    let bitwise_OR = rs1_val | imm_ext in
    match bitwise_OR {
        0b1 => wREG(rd) = 0b1,
        _   => wREG(rd) = 0b0
    };
    inc_PC();
}

/* XORI */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(XORI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, XORI))

function clause execute (ITYPE (imm, rs1, rd, XORI)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in
    let bitwise_XOR = rs1_val ^ imm_ext in
    match bitwise_XOR {
        0b1 => wREG(rd) = 0b1,
        _   => wREG(rd) = 0b0
    };
    inc_PC();
}

/* JALR */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(JALR) @ rd : regbits @ 0b1100111
    = Some(ITYPE(imm, rs1, rd, JALR))

function clause execute (ITYPE (imm, rs1, rd, JALR)) = {
    wREG(rd) = PC + 4;
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in {
        newPC : xlenbits = rs1_val + imm_ext;
        newPC[0] = bitzero;
        if unprotected(PC) then {
            if protected(newPC) then print("You are not allowed to jump to protected memory section") else PC = newPC;
        } else {
            PC = newPC;
            if unprotected(newPC) then reset_registers();
        };
        if PC == start_boundary then inc_PC();
    }
}

/* LW */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(LW) @ rd : regbits @ 0b0000011
    = Some(ITYPE(imm, rs1, rd, LW))

function clause execute (ITYPE (imm, rs1, rd, LW)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in 
    let addr    = rs1_val + imm_ext in
    if ((protected(addr) & protected(PC)) | unprotected(addr)) then {
        let mem_val = read_mem(addr) in
        wREG(rd) = mem_val
    } else print("You are not allowed to read from protected memory section");
    inc_PC();
}

/* SLLI (assert) */
function clause decode imm : bits(12) @ rs1 : regbits @ encdec_iop(SLLI) @ rd : regbits @ 0b0010011
    = Some(ITYPE(imm, rs1, rd, SLLI))

function clause execute (ITYPE (imm, rs1, rd, SLLI)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm) in
    if (rs1_val == imm_ext) then {wREG(rd) = 0b1} else {wREG(rd) = 0b0};
    inc_PC();
}

/* LB (begin enclave) */
function clause decode imm : bits(12) @ 0b00000 @ encdec_iop(LB) @ 0b00000 @ 0b0000011
    = Some(ITYPE(imm, 0b0, 0b0, LB))

function clause execute (ITYPE (imm, rs1, rd, LB)) = {
    start_boundary = PC; /* save the program counter which currently contains the start-address of the enclave */
    continue_loop : bool = true;
    while (continue_loop) do {
        let instruction : xlenbits = read_mem(*ref PC) in
        let decoded_instruction = decode(instruction) in
        match decoded_instruction {
            Some(ITYPE (imm, rs1, rd, LH))  =>  {end_boundary = PC ; continue_loop = false }, /* save the end-address of the enclave and stop the loop */
            _   =>  inc_PC()
        }
    };
    PC = start_boundary + 4; /* restore the program counter */
}

/* LH (end enclave) */
function clause decode imm : bits(12) @ 0b00000 @ encdec_iop(LH) @ 0b00000 @ 0b0000011
    = Some(ITYPE(imm, 0b0, 0b0, LH))

function clause execute (ITYPE (imm, rs1, rd, LH)) = {
    PC = ra;
    reset_registers();
    inc_PC();
}

/* S-TYPE instructions */
union clause ast = STYPE : (bits(7), regbits, regbits, bits(5), sop)

function clause decode imm2 : bits(7) @ rs2 : regbits @ rs1 : regbits @ encdec_sop(SW) @ imm1 : bits(5) @ 0b0100011
    = Some(STYPE(imm2, rs2, rs1, imm1, SW))

function clause execute (STYPE (imm2, rs2, rs1, imm1, SW)) = {
    let rs1_val = rREG(rs1) in
    let imm_ext = EXTS(imm2 @ imm1) in
    let addr    = rs1_val + imm_ext in {
        if ((protected(addr) & protected(PC)) | unprotected(addr)) then {
            let rs2_val = rREG(rs2) in
            write_mem(addr, rs2_val);
        } else print("You are not allowed to write to protected memory section");
    };
    inc_PC();
}

/* B-TYPE instructions */
union clause ast = BTYPE : (bits(1), bits(6), regbits, regbits, bits(4), bits(1), bop)

/* BEQ */
function clause decode imm4 : bits(1) @ imm2 : bits(6) @ rs2 : regbits @ rs1 : regbits @ encdec_bop(BEQ) @ imm1 : bits(4) @ imm3 : bits(1) @ 0b1100011
    = Some(BTYPE(imm4, imm2, rs2, rs1, imm1, imm3, BEQ))

function clause execute (BTYPE (imm4, imm2, rs2, rs1, imm1, imm3, BEQ)) = {
    let rs1_val = rREG(rs1) in
    let rs2_val = rREG(rs2) in
    if (rs1_val == rs2_val) then {
        let offset = EXTS(imm4 @ imm3 @ imm2 @ imm1) in
        PC = PC + offset;
    }
}

/* BNE */
function clause decode imm4 : bits(1) @ imm2 : bits(6) @ rs2 : regbits @ rs1 : regbits @ encdec_bop(BNE) @ imm1 : bits(4) @ imm3 : bits(1) @ 0b1100011
    = Some(BTYPE(imm4, imm2, rs2, rs1, imm1, imm3, BNE))

function clause execute (BTYPE (imm4, imm2, rs2, rs1, imm1, imm3, BNE)) = {
    let rs1_val = rREG(rs1) in
    let rs2_val = rREG(rs2) in
    if (rs1_val != rs2_val) then {
        let offset = EXTS(imm4 @ imm3 @ imm2 @ imm1) in
        PC = PC + offset;
    }
}

/* U-TYPE instructions */
union clause ast = UTYPE : (bits(20), regbits, uop)

/* LUI */
function clause decode imm : bits(20) @ rd : regbits @ 0b0110111
    = Some(UTYPE(imm, rd, LUI))

function clause execute (UTYPE (imm, rd, LUI)) = {
    wREG(rd) = imm @ sail_zeros(12);
    inc_PC();
}

/* AUIPC */
function clause decode imm : bits(20) @ rd : regbits @ 0b0010111
    = Some(UTYPE(imm, rd, AUIPC))

function clause execute (UTYPE (imm, rd, AUIPC)) = {
    let offset = imm @ sail_zeros(12) in
    wREG(rd) = PC + offset;
    inc_PC();
}

/* J-TYPE instructions */
union clause ast = JTYPE : (bits(1), bits(10), bits(1), bits(8), regbits, jop)

function clause decode imm4 : bits(1) @ imm1 : bits(10) @ imm2 : bits(1) @ imm3 : bits(8) @ rd : regbits @ 0b1101111
    = Some(JTYPE(imm4, imm1, imm2, imm3, rd, JAL))

function clause execute (JTYPE (imm4, imm1, imm2, imm3, rd, JAL)) = {
    wREG(rd) = PC + 4;
    let offset = EXTS(imm4 @ imm3 @ imm2 @ imm1) in
    let newPC = PC + offset in
    if unprotected(PC) then {
        if protected(newPC) then print("You are not allowed to jump to protected memory section") else PC = newPC;
    } else {
        PC = newPC;
        if unprotected(newPC) then reset_registers();
    };
    if PC == start_boundary then inc_PC();
}

/* EBREAK */
union clause ast = EBREAK : unit

function clause decode 0b000000000001 @ 0b00000 @ 0b000 @ 0b00000 @ 0b1110011
    = Some(EBREAK())


/* In any other bit pattern case, decode gives back None() */
function clause decode _
    = None()

end ast /* end scattered ast definition */