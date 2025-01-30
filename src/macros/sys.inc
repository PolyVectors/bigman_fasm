macro sys_write fd*, buf*, count* {
    mov rax, 1
    mov rdi, fd
    mov rsi, buf
    mov rdx, count
    syscall
}

OK = 0
ERROR = 1

macro sys_exit code* {
    mov rax, 60
    mov rdi, code
    syscall
}
