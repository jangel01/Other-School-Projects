#Name: Jason Angel
#Section; CPSC 240-03
#Email: jasonangel@csu.fullerton.edu
#Program name: Electricity


#!/bin/bash

#Delete some unneeded files=
rm *.o
rm *.out

echo "Assemble the X86 file"
nasm -f elf64 -l faraday.lis -o faraday.o faraday.asm 

echo "Compile the C program"
gcc -c -Wall -m64 -no-pie -o ampere.o ampere.c -std=c11 

echo "Link the two object files"
gcc -m64 -no-pie -o go.out ampere.o faraday.o -std=c11 

echo "Run the program"
./go.out


