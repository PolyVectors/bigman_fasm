include 'src/macros/io.inc'
include 'src/macros/sys.inc'

_no_arguments_provided: db "error: no arguments provided, use bigman -h for help.", 0
_too_many_arguments_provided: db "error: too many arguments provided, use bigman -h for help.", 0

no_arguments_provided:
    fprintln STDERR_FILENO, _no_arguments_provided
    sys_exit ERROR
too_many_arguments_provided:
    fprintln STDERR_FILENO, _too_many_arguments_provided
    sys_exit ERROR
