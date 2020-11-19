default order dec

$include <prelude.sail>
$include "commands.sail"

type regbits = bits(5)

scattered union ast /* begin scattered ast definition */
val decode : bits(32) -> option(ast) effect pure /* decode function */

/* I-TYPE command */
union clause ast = ITYPE : (bits(12), regbits, regbits, iop)


end ast /* end scattered ast definition */