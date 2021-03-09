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

/* operators for comparing bits */
val gt_bit : forall ('n : Int) . (bits('n), bits('n)) -> bool
function gt_bit(x, y) = unsigned(x) > unsigned(y)

val gte_bit : forall ('n : Int) . (bits('n), bits('n)) -> bool
function gte_bit(x, y) = unsigned(x) >= unsigned(y)

val lt_bit : forall ('n : Int) . (bits('n), bits('n)) -> bool
function lt_bit(x, y) = unsigned(x) < unsigned(y)

val lte_bit : forall ('n : Int) . (bits('n), bits('n)) -> bool
function lte_bit(x, y) = unsigned(x) <= unsigned(y)

overload operator >  = {gt_bit}
overload operator >= = {gte_bit}
overload operator <  = {lt_bit}
overload operator <= = {lte_bit}

/* read and write main registers */
val rX : regbits -> register(xlenbits) effect {rreg}
function rX(r) = let offset = r[2 .. 0] in Xs[unsigned(offset)]

val wX : (regbits, xlenbits) -> unit effect {wreg}
function wX(r, v) = {
    let offset = r[2 .. 0] in match offset {
        0b000   => print("Cannot overwrite hard-wired zero register"),
        _       => (*Xs[unsigned(offset)]) = v
    }
}

overload X = {rX, wX}

/* methods to increment PC Register */
val add_to_PC : forall ('n : Int) , ('n > 0) . (int('n)) -> unit effect {rreg, wreg}
function add_to_PC(bytes) = {PC = PC + bytes}

val inc_PC : unit -> unit effect {rreg, wreg}
function inc_PC() = add_to_PC(4)