; HelloWorld.asm
 
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
szText db 'Hello World!', 0
 
    .code
start:
    PrintString szText  ;Hello World!
    ret
end start