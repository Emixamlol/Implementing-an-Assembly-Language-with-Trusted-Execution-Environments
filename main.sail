default Order dec

$include <prelude.sail>
$include <elf.sail>
$include "./assembly.sail"

function main() : unit -> unit = {
    /* FETCH - DECODE - EXECUTE */
    PC = elf_entry();
    print("PC = ", PC)
}