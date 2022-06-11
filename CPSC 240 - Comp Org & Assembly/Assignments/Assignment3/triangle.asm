;Program name: "String I/O Demonstration".  This program demonstrates how to input and output a string with embedded white  *
;space.  Copyright (C) 2017  Floyd Holliday                                                                                 *
;This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  *
;version 3 as published by the Free Software Foundation.                                                                    *
;This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied         *
;warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     *
;A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                           *
;****************************************************************************************************************************




;========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3=========4=========5=========6=========7**
;Author information
;  Author name: Jason Angel
;  Author email: jasonangel@csu.fullerton.edu
;
;Program information
; Program name: Right Triangles
;  Programming languages X86 with one module in C
;  Date program began Unkown
;  Date program completed 2021 Sept 29
;
;Purpose
;  Practice with xmm registers and input validation
;
;Project information
;  Files: pythagoras.c triangle.asm r.sh 
;  Status: The program has been tested extensively with no detectable errors.
;===== Begin code area ====================================================================================================================================================

extern printf
extern scanf
extern fgets
extern strlen
extern stdin

global triangle

two_point_zero equ 0x4000000000000000
segment .data

namePrompt db "PLease enter your last name: ", 0
titlePrompt db "Please enter your title (Mr, Ms, Nurse, Engineer, etc): ", 0
triangleInput db "Please enter the sides of your triangle separated by ws: ", 0
areaOfTriangle db "THe area of this triangle is %1.18lf square units ", 10, 0
lengthOfHypotenuse db "The length of the hypotenuse is %1.18lf units", 10, 0
farewell db "Please enjoy your triangles %s %s", 10, 0
error db "Do not input sides less than or equal to zero. Ending program....", 10, 0
stringformat db "%s", 0
eight_byte_format db "%lf", 0
two_float_format db "%lf %lf", 0

align 64

segment .bss
name resb 32
title resb 32

segment .text

triangle:

push       rbp                                              ;Save a copy of the stack base pointer
mov        rbp, rsp                                         ;We do this in order to be 100% compatible with C and C++.
push       rbx                                              ;Back up rbx
push       rcx                                              ;Back up rcx
push       rdx                                              ;Back up rdx
push       rsi                                              ;Back up rsi
push       rdi                                              ;Back up rdi
push       r8                                               ;Back up r8
push       r9                                               ;Back up r9
push       r10                                              ;Back up r10
push       r11                                              ;Back up r11
push       r12                                              ;Back up r12
push       r13                                              ;Back up r13
push       r14                                              ;Back up r14
push       r15                                              ;Back up r15
pushf                                                       ;Back up rflags

;Prompt for name
mov qword rax, 0
mov rdi, stringformat
mov rsi, namePrompt
call printf

;Obtain name
mov qword rax, 0
mov rdi, name
mov rsi, 32
mov rdx, [stdin]
call fgets

;Prompt for title
mov qword rax, 0
mov rdi, stringformat
mov rsi, titlePrompt
call printf

;Obtain title
mov qword rax, 0
mov rdi, title
mov rsi, 32
mov rdx, [stdin]
call fgets

;Remove newline from input
mov rax, 0                           
mov rdi, title
call strlen
mov r14, rax
mov r15, 0
mov [title + r14 -1], r15

;Prompt for triangle input
mov qword rax, 0
mov rdi, stringformat
mov rsi, triangleInput
call printf

;Obtain triangle input
push qword -1
push qword -2
mov qword rax, 0
mov rdi, two_float_format
mov rsi, rsp
mov rdx, rsp
add rdx, 8
call scanf

movsd xmm0, [rsp]
movsd xmm1, [rsp +8]
pop rax
pop rax

;see if either side is negative
xorpd xmm10, xmm10
ucomisd xmm0, xmm10
jbe negative
ucomisd xmm1, xmm10
jbe negative
                      
;Calculate area of the triangle
continue:
movsd xmm2, xmm0                 ;save a copy of xmm0
mov rbx, two_point_zero
push rbx
mulsd xmm0, xmm1
divsd xmm0, [rsp]
pop rax

;Save a copy of the sides before calling printf
;push qword -1
;push qword -2
;movsd [rsp], xmm2
;movsd [rsp +8], xmm1
movsd xmm13, xmm2           ;save copy of xmm2
movsd xmm14, xmm1	    ;save copy of xmm1

;Output area of triangle
mov rax, 1
mov rdi, areaOfTriangle
call printf

;Calculate the length of the hypotenuse
;movsd xmm0, [rsp]
;movsd xmm1, [rsp + 8]
;pop rax
;pop rax
movsd xmm0, xmm13
movsd xmm1, xmm14

mulsd xmm0, xmm0
mulsd xmm1, xmm1
addsd xmm0, xmm1
sqrtsd xmm0, xmm0

;Output the length of the hypotenuse
mov rax, 1
mov rdi, lengthOfHypotenuse
movsd xmm15, xmm0             ;make a backup copy of xmm0
call printf

;Farewell message
mov qword rax, 0
mov rdi, farewell
mov rsi, title
mov rdx, name
call printf

movsd xmm0, xmm15     ;return the length of the hypotenuse to the C program
jmp end               ;skip the negative block 

;Only execute this block of code if either side of the triangle was a negative
negative:             	
mov qword rax, 0 
mov rdi, error
call printf
xorpd xmm11, xmm11  
movsd xmm0, xmm11    ;return 0 to the C program
	

end:

popf                                                        ;Restore rflags
pop        r15                                              ;Restore r15
pop        r14                                              ;Restore r14
pop        r13                                              ;Restore r13
pop        r12                                              ;Restore r12
pop        r11                                              ;Restore r11
pop        r10                                              ;Restore r10
pop        r9                                               ;Restore r9
pop        r8                                               ;Restore r8
pop        rdi                                              ;Restore rdi
pop        rsi                                              ;Restore rsi
pop        rdx                                              ;Restore rdx
pop        rcx                                              ;Restore rcx
pop        rbx                                              ;Restore rbx
pop        rbp                                              ;Restore rbp

ret
