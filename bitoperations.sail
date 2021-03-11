/* shifting bits (cf. https://github.com/rems-project/sail/blob/sail2/doc/examples/my_replicate_bits.sail) */
infixl 7 <<
infixl 7 >>

val operator << = "shiftl" : forall 'm. (bits('m), int) -> bits('m)
val "shiftl" : forall 'm. (bits('m), int) -> bits('m)

val operator >> = {
  ocaml: "shiftr_ocaml",
  c: "shiftr_c",
  lem: "shiftr_lem",
  _: "shiftr"
} : forall 'm. (bits('m), int) -> bits('m)

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

/* XOR operator on bits*/
val xor_bit : (bit, bit) -> bit
function xor_bit(b1, b2) = if (b1 == b2) then bitzero else bitone

overload operator ^ = {xor_bit}

val xor_bitvector : forall ('n : Int) , 'n > 1 . (bits('n), bits('n)) -> bits('n)

function xor_bitvector(v1, v2) = {
    let len = sizeof('n);
    result : bits('n) = sail_zeros(len);
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

/* take 2's complement of a bitvector */
val twos_complement : forall ('n : Int) , 'n > 1 . bits('n) -> bits('n)
function twos_complement(v) = {
    result = not_vec(v);
    result = result + 0b1;
    result
}

/* signed bit multiplication */
val mul_bitvector : forall ('n : Int) , 'n > 1 . (bits('n), bits('n)) -> bits(2 * 'n)

function mul_bitvector(multiplicand, multiplier) = {
    let len = sizeof('n);
    ext_muland : bits(2 * 'n) = sail_sign_extend(multiplicand, 2 * len);
    ext_mulier : bits(2 * 'n) = sail_sign_extend(multiplier, 2 * len);
    result : bits(2 * 'n) = sail_zeros(2 * len);
    foreach (i from 0 to (len - 1)) {
        match ext_mulier[i] {
            bitone => if (i == len - 1) then result = result + twos_complement(ext_muland >> i) else result = result + (ext_muland >> i)
        }
    };
    result
}

overload operator * = {mul_bitvector}