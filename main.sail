default Order dec

$include <prelude.sail>
$include <elf.sail>
$include "./print.sail"
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
    test : bits(8) = 0xFF;
    test = sail_shiftleft(test, 3);
    print("test = ", test);
    let a = 0b1001;
    let b = 0b0011;
    let (div, rem) = a / b;
    print("quotient = ", div);
    print("remainder = ", rem);
    let c = 0b1110;
    let d = 0b0011;
    let mul = d * c;
    print("mul = ", mul);
   /*  let quotient = div[0];
    let remainder = div[1];
    print("quotient = ", quotient);
    print("remainder = ", remainder); */
    /* call the fetch-decode-execute loop */
    //fde_loop();
}