format ELF64 executable

include 'macros/sys.inc'
include 'macros/lang.inc'

hello: db "Hello, world!", 10
hello_len = $-hello

argc: dq 0

file_path rb 64
file_path_len: db 0

entry _start
_start:
    pop r8
    mov [argc], r8
    pop r8
    pop r8

.append_file_path:
    cmp BYTE [r8], 0
    je .after_append_file_path

    mov al, BYTE [r8]
    mov r9, file_path_len
    movzx rcx, BYTE [r9]
    mov [file_path + rcx], al

    inc r8
    inc BYTE [file_path_len]
    jmp .append_file_path

.after_append_file_path:
    movzx rdx, BYTE [file_path_len]
    SYS_write STDOUT_FILENO, file_path, rdx

    SYS_exit 0
