#!/bin/bash                                                                                                                                              
#Delete some unneeded files=                                                                                                                             
rm *.o
rm *.out

echo "Assemble the X86 file: time.asm"
nasm -f elf64 -l tiime.lis -o tiime.o tiime.asm -g -gdwarf

echo "Compile the C program: driver.c"
gcc -c -Wall -m64 -no-pie -o driver.o driver.c -std=c11 -g

echo "Link the two object files"
gcc -m64 -no-pie -o go.out driver.o tiime.o -std=c11 -g

echo "Run the program"
gdb ./go.out




