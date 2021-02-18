all: main.c
	gcc main.c /home/maxime/.opam/default/share/sail/lib/*.c -lgmp -lz -I /home/maxime/.opam/default/share/sail/lib/ -o main

main.c: main.sail assembly.sail instructions.sail bitfields.sail
	sail -c -O main.sail -o main