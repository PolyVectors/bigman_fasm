format ELF64 executable

include 'macros/sys.inc'
include 'macros/lang.inc'

hello: db "Hello, world!", 10
hello_len = $-hello

entry _start
_start:
    SYS_write STDOUT_FILENO, hello, hello_len
    SYS_exit 0
