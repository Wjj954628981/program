.model small
.stack 200h
.data	
.code
    
start:

   mov bh,0  
   mov dh,00h     ;第0列，从左到右为列
   mov dl,0h      ;第0行，从上到下为行
   mov ah,02h     ;下面2句是设定光标位置的，参数由DH:DL决定
   int 10h        ;可以修改DH:DL的值查看光标的效果
   
   mov ax,0h
   
   mov ah,02h     ;检测此时键盘特殊键的状态
   int 16h
   cmp al,0h      ;比较是否有特殊键的按下
   jnz step1
   mov ah,01h     ;这两行监测此时是否有普通键按下
   int 16h
   jnz step1
   jmp start      ;若没有按ESC键，则跳到开始重新执行

step1:
   cmp ax,011bh
   jz exit
    
   mov bl,ah         ;防止Ah的数据丢失
    
   mov ch,02h
 
s:
   push cx           ;cx入栈
   mov ch,02h   
    
step2:               ;为了方便，假设AL=31H，AH=02H
   mov cl,04h
   rol al,cl         ;把AL循环左移4位，也就是AL的高4位和低4位位置调
    
   push ax
   and al,0fh        ;高4位清零  AL=03H
   add al,30h       
   
   cmp al,3ah        ;ASCII码3AH表示:，它前面的是0~9的ASCII码
   jb  step3         ;小于3AH则打印，也就是如果是数字就打印数字0~9
   add al,07h        ;若不是数字，AL=AL+7，就是打印A~F

step3:
   mov ah,0eh        ;这两句是把AL里面的数据显示到屏幕，每显示一个字右移一格
   int 10h           ;AL=33H 也就是显示3，光标右移一格	
   pop ax 
    
   dec ch
   jnz step2         ;循环显示下一位
    
   mov al,bl         ;把前面保存到BL的扫描码存到AL，然后打印出来
   pop cx
   dec ch
   jnz s
   MOV AH,0H         ;防止不断重复
   INT 16H
   jmp start
       
 exit:   
 
 
   mov ah,4ch
   int 21h

end start
