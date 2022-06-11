;Name: Jason Angel
;Section; CPSC 240-03
;Email: jasonangel@csu.fullerton.edu
;Program name: Electricity

extern printf
extern scanf
extern fgets
extern stdin
extern strlen

global electricity

segment .data
welcome db "This program will help discover your work", 10, 0
voltagePrompt db "Please enter the voltage applied to your electric device: ", 0
electricPrompt db "Please enter the electric resistance found in your device: ", 0
timePrompt db "Please enter the time in seconds when your electric device was running: ", 0
namePrompt db "What is your last name? ", 0
titlePrompt db "What is your title? ", 0
thankyou db "Thank you %s %s .", 0
result db "The work performed by your device was %1.18lf .", 10, 0
stringformat db "%s", 0
floatformat db "%lf", 0
weirdformat db "%s %c", 0
align 64
segment .bss
name resb 32
title resb 32
junk resb 2

segment .text
electricity:

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
pushf

;welcome message
mov qword rax, 0
mov rdi, stringformat
mov rsi, welcome
call printf

;prompt for voltage
mov qword rax, 0
mov rdi, stringformat
mov rsi, voltagePrompt
call printf

;obtain voltage
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm10, [rsp]   ;save voltage in xmm10
pop rax
pop rax

;prompt for electric res
mov qword rax, 0
mov rdi, stringformat
mov rsi, electricPrompt
call printf

;obtain electric res
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm11, [rsp] ;save electirc res in xmm11
pop rax
pop rax

;prompt for time
mov qword rax, 0
mov rdi, stringformat
mov rsi, timePrompt
call printf

;obtain time
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm12, [rsp]  ;save time in xmm12
pop rax
pop rax

;prompt for last name
mov qword rax, 0
mov rdi, stringformat
mov rsi, namePrompt
call printf

;clear buffer
mov qword rax, 0
mov rdi, junk
mov rsi, 2
mov rdx, [stdin]
call fgets

;obtain name
mov qword rax, 0
mov rdi, name
mov rsi, 32
mov rdx, [stdin]
call fgets

;obtain name
;mov qword rax, 0
;mov rdi, stringformat
;mov rsi, name
;call scanf

;remove newline from name
mov rax, 0                           
mov rdi, name
call strlen
mov r14, rax
mov r15, 0
mov [name + r14 -1], r15

;prompt for title
mov qword rax, 0
mov rdi, stringformat
mov rsi, titlePrompt
call printf

;obtain title
mov qword rax, 0
mov rdi, title
mov rsi, 32
mov rdx, [stdin]
call fgets

;obtain title
;mov qword rax, 0
;mov rdi, stringformat
;mov rsi, title
;call scanf

;remove newline from title
mov rax, 0                           
mov rdi, title
call strlen
mov r14, rax
mov r15, 0
mov [title + r14 -1], r15

;calculate current
movsd xmm13, xmm10       ;make backup copy of voltage
divsd xmm10, xmm11       ;divide voltage by resistance
movsd xmm5, xmm10        ;place current in xmm5

;calculate power
mulsd xmm5, xmm13        ;xmm5 now holds power instead of current

;now calculate work
mulsd xmm5, xmm12       ;multiply power and time
movsd xmm15, xmm5       ;save work

;print out thank you
mov qword rax, 0
mov rdi, thankyou
mov rsi, title
mov rdx, name
call printf

;print out result
mov rax, 1
mov rdi, result
movsd xmm0, xmm15
call printf

mov rax, name

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
