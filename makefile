all: programa
programa: main funcs
	gcc -o funcs main.o funcs.o
main: main.c funcs.h
	gcc -c main.c
funcs: funcs.c funcs.h
	gcc -c funcs.c