format ELF64 executable

include 'macros/io.inc'
include 'macros/os.inc'
include 'macros/lang.inc'

hello: db "Hello, world!", 10
hello_len = $-hello

print:
    write STDOUT_FILENO, hello, hello_len
    ret

entry _start
_start:
    call print
    exit 0
