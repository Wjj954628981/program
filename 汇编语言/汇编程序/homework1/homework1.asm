.386
.model flat, stdcall

include \masm32\include\msvcrt.inc

includelib \masm32\lib\msvcrt.lib

.data
    input db "%d", 0
    print db "%d", 13, 0
    n dd ?
    f dd ?

.code

start:
    invoke crt_scanf, addr input, addr n
    mov ecx, n
    mov eax, 2
    mov ebx, 1

beginwhile:
    cmp eax, ecx
    jnle endwhile
        imul ebx, eax
        add eax, 1
    jmp beginwhile
endwhile:

    mov f, ebx
    invoke crt_printf, addr print, f
    ret
end start  