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

;Calculate area of the triangle
movsd xmm2, xmm0                 ;save a copy of xmm0
mov rbx, two_point_zero
push rbx
mulsd xmm0, xmm1
divsd xmm0, [rsp]
pop rax

;Save a copy of the sides before calling printf
push qword -1
push qword -2
movsd [rsp], xmm2
movsd [rsp +8], xmm1

;Output area of triangle
mov rax, 1
mov rdi, areaOfTriangle
call printf

;Calculate the length of the hypotenuse
movsd xmm0, [rsp]
movsd xmm1, [rsp + 8]
pop rax
pop rax

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

movsd xmm0, xmm15

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
