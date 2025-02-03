newline: db 10

; rdi: file handle
; rsi: char buf*
fprintln:
    xor r8, r8
.get_length:
    cmp BYTE [rsi + r8], 0
    je .after_get_length

    inc r8
    jmp .get_length
.after_get_length:
    sys_write rdi, rsi, r8
    sys_write rdi, newline, 1
    ret
