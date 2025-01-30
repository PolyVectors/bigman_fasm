format ELF64 executable

include 'src/macros/sys.inc'
include 'src/macros/io.inc'

include 'src/errors.inc'

file_path rb 64
file_path_len: db 0

entry _start
_start:
    pop r8
    
    cmp r8, 1
    je no_arguments_provided
    cmp r8, 3
    jge too_many_arguments_provided
     
    add rsp, 8
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
    movzx r8, BYTE [file_path_len]
    sys_write STDOUT_FILENO, file_path, r8

    sys_exit 0
