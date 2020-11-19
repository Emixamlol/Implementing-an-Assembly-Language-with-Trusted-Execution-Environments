default order dec

$include <prelude.sail>
$include "commands.sail"

scattered union ast /* begin scattered ast definition */
val decode : bits(32) -> option(ast) effect pure /* decode function */

/* LUI command */
union clause ast = LUI

/* AUIPC command */
union clause ast = AUIPC

/* JAL command */
union clause ast = JAL

/* JALR command */
union clause ast = JALR

/* BEQ command */
union clause ast = BEQ

/* BNE command */
union clause ast = BNE


end ast /* end scattered ast definition */