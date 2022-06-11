extern printf
extern scanf
extern fgets
extern stdin
extern strlen
extern strlen

global hello_world

max_name_size equ 32
max_title_size equ 32
max_mood_size equ 32

segment .data

align 16

firstMessage db "Please enter your first and last names: ", 0
secondMessage db "Please enter your title (Ms, Mr, Engineer, Prorammer, Mathmatician, Genius, etc): ", 0
thirdMessage db "Hello %s %s . How has your day been so far?: ", 0
fourthMessage db "%s is really nice", 10, 0
fifthMessage db "This concludes the demostration of the Hello program written in x86 assembly", 10, 0
stringformat db "%s", 0

align 64

segment .bss

name resb max_name_size
title resb max_title_size
mood resb max_mood_size
junk resb 2

segment .text

hello_world:

push rbp
mov rbp, rsp
push rbx
push rcx
push rdx
push rdi
push rsi
push r8
push r9
push r10
push r11
push r12
push r13
push r14
push r15
pushf

;------------Prompt four name -----------"
mov qword rax, 0
mov rdi, stringformat
mov rsi, firstMessage
call printf

;------------Obtain name -----------"
mov qword rax, 0
mov rdi, stringformat
mov rsi, name
;mov rsi, max_name_size
;mov rdx, [stdin]
call scanf

mov qword rax, 0
mov rdi, junk
mov rsi, 2
mov rdx, [stdin]
call fgets

;mov rax, 0                           ;remove newline from input
;mov rdi, name
;call strlen
;mov r14, rax

;mov r15, 0
;mov [name + r14 -1], r15


;----------Prompt for title---------'
mov qword rax, 0
mov rdi, stringformat
mov rsi, secondMessage
call printf

;---------Obtain title----------
;mov qword rax, 0
;mov rdi, title
;mov rsi, max_title_size
;mov rdx, [stdin]
;call fgets

;mov rax, 0                           ;remove newline from input
;mov rdi, title
;call strlen
;mov r14, rax

;mov r15, 0
;mov [title + r14 -1], r15

mov qword rax, 0
mov rdi, stringformat
mov rsi, title
call scanf

mov qword rax, 0
mov rdi, junk
mov rsi, 2
mov rdx, [stdin]
call fgets

;------Prompt mood--------
mov qword rax, 0
mov rdi, thirdMessage
mov rsi, title
mov rdx, name
call printf

;-------Obtain mood-------
mov qword rax, 0
mov rdi, mood
mov rsi, max_mood_size
mov rdx, [stdin]
call fgets

mov rax, 0                           ;remove newline from input
mov rdi, mood
call strlen
mov r14, rax

mov r15, 0
mov [mood + r14 -1], r15

;-----fifthMessage------
mov qword rax, 0
mov rdi, fourthMessage
mov rsi, mood
call printf
 
;----------finalMessage------
mov qword rax, 0
mov rdi, stringformat
mov rsi, fifthMessage
call printf 

mov rax, name
popf
pop r15
pop r14
pop r13
pop r12
pop r11
pop r10
pop r9
pop r8
pop rsi
pop rdi
pop rdx
pop rcx
pop rbx
pop rbp

ret
