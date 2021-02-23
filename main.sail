default Order dec

$include <prelude.sail>
$include <elf.sail>
$include "./assembly.sail"

register PC : xlenbits /* Program Counter Register */

/* automatically zero extend bitvectors when necessary */
val cast extz : forall ('n 'm : Int) , 'm > 'n . (implicit('m), bits('n)) -> bits('m)
function extz(m, xs) = sail_zero_extend(xs, m)

/* methods to increment PC Register */
/* val add_bytes_to_PC : forall ('n : Int) , ('n > 0) . (int('n)) -> unit effect {rreg, wreg}
function add_bytes_to_PC(bytes) = {
    PC + bytes;
    x : xlenbits = 0x0;
    match bytes {
        1 => x = 0x8,
        2 => x = 0x10,
        3 => x = 0x18,
        4 => x = 0x20,
        _ => print("Cannot add this amount of bytes to PC register")
    };
    (*ref PC) = PC + x;
} */

/* val add_4_bytes_to_PC: unit -> unit effect {rreg, wreg}
function add_4_bytes_to_PC() = add_bytes_to_PC(4)

overload inc_PC = {add_bytes_to_PC, add_4_bytes_to_PC} */

/* read memory */
val MEMr = {lem: "MEMr", coq: "MEMr", _: "read_ram"}: forall ('n 'm : Int) , 'n >= 0 . (int('m), int('n), bits('m), bits('m)) -> bits(8 * 'n) effect {rmem}
// val read_mem : forall 'n , 'n >= 0 . (xlenbits, int('n)) -> bits(8 * 'n) effect {rmem}
val read_mem : xlenbits -> xlenbits effect {rmem}

// function read_mem(addr, width) = MEMr(sizeof(xlen), width, sail_zero_extend(0x0, sizeof(xlen)), addr)
function read_mem(addr) = MEMr(sizeof(xlen), 4, sail_zero_extend(0x0, sizeof(xlen)), addr)

/* main function with fetch-decode-execute loop */
/* calling './main -e test' in terminal results in error 'Invalid ELF type of machine for class (64-bit)' */
function main() : unit -> unit = {
    // (*ref PC) = elf_entry(); /* error: type coercion from int to bitvector not possible */
    PC = sail_zero_extend(0x1000, sizeof(xlen));
    print("PC = ", PC);
    let line = read_mem(PC) in
    print("line = ", line);
    // inc_PC();
    PC = PC + 4;
    print("PC = ", PC);
    let line = read_mem(PC) in
    print("line = ", line);
    /* fetch-decode-execute loop (CURRENTLY TEMPLATE) */
    EOF : bool = false;
    while (EOF != true) do {
        let instruction : xlenbits = read_mem(*ref PC);
        if (instruction == 0xF) then EOF = true
        else {
            let decoded_instruction = decode(instruction);
            match decoded_instruction {
                Some(inst) => {
                    execute(inst);
                },
                None() => print("Instruction is None()"),
                _ => print("decoding the instruction resulted in something unexpected")
            };
            // inc_PC()
        }
    }
}