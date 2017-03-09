assume cs:code 
code segment
start:
mov ax,0h

mov ah,02h    
int 16h

cmp al,0h    
jnz step0

mov ah,01h    
int 16h
jnz step0

jmp start    

step0:
   cmp ax,011bh
   jz exit

step1:
   mov bx,ax
   call step3
   mov dl,0dh
   mov ah,02h
   int 21

step2:
   mov bx,ax
   call step3

step3:mov ch,4
   rotate:mov cl,4
         rol bx,cl
         mov al,bl
         and al,0fh
         add al,30h
         cmp al,3ah
         jb print
         add al,7h
         jmp print
         dec ch
         jnz rotate
   ret

print:
   mov dl,al
   mov ah,2
   int 21h   
  
exit:
   mov ah,4ch
   int 21

code ends
end start
