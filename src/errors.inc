_no_arguments: db "error: no arguments provided, use bigman -h for help.", 0
_too_many_arguments: db "error: too many arguments provided, use bigman -h for help.", 0
_no_file: db "error: the file specified does not exist, use bigman -h for help.", 0

no_arguments:
    mov rdi, STDERR_FILENO
    mov rsi, _no_arguments

    call fprintln
    sys_exit ERROR
too_many_arguments:
    mov rdi, STDERR_FILENO
    mov rsi, _too_many_arguments

    call fprintln
    sys_exit ERROR
no_file:
    mov rdi, STDERR_FILENO
    mov rsi, _no_file

    call fprintln
    sys_exit ERROR
