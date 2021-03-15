type xlen : Int = 32
type xlenbits : Type = bits(xlen)
type regbits : Type = bits(5)

register PC : xlenbits /* Program Counter Register */

/* main registers */
register zero : xlenbits    /* hard-wired zero */
register ra : xlenbits      /* return address */
register sp : xlenbits      /* stack pointer */
register gp : xlenbits      /* global pointer */
register a0 : xlenbits
register a1 : xlenbits
register a2 : xlenbits
register a3 : xlenbits

let Xs : vector(8, dec, register(xlenbits)) = [ref a3, ref a2, ref a1, ref a0, ref gp, ref sp, ref ra, ref zero]

/* automatically zero extend bitvectors when necessary */
val cast extz : forall ('n 'm : Int) , 'm > 'n . (implicit('m), bits('n)) -> bits('m)
function extz(m, xs) = sail_zero_extend(xs, m)

/* method to sign-extend bitvector to size of xlen */
val EXTS : forall ('n : Int) , 0 < 'n <= xlen  . bits('n) -> xlenbits
function EXTS(xs) = sail_sign_extend(xs, sizeof(xlen))

/* methods to increment PC Register */
val add_to_PC : forall ('n : Int) , ('n > 0) . (int('n)) -> unit effect {rreg, wreg}
function add_to_PC(bytes) = {PC = PC + bytes}

val inc_PC : unit -> unit effect {rreg, wreg}
function inc_PC() = add_to_PC(4)

/* read and write main registers */
val rREG : regbits -> xlenbits effect {rreg}
function rREG(r) = let offset = r[2 .. 0] in (*Xs[unsigned(offset)])

val wREG : (regbits, xlenbits) -> unit effect {wreg}
function wREG(r, v) = {
    let offset = r[2 .. 0] in match offset {
        0b0 => print("Cannot overwrite hard-wired zero register"),
        _   => (*Xs[unsigned(offset)]) = v
    }
}

/* read memory */
val MEMr = {lem: "MEMr", coq: "MEMr", _: "read_ram"}: forall ('n 'm : Int) , 'n >= 0 . (int('m), int('n), bits('m), bits('m)) -> bits(8 * 'n) effect {rmem}
/* val read_mem : forall 'n , 'n >= 0 . (xlenbits, int('n)) -> bits(8 * 'n) effect {rmem} */
val read_mem : xlenbits -> xlenbits effect {rmem}

/* function read_mem(addr, width) = MEMr(sizeof(xlen), width, sail_zero_extend(0x0, sizeof(xlen)), addr) */
function read_mem(addr) = MEMr(sizeof(xlen), 4, sail_zero_extend(0x0, sizeof(xlen)), addr)