STDIN_FILENO = 0
STDOUT_FILENO = 1
STDERR_FILENO = 2

O_RDONLY = 0

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
