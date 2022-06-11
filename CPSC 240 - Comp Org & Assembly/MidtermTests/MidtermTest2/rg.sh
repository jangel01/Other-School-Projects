#  Jason ANgel
#  CPSC 240-03
#  jasonangel@csu.fullerton.edu
#  Harmonic Sum

#!/bin/bash 

#Delete some unneeded files=                                                                                                                             
rm *.o
rm *.out

echo "Comple isfloat.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -o isfloat.o isfloat.cpp -std=c++17 -g

echo "Comple reciprocal_sum.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -o reciprocal_sum.o reciprocal_sum.cpp -std=c++17 -g

echo "Comple statistics.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -o statistics.o statistics.cpp -std=c++17 -g 

echo "Assemble the X86 file harmonic.asm"
nasm -f elf64 -l harmonic.lis -o harmonic.o harmonic.asm -g -gdwarf

echo "Link the four object files"
g++ -m64 -fno-pie -no-pie -o go.out isfloat.o reciprocal_sum.o statistics.o harmonic.o -std=c++17 -g

echo "Run the program"
gdb ./go.out


