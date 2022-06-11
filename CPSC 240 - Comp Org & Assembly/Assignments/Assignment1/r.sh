#!/bin/bash

#Author: Jason Angel

echo "Remove old executable files if there is any"
rm *.out

echo "Assemble the X86 file hello.asm"
nasm -f elf64 -l hello.lis -o hello.o hello.asm

echo "Compile the C++ file welcome.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -l welcome.lis -o welcome.o welcome.cpp -std=c++2a

echo "Link the two 'O' files wlecome.o hello.o"
g++ -m64 -std=c++2a -o go.out hello.o welcome.o -fno-pie -no-pie

echo "Next the program will run"
./go.out

