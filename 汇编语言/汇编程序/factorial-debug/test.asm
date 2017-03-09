; test.asm
 
comment * ----------------------------------------------
                 The First Assemble Application
                ---------------------------------------------- *
 
    .386
    .model flat, stdcall
    option casemap:none
 
include \masm32\include\windows.inc

include \masm32\include\user32.inc
include \masm32\include\debug.inc
include \masm32\include\kernel32.inc

includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\debug.lib
 
.data
    i dd 2
    f dd 1
    n dd 5
.code
main proc
    mov ecx, i
    mov eax, f
    mov edx, n
    .while ecx<=edx 
        imul eax, ecx
        inc ecx
    .endw
    PrintDec eax
    ret
main endp
end main