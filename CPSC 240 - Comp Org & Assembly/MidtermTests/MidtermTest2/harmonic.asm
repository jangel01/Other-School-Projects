;Jason ANgel
;CPSC 240-03
;jasonangel@csu.fullerton.edu
;Harmonic Sum

extern printf
extern scanf
extern fgets
extern isfloat
extern atof
extern stdin
extern strlen
extern reciprocal_sum

global harmonic

one_point_zero equ 0x3FF0000000000000

align 16
segment .data
welcome db "We will find your harmonic sum", 10, 0
;inputSizePrompt db "Please enter how many numbers are in the set: ", 10, 0
numbersPrompt db "Enter your four numbers one at a time separated by white space: ", 10, 0
sum db "The sum of the harmonic sum of these numbers is: %.6lf", 10, 0
finalMessage db "The reciprocal of sums will be returned to the driver", 10, 0
invalidInput db "Invalid input encountered. Please run this program again.", 10, 0
invalidReturn db "THe floating point %.1lf will be returned the the driver", 10, 0
stringformat db "%s", 0
floatformat db "%lf", 0

align 64
segment .bss
float1 resb 32

segment .text
harmonic:

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

;Output welcome message
mov qword rax, 0
mov rdi, welcome
call printf

;Prompt for inputs
mov qword rax, 0
mov rdi, numbersPrompt
call printf

;Obtain first input
mov qword rax, 0
mov rdi, stringformat
mov rsi, float1
call scanf

;Check to see if first input is a float
mov rax, 0
mov rdi, float1
call isfloat
mov r15, rax

;Check the return value and jump to the end of the program if needed
cmp r15, 0
je invalid

firstInputValid:                    ;Invalid input shall ignore the proceeding code

;Convert first input from a string to a float
mov rax, 0
mov rdi, float1
call atof
movsd xmm10, xmm0

;Obtain second input
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm11, [rsp] 
pop rax
pop rax

;Obtain third input
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm12, [rsp]  
pop rax
pop rax

;Obtain fourth input
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm13, [rsp]
pop rax
pop rax

;Perform calculations
mov rbx, one_point_zero
push rbx
movsd xmm15, [rsp]
divsd xmm15, xmm10
movsd xmm10, xmm15
movsd xmm15, [rsp]
divsd xmm15, xmm11
movsd xmm11, xmm15
movsd xmm15, [rsp]
divsd xmm15, xmm12
movsd xmm12, xmm15
movsd xmm15, [rsp]
divsd xmm15, xmm13
movsd xmm13, xmm15
xorpd xmm14, xmm14
addsd xmm14, xmm10
addsd xmm14, xmm11
addsd xmm14, xmm12
addsd xmm14, xmm13
pop rax

;Print out sum
mov rax, 1
mov rdi, sum
movsd xmm0, xmm14
call printf

;Call reciprocal_sum
mov qword rax, 0
movsd xmm0, xmm14
call reciprocal_sum
movsd xmm14, xmm0

;Print out final message
mov qword rax, 0
mov rdi, finalMessage
call printf

movsd xmm0, xmm14
jmp end

invalid:                     ;Execute if first input was not a float

mov rbx, one_point_zero
push rbx
movsd xmm15, [rsp]
pop rax

;Print out invalid input message
mov qword rax, 0
mov rdi, invalidInput
call printf

;Print out value to be returned to the driver
mov rax, 1
mov rdi, invalidReturn
movsd xmm0, xmm15
call printf

movsd xmm0, xmm15

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
