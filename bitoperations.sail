/* shifting bits (cf. https://github.com/rems-project/sail/blob/sail2/doc/examples/my_replicate_bits.sail) */
infixl 7 <<
infixl 7 >>

overload operator << = {sail_shiftleft}
overload operator >> = {sail_shiftright}

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

/* XOR operator on bits and booleans*/
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
    result
}

overload operator ^ = {xor_bitvector}

val xor_bool : (bool, bool) -> bool
function xor_bool(b1, b2) = if (b1 == b2) then false else true

overload operator ^ = {xor_bool}

/* take 2's complement of a bitvector */
val twos_complement : forall ('n : Int) , 'n > 1 . bits('n) -> bits('n)
function twos_complement(v) = {
    result = not_vec(v);
    result = result + 0b1;
    result
}

/* take the absolute value of or bitvector */
val abs : forall ('n : Int) , 'n > 1 . bits('n) -> bits('n)
function abs(v) = {
    let msb = sizeof('n) - 1 in
    match v[msb] {
        bitzero => v,
        bitone  => twos_complement(v)
    }
}

/* signed bit multiplication */
val mul_bitvector : forall ('n : Int) , 'n > 1 . (bits('n), bits('n)) -> bits(2 * 'n)

function mul_bitvector(multiplicand, multiplier) = {
    print("multiplicand = ", signed(multiplicand));
    print("mutliplier = ", signed(multiplier));
    let len = sizeof('n);
    let ext_muland : bits(2 * 'n) = sail_sign_extend(multiplicand, 2 * len);
    let ext_mulier : bits(2 * 'n) = sail_sign_extend(multiplier, 2 * len);
    result : bits(2 * 'n) = sail_zeros(2 * len);
    let msb = len - 1 in
    foreach (i from 0 to msb) {
        if (ext_mulier[i] == bitone) then {
            match i {
                msb if msb == (len - 1) => result = result + twos_complement(ext_muland << i),
                _   => result = result + (ext_muland << i)
            };
        }
    };
    print("result = ", signed(result));
    result
}

overload operator * = {mul_bitvector}

/* signed bit division */

overload operator - = {sub_bits}

val div_bitvector : forall ('n : Int) , 'n > 1 . (bits('n), bits('n)) -> (bits(2 * 'n), bits(2 * 'n))

function div_bitvector(dividend, divisor) = {
    print("dividend = ", signed(dividend));
    print("divisor = ", signed(divisor));
    let len = sizeof('n);
    let ext_divsor  : bits(2 * 'n) = abs(sail_sign_extend(divisor, 2 * len));
    ext_divend      : bits(2 * 'n) = abs(sail_sign_extend(dividend, 2 * len));
    quotient    : bits(2 * 'n) = sail_zeros(2 * len);
    remainder   : bits(2 * 'n) = sail_zeros(2 * len);
    foreach (i from 0 to len) {
        let shift = len - i;
        if (ext_divend > (ext_divsor << shift)) then {
            ext_divend = ext_divend - (ext_divsor << shift);
            quotient[shift] = bitone;
        };
        if (shift == 0) then remainder = replicate_bits(ext_divend, 1);
    };
    let msb = len - 1 in
    if ((dividend[msb] == bitone) ^ (divisor[msb] == bitone)) then {
        quotient    = twos_complement(quotient);
        remainder   = twos_complement(remainder);
    };
    print("quotient = ", signed(quotient));
    print("remainder = ", signed(remainder));
    (quotient, remainder)
}

overload operator / = {div_bitvector}