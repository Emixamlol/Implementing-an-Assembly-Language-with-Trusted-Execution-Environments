$include <string.sail>

overload operator + = {concat_str}

val print_str   = {c: "print_endline"}  : string -> unit
val print_int   = {c: "print_int"}      : int -> unit
val print_bits  = {c: "print_bits"}     : forall ('n : Int) . bits('n) -> unit

overload print = {print_str, print_int, print_bits}