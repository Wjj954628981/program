.386
.model flat, stdcall

include \masm32\include\msvcrt.inc

includelib \masm32\lib\msvcrt.lib

.data
    a dd 0
    b dd 1
    i dd 1
    t dd ?
    n dd ?
    vac db ' ', 0
    input db 'please input the number of the sequence:', 0
    output db 'the Fibonacci sequence is:', 0
    data1 db '%d', 0 

.code

start:
    invoke crt_printf, addr input
    invoke crt_scanf, addr data1, addr n
    invoke crt_printf, addr output
    invoke crt_printf, addr data1, a
    invoke crt_printf, addr vac
    invoke crt_printf, addr data1, b
    invoke crt_printf, addr vac
    mov ecx, i
    cmp ecx, n
    jl again

again:
    mov ebx, b
    mov t, ebx
    mov eax, a
    add ebx, eax
    mov b, ebx
    invoke crt_printf, addr data1, b
    invoke crt_printf, addr vac
    mov eax, t
    mov a, eax
    inc i
    mov ecx, i
    cmp ecx, n
    jl again
ret
end start  