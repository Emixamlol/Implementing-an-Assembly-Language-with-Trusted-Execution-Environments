default Order dec

$include <prelude.sail>
$include <elf.sail>
$include "./assembly.sail"

register PC : xlenbits

val MEMr = {lem: "MEMr", coq: "MEMr", _: "read_ram"}: forall ('n 'm : Int) , 'n >= 0 . (int('m), int('n), bits('m), bits('m)) -> bits(8 * 'n) effect {rmem}
// val read_mem : forall 'n , 'n >= 0 . (xlenbits, int('n)) -> bits(8 * 'n) effect {rmem}
val read_mem : xlenbits -> xlenbits effect {rmem}

// function read_mem(addr, width) = MEMr(sizeof(xlen), width, sail_zero_extend(0x0, sizeof(xlen)), addr)
function read_mem(addr) = MEMr(sizeof(xlen), 4, sail_zero_extend(0x0, sizeof(xlen)), addr)

function main() : unit -> unit = {
    /* FETCH - DECODE - EXECUTE */
    // (*ref PC) = elf_entry(); /* error: type coercion from int to bitvector not possible */
    PC = sail_zero_extend(0x1000, sizeof(xlen));
    print("PC = ", PC);
    let line = read_mem(PC) in
    print("line = ", line);
    print("size xlen = ", sizeof(xlen));
    i : int = 0;
    while (i < 10) do {
        print("i = ", i);
        i = i + 1;
    }
}