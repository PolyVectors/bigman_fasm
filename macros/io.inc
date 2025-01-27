STDOUT_FILENO = 1
STDIN_FILENO = 0

macro write fd*, str*, str_len* {
    mov rax, 1
    mov rdi, fd
    mov rsi, str
    mov rdx, str_len
    syscall
}
