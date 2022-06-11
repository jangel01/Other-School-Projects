;Jason Angel
;jasonangel@csu.fullerton.edu
;CPSC 240-03
;Final

extern printf
extern scanf
extern getfreq

global force

zero_point_five equ 0x3FE0000000000000
zero equ 0x0000000000000000

align 16
segment .data
welcome db "Welcome to the Jason Breaking Program", 10, 0
freq db "The frequency (GHz) of the processor in machine is %0.2lf ", 10, 0
massInput db "Please enter the mass of moving vehicle (Kg): ", 0
velocityInput db "Please enter the velocity of the vehicle (meters per second): ", 0
distanceInput db "Please enter the distance (meters) required for a complete stop: ", 0
forceResult db "The required braking force is %.3lf Newtons. ", 10, 0
computation db "The computation required %ld tics or %.2lf nanosec", 10, 0
freqPrompt db "Please enter the cpu frequency (GHz): ", 0
floatformat db "%lf", 0

align 64
segment .bss

segment .text
force:

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
mov rdi, welcome 
call printf

;get freq of the system
mov rax, 0
call getfreq
movsd xmm10, xmm0

;dispplay freq
mov rax, 1
mov rdi, freq
movsd xmm0, xmm10
call printf

;prompt for mass of vehicle
mov qword rax, 0
mov rdi, massInput
call printf

;obtain mass
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm11, [rsp]   ;save mass in xmm11
pop rax
pop rax

;prompt for velocity of the vehicle
mov qword rax, 0
mov rdi, velocityInput
call printf

;obtain velocity
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm12, [rsp]   ;save velocity in xmm12
pop rax
pop rax

;prompt for distance
mov qword rax, 0
mov rdi, distanceInput
call printf

;obtain distance
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm13, [rsp]   ;save distance in xmm13
pop rax
pop rax

;read clock before computation
mov rax, 0
mov rdx, 0
cpuid
rdtsc
shl rdx, 32
add rax, rdx
mov r12, rax

;perform computations
mov rbx, zero_point_five
push rbx
movsd xmm8, [rsp]
pop rax
mulsd xmm11, xmm8    
mulsd xmm12, xmm12   
mulsd xmm11, xmm12    
divsd xmm11, xmm13          ;xmm11 holds the final result   
 
;read clock again
mov rax, 0
mov rdx, 0
cpuid
rdtsc
shl rdx, 32
add rax, rdx
mov r13, rax

;get difference between both clocks and store result in xmm register
sub r13, r12
cvtsi2sd xmm14, r13

;output force result
mov rax, 1
mov rdi, forceResult
movsd xmm0, xmm11
call printf

;check if freq is 0 and ask for the freq if so
mov rbx, zero
push rbx
movsd xmm8, [rsp]
pop rax
xorpd xmm10, xmm10
ucomisd xmm10, xmm8
je inputFreq
jmp continue

inputFreq:
;Prompt for freq
mov qword rax, 0
mov rdi, freqPrompt
call printf

;obtain freq
push qword 999
push qword 0
mov rax, 0
mov rdi, floatformat
mov rsi, rsp
call scanf
movsd xmm10, [rsp]   ;save distance in xmm13
pop rax
pop rax

continue:
;convert tics to nanoseconds
divsd xmm14, xmm10

;output computation time
mov rax, 1
mov rdi, computation
mov rsi, r13
movsd xmm0, xmm14
call printf

movsd xmm0, xmm14

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

