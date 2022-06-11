#!/bin/bash

#Delete some unneeded files=
rm *.o
rm *.out

echo "Comple isfloat.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -o isfloat.o isfloat.cpp -std=c++17

echo "Assemble the X86 file"
nasm -f elf64 -l hertz.lis -o hertz.o hertz.asm

echo "Compile maxwell.c"
gcc -c -m64 -Wall -fno-pie -no-pie -o maxwell.o maxwell.c -std=c11

echo "Link the three object files"
g++ -m64 -fno-pie -no-pie -o go.out isfloat.o hertz.o maxwell.o -std=c++17

echo "Run the program"
./go.out



