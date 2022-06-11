extern printf
extern scanf
extern strlen
extern stdin
extern fgets
extern precision
extern abs

global sum

one equ 1;0x3FF0000000000000
negative_one equ -1;0xBFF0000000000000
two equ 2;0x4000000000000000
four equ 4;0x4010000000000000
stop equ 100

align 16
segment .data
cpuGHZ db "This machine is running a cpu rated at 4.20 GHz", 10, 0
clock db "The time on the clock is now %ld tics", 10, 0
sumcomputed db "The sum has been computed", 10, 0
sumresult db "The sum is %.6lf", 10, 0
etime db "The execution time was %ld tics", 10, 0
de db "--> %1.18lf", 10, 0
align 64
segment .bss

segment .text
sum:

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

mov qword rax, 0
mov rdi, cpuGHZ
call printf

call precision
movsd xmm10, xmm0

mov rax, 0
mov rdx, 0
cpuid
rdtsc
shl rdx, 32
add rax, rdx
mov r12, rax

mov qword rax, 0
mov rdi, clock
mov rsi, r12
call printf

mov r15, 0  ;counter
xorpd xmm15, xmm15  ;accumaltor
mov rbx, one
cvtsi2sd xmm13, rbx  ;xmm13 holds one, then -1, then back to 1, etc for each iteration
 
loop:

;reset values
mov rbx, four 
cvtsi2sd xmm11, rbx ;xmm11 holds 4.0
mov rbx, two
cvtsi2sd xmm12, rbx ;xmm12 holds 2.0

;num calculations
mulsd xmm11, xmm13

;denom calculations
cvtsi2sd xmm8, r15
mulsd xmm12, xmm8
mov r13, one
cvtsi2sd xmm9, r13     ;xmm9 holds one 
addsd xmm12, xmm9

;divide num and denom
divsd xmm11, xmm12

;mov rax, 1
;mov rdi, de
;cvtsi2sd xmm6, r15   ;counter
;movsd xmm0, xmm11
;call printf

movsd xmm14, xmm11   ;make backup copy of xmm11
;xorpd xmm12, xmm12
mov rbx, one
cvtsi2sd xmm12, rbx
ucomisd xmm13, xmm12
je continue

n1:
mov rbx, negative_one
cvtsi2sd xmm12, rbx
mulsd xmm11, xmm12

;p1:
;mov rbx, one
;cvtsi2sd xmm12, rbx
;mulsd xmm11, xmm12

;mov rbx, negative_one
;cvtsi2sd xmm12, rbx
;mulsd xmm11, xmm12

continue:

ucomisd xmm11, xmm10
jbe break_loop
;mov rbx, stop
;cvtsi2sd xmm12, rbx
;ucomisd xmm8, xmm12
;je break_loop

addsd xmm15, xmm14

mov rax, 1
mov rdi, de
cvtsi2sd xmm6, r15   ;counter
movsd xmm0, xmm11
call printf

mov rbx, one
cvtsi2sd xmm9, rbx
ucomisd xmm13, xmm9
je switch_to_negative

switich_to_positive:
mov rbx, one
cvtsi2sd xmm9, rbx
movsd xmm13, xmm9
jmp end_of_loop

switch_to_negative:
mov rbx, negative_one
cvtsi2sd xmm9, rbx
movsd xmm13, xmm9

end_of_loop:

inc r15
jmp loop

break_loop:
mov qword rax, 0
mov rdi, sumcomputed
call printf

mov rax, 0
mov rdx, 0
cpuid
rdtsc
shl rdx, 32
add rax, rdx
mov r14, rax

mov qword rax, 0
mov rdi, clock
mov rsi, r14
call printf

mov rax, 1
mov rdi, sumresult
movsd xmm0, xmm15
call printf

mov qword rax, 0
mov rdi, etime
sub r14, r12
mov rsi, r14
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

