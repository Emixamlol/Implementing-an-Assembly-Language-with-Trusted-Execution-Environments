type xlen : Int = 32
type xlenbits : Type = bits(xlen)
type regbits : Type = bits(5)

/* special purpose registers */
register PC : xlenbits              /* program counter */
register start_boundary : xlenbits  /* start address of memory enclave */
register end_boundary : xlenbits    /* end address of memory enclave */

/* general purpose registers */
register zero : xlenbits    /* hard-wired zero */
register ra : xlenbits      /* return address */
register sp : xlenbits      /* stack pointer */
register gp : xlenbits      /* global pointer */
register a0 : xlenbits
register a1 : xlenbits
register a2 : xlenbits
register a3 : xlenbits

let Xs : vector(8, dec, register(xlenbits)) = [ref a3, ref a2, ref a1, ref a0, ref gp, ref sp, ref ra, ref zero]

/* method to sign-extend bitvector to size of xlen */
val EXTS : forall ('n : Int) , 0 < 'n <= xlen  . bits('n) -> xlenbits
function EXTS(xs) = sail_sign_extend(xs, sizeof(xlen))

/* methods to increment PC Register */
val add_to_PC : forall ('n : Int) , ('n > 0) . (int('n)) -> unit effect {rreg, wreg}
function add_to_PC(bytes) = {PC = PC + bytes}

val inc_PC : unit -> unit effect {rreg, wreg}
function inc_PC() = add_to_PC(4)

/* test if an address is in protected memory or not */
val protected : xlenbits -> bool effect {rreg}
function protected(addr) = {start_boundary <= addr & addr <= end_boundary}

val unprotected : xlenbits -> bool effect {rreg}
function unprotected(addr) = {addr < start_boundary | end_boundary < addr}

/* read and write general purpose registers */
val reg_offset : regbits -> bits(3)
function reg_offset(r) = {
    match r {
        reg if 0b00000 <= reg & reg <= 0b00011 => r[2 .. 0],
        0b01010 => 0b100,
        0b01011 => 0b101,
        0b01100 => 0b110,
        0b01101 => 0b111,
        _       => 0b000
    }
}

val rREG : regbits -> xlenbits effect {rreg}
function rREG(r) = let offset = reg_offset(r) in (*Xs[unsigned(offset)])

val wREG : (regbits, xlenbits) -> unit effect {wreg}
function wREG(r, v) = {
    let offset = reg_offset(r) in match offset {
        0b000   => if (v == 0b0) then {(*Xs[0]) = 0b0} else print("Cannot overwrite hard-wired zero register"),
        _       => (*Xs[unsigned(offset)]) = v
    }
}

/* read and write memory */
val MEMr = {lem: "MEMr", coq: "MEMr", _: "read_ram"}: forall ('n 'm : Int) , 'n >= 0 . (int('m), int('n), bits('m), bits('m)) -> bits(8 * 'n) effect {rmem}
/* val read_mem : forall 'n , 'n >= 0 . (xlenbits, int('n)) -> bits(8 * 'n) effect {rmem} */
val read_mem : xlenbits -> xlenbits effect {rmem}

/* function read_mem(addr, width) = MEMr(sizeof(xlen), width, sail_zeros(sizeof(xlen)), addr) */
function read_mem(addr) = MEMr(sizeof(xlen), 4, sail_zeros(sizeof(xlen)), addr)

val MEMw = {lem: "MEMw", coq: "MEMw", _: "write_ram"}: forall ('n 'm : Int) , 'n >= 0 . (int('m), int('n), bits('m), bits('m), bits('m)) -> unit effect {wmem}

val write_mem : (xlenbits, xlenbits) -> unit effect {wmem}
function write_mem(addr, data) = MEMw(sizeof(xlen), 4, sail_zeros(sizeof(xlen)), addr, data)

/* reset general purpose registers (resets all but a3) */
val reset_registers : unit -> unit effect {wreg}
function reset_registers() = {
    foreach (i from 1 to 6) {
        (*Xs[i]) = 0b0;
    }
}

/* display the contents of all registers */
val obj_dump : unit -> unit effect {rreg}

function obj_dump() = {
    foreach (i from 0 to 7) {
        let content = (*Xs[i]);
        reg_name : string = match i {
            0   => "zero",
            1   => "ra",
            2   => "sp",
            3   => "gp",
            4   => "a0",
            5   => "a1",
            6   => "a2",
            7   => "a3"
        };
        print(reg_name + " = ", content)
    }
}