# Jason Angel
# jasonangel@csu.fullerton.edu
# CPSC 240-03
# Final

#!/bin/bash                                                                       
                                                                                                        
#Delete some unneeded files=                                                                                                                            
                                                                                                                                                         
rm *.o
rm *.out

echo "Assemble the X86 file: asmfunc.asm"
nasm -f elf64 -l asmfunc.lis -o asmfunc.o asmfunc.asm

echo "Assemble the X86 file: getfrequency.asm"
nasm -f elf64 -l getfrequency.lis -o getfrequency.o getfrequency.asm

echo "Comple driver.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -o driver.o driver.cpp -std=c++17

echo "Link the three object files"
g++ -m64 -fno-pie -no-pie -o go.out asmfunc.o getfrequency.o driver.o -std=c++17

echo "Run the program"
./go.out

