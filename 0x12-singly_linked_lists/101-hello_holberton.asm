section .data
text:	db "Hello, Holberton", 10, 0

section .text

extern printf

global main

main:
	mov rdi, text
	mov rax, 0
	call printf

	mov rax, 0
	ret
