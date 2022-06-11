#!/bin/bash                                                                                                                                              

#Delete some unneeded files=                                                                                                                             
rm *.o
rm *.out

echo "Comple driver.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -o driver.o driver.cpp -std=c++17

echo "Compile precision.c"
gcc -c -m64 -Wall -fno-pie -no-pie -o precision.o precision.c -std=c11

echo "Assemble the X86 file asmfunc"
nasm -f elf64 -l asmfunc.lis -o asmfunc.o asmfunc.asm

echo "Link the three object files"
g++ -m64 -fno-pie -no-pie -o go.out driver.o precision.o asmfunc.o -std=c++17

echo "Run the program"
./go.out

