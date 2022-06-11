#!/bin/bash

#Delete some unneeded files=
rm *.o
rm *.out

echo "Assemble the X86 file"
nasm -f elf64 -l triangle.lis -o triangle.o triangle.asm

echo "Compile the C program"
gcc -c -Wall -m64 -no-pie -o pythagoras.o pythagoras.c -std=c11 

echo "Link the two object files"
gcc -m64 -no-pie -o go.out pythagoras.o triangle.o -std=c11 

echo "Run the program"
./go.out



