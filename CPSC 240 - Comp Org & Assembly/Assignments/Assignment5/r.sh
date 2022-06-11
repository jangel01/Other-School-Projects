#!/bin/bash                                                                                                                                              
#Delete some unneeded files=                                                                                                                             
rm *.o
rm *.out

echo "Assemble the X86 file: time.asm"
nasm -f elf64 -l tiime.lis -o tiime.o tiime.asm

echo "Assemble the X86 file: getfrequency.asm"
nasm -f elf64 -l getfrequency.lis -o getfrequency.o getfrequency.asm

echo "Compile the C program: driver.c"
gcc -c -Wall -m64 -no-pie -o driver.o driver.c -std=c11

echo "Link the two object files"
gcc -m64 -no-pie -o go.out driver.o getfrequency.o tiime.o -std=c11

echo "Run the program"
./go.out




