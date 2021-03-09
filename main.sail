default Order dec

$include <prelude.sail>
$include <elf.sail>
$include "./print.sail"
$include "./registers.sail"
$include "./assembly.sail"

/* automatically zero extend bitvectors when necessary */
val cast extz : forall ('n 'm : Int) , 'm > 'n . (implicit('m), bits('n)) -> bits('m)
function extz(m, xs) = sail_zero_extend(xs, m)

/* read memory */
val MEMr = {lem: "MEMr", coq: "MEMr", _: "read_ram"}: forall ('n 'm : Int) , 'n >= 0 . (int('m), int('n), bits('m), bits('m)) -> bits(8 * 'n) effect {rmem}
// val read_mem : forall 'n , 'n >= 0 . (xlenbits, int('n)) -> bits(8 * 'n) effect {rmem}
val read_mem : xlenbits -> xlenbits effect {rmem}

// function read_mem(addr, width) = MEMr(sizeof(xlen), width, sail_zero_extend(0x0, sizeof(xlen)), addr)
function read_mem(addr) = MEMr(sizeof(xlen), 4, sail_zero_extend(0x0, sizeof(xlen)), addr)

/* fetch-decode-execute loop */
val fde_loop : unit -> unit effect {rreg, wreg, rmem}
function fde_loop() = {
    continue_loop : bool = true;
    while (continue_loop) do {
        let instruction : xlenbits = read_mem(*ref PC);
        print("Instruction = ", instruction);
        let decoded_instruction = decode(instruction) in
        match decoded_instruction {
            Some(EBREAK())  => continue_loop = false,
            Some(inst)      => execute(inst),
            None()          => print("instruction is None()"),
            _               => print("decoding the instruction resulted in something unexpected")
        };
        print("PC in fde_loop = ", PC);
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
    /* call the fetch-decode-execute loop */
    fde_loop();
}