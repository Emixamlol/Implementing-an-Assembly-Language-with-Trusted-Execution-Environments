default Order dec

$include <prelude.sail>
$include <elf.sail>
$include "./assembly.sail"

register PC : xlenbits /* Program Counter Register */

/* automatically zero extend bitvectors when necessary */
val cast extz : forall ('n 'm : Int) , 'm > 'n . (implicit('m), bits('n)) -> bits('m)
function extz(m, xs) = sail_zero_extend(xs, m)

/* methods to increment PC Register */
val add_to_PC : forall ('n : Int) , ('n > 0) . (int('n)) -> unit effect {rreg, wreg}
function add_to_PC(bytes) = {PC = PC + bytes}

val inc_PC : unit -> unit effect {rreg, wreg}
function inc_PC() = add_to_PC(4)

/* read memory */
val MEMr = {lem: "MEMr", coq: "MEMr", _: "read_ram"}: forall ('n 'm : Int) , 'n >= 0 . (int('m), int('n), bits('m), bits('m)) -> bits(8 * 'n) effect {rmem}
// val read_mem : forall 'n , 'n >= 0 . (xlenbits, int('n)) -> bits(8 * 'n) effect {rmem}
val read_mem : xlenbits -> xlenbits effect {rmem}

// function read_mem(addr, width) = MEMr(sizeof(xlen), width, sail_zero_extend(0x0, sizeof(xlen)), addr)
function read_mem(addr) = MEMr(sizeof(xlen), 4, sail_zero_extend(0x0, sizeof(xlen)), addr)

/* fetch-decode-execute loop */
val fde_loop : unit -> unit effect {rreg, wreg, rmem}
function fde_loop() = {
    EOF : bool = false;
    while (EOF != true) do {
        let instruction : xlenbits = read_mem(*ref PC) in
        let decoded_instruction = decode(instruction) in
        match decoded_instruction {
            Some(inst)  => execute(inst),
            None()      => print("instruction is None()"),
            _           => print("decoding the instruction resulted in something unexpected")
        };
        inc_PC();
    }
}

/* main function calling fetch-decode-execute loop */
/* calling './main -e test' in terminal results in error 'Invalid ELF type of machine for class (64-bit)' */
function main() : unit -> unit = {
    PC = get_slice_int(sizeof(xlen), elf_entry(), 0);
    print("PC = ", PC);
    let line = read_mem(PC) in
    print("line = ", line);
    inc_PC();
    PC = PC + 4;
    print("PC = ", PC);
    let line = read_mem(PC) in
    print("line = ", line);
    /* call the fetch-decode-execute loop */
    fde_loop();
}