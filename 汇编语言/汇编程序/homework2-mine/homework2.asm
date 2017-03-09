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
    data db '%d', 0 

.code

start:
    invoke crt_scanf, addr data, addr n
    invoke crt_printf, addr data, a
    invoke crt_printf, addr vac
    invoke crt_printf, addr data, b
    invoke crt_printf, addr vac
beginwhile:
    mov ecx, i
    mov edx, n
    sub edx, 1
    cmp ecx, edx
    jnle endwhile

    mov ebx, b
    mov t, ebx
    mov eax, a
    add ebx, eax
    mov b, ebx
    invoke crt_printf, addr data, b
    invoke crt_printf, addr vac
    mov eax, t
    mov a, eax
    inc i
    
    jmp beginwhile
endwhile:
    ret
end start  