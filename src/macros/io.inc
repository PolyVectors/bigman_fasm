include 'src/macros/sys.inc'

STDIN_FILENO = 0
STDOUT_FILENO = 1
STDERR_FILENO = 2

O_RDONLY = 0

macro fprintln fd*, c_string* {
    mov al, 0
    
    local get_length
    local after_get_length

get_length:
    movzx r8, al
    mov bl, [c_string + r8]
    cmp bl, 0
    je after_get_length

    inc al
    jmp get_length

after_get_length:
    push 10
    movzx r10, al
    
    sys_write fd, c_string, r10
    sys_write fd, rsp, 1
}
