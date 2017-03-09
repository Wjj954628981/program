.386
.model flat, stdcall

include \masm32\include\msvcrt.inc

includelib \masm32\lib\msvcrt.lib

.data
	data1 db '%d', 0 
	a dd ?
	b dd ?
	i dd ?
	t dd ?
	n dd ?
.code
start:
	mov eax,0
	mov a,eax
	mov eax,1
	mov b,eax
	mov eax,1
	mov i,eax
	invoke crt_scanf, addr data1, addr n
	invoke crt_printf, addr data1, a
	invoke crt_printf, addr data1, b
@0:
	mov eax,i
	cmp eax,n
	jl @1
	jmp @2
@1:
	mov eax,b
	mov t,eax
	mov eax,a
	add eax,b
	mov b,eax
	invoke crt_printf, addr data1, b
	mov eax,t
	mov a,eax
	mov eax,i
	add eax,1
	mov i,eax
	jmp @0
@2:
ret
end start 
