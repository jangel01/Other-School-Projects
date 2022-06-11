extern printf
extern scanf
extern fgets
extern atof
extern isfloat
extern stdin
extern strlen

global hi

negative_one equ 0xBFF0000000000000

align 16
segment .data
welcome db "We will find your power", 10, 0
namePrompt db "Please choose your name. You choose the format of your name: ", 0
greeting db "Welcome %s ", 10, 0
resisPrompt db "Please enter the resistance of your circuit: ", 0
currPrompt db "Please enter the current flow in this circuit: ", 0
result db "Thank you %s. Your power consumption is %.5lf watts", 10, 0
invalidInput db "Invalid input detected. You may run this program again.", 10, 0
stringformat db "%s", 0
one_float_format db "%lf", 0

align 64
segment .bss
userName resb 32
float1 resb 32
float2 resb 32

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
pushf                         

;Output welcome message
mov qword rax, 0
mov rdi, welcome
call printf

;Prompt for name
mov qword rax, 0
mov rdi, namePrompt
call printf

;Obtain name
;mov qword rax, 0
;mov rdi, userName
;mov rsi, 32
;mov rdx, [stdin]
;call fgets

;Remove newline from name variable
;mov rax, 0                           
;mov rdi, userName
;call strlen
;mov r14, rax
;mov r15, 0
;mov [userName + r14 -1], r15

mov qword rax, 0
mov rdi, stringformat
mov rsi, userName
call scanf

;Output greeting
mov qword rax, 0
mov rdi, greeting
mov rsi, userName
call printf

;Prompt for resistance
mov qword rax, 0
mov rdi, resisPrompt
call printf

;Obtain resistance
mov qword rax, 0
mov rdi, stringformat
mov rsi, float1
call scanf

;Check to see if float1 is an actual float
mov rax, 0
mov rdi, float1
call isfloat
mov r15, rax

;Check the return value and jump to the end of the program if needed
cmp r15, 0
je invalid

firstInputValid:                    ;Invalid input shall ignore the proceeding code

;Convert float1 from a string to a float
mov rax, 0
mov rdi, float1
call atof
movsd xmm10, xmm0

;Prompt for second float
mov qword rax, 0
mov rdi, currPrompt
call printf

;Obtain second float
mov qword rax, 0
mov rdi, stringformat
mov rsi, float2
call scanf

;Check to see if float2 is an actual float
mov rax, 0
mov rdi, float2
call isfloat
mov r15, rax

;Check the return value and jump to the end of the program if needed
cmp r15, 0
je invalid

secondInputValid:                 ;Invalid input shall ignore the proceeding code

;Convert float2 to a float
mov rax, 0
mov rdi, float2
call atof
movsd xmm11, xmm0

;Do computations
mulsd xmm11, xmm11 ;(I^2)
mulsd xmm11, xmm10  ;(I x R)
movsd xmm0, xmm11

;Output power
mov rax, 1
mov rdi, result
mov rsi, userName
movsd xmm15, xmm0   ;save a copy of xmm0
call printf
movsd xmm0, xmm15
jmp end

invalid:                  ;Invalid input should only execute this code
mov qword rax, 0
mov rdi, invalidInput
call printf
mov rbx, negative_one
push rbx
movsd xmm14, [rsp]
pop rax
movsd xmm0, xmm14

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
