.model small
.stack 200h
.data	
.code
    
start:

   mov bh,0  
   mov dh,00h     ;��0�У�������Ϊ��
   mov dl,0h      ;��0�У����ϵ���Ϊ��
   mov ah,02h     ;����2�����趨���λ�õģ�������DH:DL����
   int 10h        ;�����޸�DH:DL��ֵ�鿴����Ч��
   
   mov ax,0h
   
   mov ah,02h     ;����ʱ�����������״̬
   int 16h
   cmp al,0h      ;�Ƚ��Ƿ���������İ���
   jnz step1
   mov ah,01h     ;�����м���ʱ�Ƿ�����ͨ������
   int 16h
   jnz step1
   jmp start      ;��û�а�ESC������������ʼ����ִ��

step1:
   cmp ax,011bh
   jz exit
    
   mov bl,ah         ;��ֹAh�����ݶ�ʧ
    
   mov ch,02h
 
s:
   push cx           ;cx��ջ
   mov ch,02h   
    
step2:               ;Ϊ�˷��㣬����AL=31H��AH=02H
   mov cl,04h
   rol al,cl         ;��ALѭ������4λ��Ҳ����AL�ĸ�4λ�͵�4λλ�õ�
    
   push ax
   and al,0fh        ;��4λ����  AL=03H
   add al,30h       
   
   cmp al,3ah        ;ASCII��3AH��ʾ:����ǰ�����0~9��ASCII��
   jb  step3         ;С��3AH���ӡ��Ҳ������������־ʹ�ӡ����0~9
   add al,07h        ;���������֣�AL=AL+7�����Ǵ�ӡA~F

step3:
   mov ah,0eh        ;�������ǰ�AL�����������ʾ����Ļ��ÿ��ʾһ��������һ��
   int 10h           ;AL=33H Ҳ������ʾ3���������һ��	
   pop ax 
    
   dec ch
   jnz step2         ;ѭ����ʾ��һλ
    
   mov al,bl         ;��ǰ�汣�浽BL��ɨ����浽AL��Ȼ���ӡ����
   pop cx
   dec ch
   jnz s
   MOV AH,0H         ;��ֹ�����ظ�
   INT 16H
   jmp start
       
 exit:   
 
 
   mov ah,4ch
   int 21h

end start
