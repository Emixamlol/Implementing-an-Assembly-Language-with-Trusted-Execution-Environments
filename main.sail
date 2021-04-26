default Order dec

$include <prelude.sail>
$include <elf.sail>

/* automatically zero extend bitvectors when necessary */
val cast extz : forall ('n 'm : Int) , 'm > 'n . (implicit('m), bits('n)) -> bits('m)
function extz(m, xs) = sail_zero_extend(xs, m)

$include "./print.sail"
$include "./bitoperations.sail"
$include "./registers.sail"
$include "./assembly.sail"

/* fetch-decode-execute loop */
val fde_loop : unit -> unit effect {rreg, wreg, rmem, wmem}
function fde_loop() = {
    continue_loop : bool = true;
    while (continue_loop) do {
        let instruction : xlenbits = read_mem(*ref PC);
        print("Instruction = ", instruction);
        let decoded_instruction = decode(instruction) in
        match decoded_instruction {
            Some(EBREAK())  => continue_loop = false,
            Some(inst)      => execute(inst),
            None()          => {print("instruction is None()") ; inc_PC()},
            _               => {print("decoding the instruction resulted in something unexpected") ; continue_loop = false}
        };
        print("PC in fde_loop = ", PC);
    }
}

/* main function calling fetch-decode-execute loop */
/* calling './main -e test' in terminal results in error 'Invalid ELF type of machine for class (64-bit)' */
function main() : unit -> unit = {
    PC = get_slice_int(sizeof(xlen), elf_entry(), 0);
    print("PC = ", PC);
    /* call the fetch-decode-execute loop */
    fde_loop();
    /* print register contents after the ELF file has been executed */
    obj_dump();
}