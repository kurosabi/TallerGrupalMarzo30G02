all: Program

Program: Funcs Main
	gcc -o out main.o funcs.o

Funcs: funcs.c funcs.h
	gcc -c funcs.c

Main: main.c funcs.h
	gcc -c main.c
  