STDOUT_FILENO = 1
STDIN_FILENO = 0

macro SYS_write fd*, buf*, count* {
    mov rax, 1
    mov rdi, fd
    mov rsi, buf
    mov rdx, count
    syscall
}

macro SYS_exit code* {
    mov rax, 60
    mov rdi, code
    syscall
}
