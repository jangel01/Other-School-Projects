extern printf
extern scanf
extern fgets
extern stdin
extern getfreq

global hi

nine_point_eight equ 0x402399999999999A
two_point_zero equ 0x4000000000000000
four_point_two equ 0x4010CCCCCCCCCCCD
;fi equ 0x4049000000000000

align 16
segment .data
billion db "--> %ld ", 10,0
clock db "The current clock time is %ld tics", 10, 0
marblePrompt db "Please enter the height in meters of the dropped marble: ", 0
num db "The num is %1.18lf", 10, 0
beforeroot db "Before root: %1.18lf", 10, 0
result db "THe marble will reach earth after %.6lf seconds", 10, 0
etime db "The execution time was %ld tics which equals %.6lf ns", 10, 0
farewell db "Jason wishes you a nice day", 10, 0
xn db "--> %1.18lf", 10, 0
floatformat db "%lf", 0

align 64
segment .bss

segment .text
hi:

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

mov qword rax, 0
mov rdi, marblePrompt
call printf

push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm13, [rsp]   ;save height of marble in xmm10
pop rax
pop rax

;calculations
mov r14, two_point_zero
mov r15, nine_point_eight
push r15
push r14
movsd xmm10, [rsp]
movsd xmm11, [rsp + 8]
pop rax
pop rax
divsd xmm11, xmm10
divsd xmm13, xmm11

mov rax, 1
mov rdi, beforeroot
movsd xmm0, xmm13
call printf

sqrtsd xmm13, xmm13

mov rax, 1
mov rdi, num
movsd xmm0, xmm11
call printf

mov rax, 1
mov rdi, result
movsd xmm0, xmm13
call printf

mov rax, 0
mov rdx, 0
cpuid
rdtsc
shl rdx, 32
add rax, rdx
mov r13, rax

mov qword rax, 0
mov rdi, clock
mov rsi, r13
call printf

;mov rbx, four_point_two
;push rbx
;movsd xmm14, [rsp]
;pop rax
call getfreq
movsd xmm14, xmm0
mov rax, r13
sub rax, r12
mov r15, rax
cvtsi2sd xmm15, rax
divsd xmm15, xmm14

;sub r13, r12
;mov rbx, four_point_two
;push r13
;push rbx
;movsd xmm14, [rsp]
;movsd xmm15, [rsp + 8]
;pop rax
;pop rax
;divsd xmm15, xmm14

mov qword rax, 1
mov rdi, etime
mov rsi, r15
movsd xmm0, xmm15
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
