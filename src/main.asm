format ELF64 executable

include 'macros/io.inc'
include 'macros/os.inc'
include 'macros/lang.inc'

hello: db "Hello, world!", 10
hello_len = $-hello

entry _start
_start:
    write STDOUT_FILENO, hello, hello_len
    exit 0
