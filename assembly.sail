default order dec

$include <prelude.sail>
$include "commands.sail"

type regbits = bits(5)

scattered union ast /* begin scattered ast definition */
val decode : bits(32) -> option(ast) effect pure /* decode function */

/* R-TYPE command */
union clause ast = RTYPE : (regbits, regbits, regbits, rop)

/* I-TYPE command */
union clause ast = ITYPE : (bits(12), regbits, regbits, iop)

/* S-TYPE command */
union clause ast = STYPE : (bits(7), regbits, regbits, bits(5), sop)

/* B-TYPE command */
union clause ast = BTYPE : (bits(1), bits(6), regbits, regbits, bits(4), bits(1), bop)

/* U-TYPE command */
union clause ast = UTYPE : (bits(20), regbits, uop)

/* J-TYPE command */
union clause ast = JTYPE : (bits(1), bits(10), bits(1), bits(9), regbits, jop)


end ast /* end scattered ast definition */