.386
.model flat, stdcall

include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib

.data
    szText db 'Hello World!', 0

.code
start:
    invoke crt_printf, addr szText
    ret
end start