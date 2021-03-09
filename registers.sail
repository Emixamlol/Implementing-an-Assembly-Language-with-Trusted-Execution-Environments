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

/* implement XOR operator on bits*/
val xor_bit : (bit, bit) -> bit
function xor_bit(b1, b2) = if (b1 == b2) then bitzero else bitone

overload operator ^ = {xor_bit}

val xor_bitvector : forall ('n : Int) , 'n > 1 . (bits('n), bits('n)) -> bits('n)
function xor_bitvector(v1, v2) = {
    let len = sizeof('n);
    result : bits('n) = sail_zero_extend(0b0, len);
    foreach (i from 0 to (len - 1)) {
        let b1 = v1[i];
        let b2 = v2[i];
        result[i] = b1 ^ b2;
    };
    /* i : int = 0;
    while (i < len) do {
        let b1 = v1[i];
        let b2 = v2[i];
        result[i] = b1 ^ b2;
        i = i + 1;
    }; */
    result
}

overload operator ^ = {xor_bitvector}

/* read and write main registers */
val rX : regbits -> xlenbits effect {rreg}
function rX(r) = let offset = r[2 .. 0] in (*Xs[unsigned(offset)])

val wX : (regbits, xlenbits) -> unit effect {wreg}
function wX(r, v) = {
    let offset = r[2 .. 0] in match offset {
        0b0 => print("Cannot overwrite hard-wired zero register"),
        _   => (*Xs[unsigned(offset)]) = v
    }
}

overload X = {rX, wX}

/* methods to increment PC Register */
val add_to_PC : forall ('n : Int) , ('n > 0) . (int('n)) -> unit effect {rreg, wreg}
function add_to_PC(bytes) = {PC = PC + bytes}

val inc_PC : unit -> unit effect {rreg, wreg}
function inc_PC() = add_to_PC(4)