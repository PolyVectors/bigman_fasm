macro exit code {
    mov rax, 60
    mov rdi, code
    syscall
}
