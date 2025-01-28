macro for i*, start*, end* {
    mov QWORD [i], start
.#i#_again:
    cmp QWORD [i], end
    jge .#i#_over
}

macro next i*, increase* {
    add QWORD [i], increase
    jmp .#i#_again
.#i#_over:
}

; Unsure if support for if statements is desired

; macro if a*, [arg] {
;    cmp DWORD [a], arg
;    jne .#a#_over
; }

; macro endif a {
; .#a#_over:
; }
