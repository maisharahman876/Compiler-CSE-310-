.model small
.stack 100h
.data
x1 dw ?
y1 dw ?
z1 dw ?
ret_var dw ?
p0_var dw ?
p1_var dw ?
a1_1 dw ?
b1_1 dw ?
p0_var1 dw ?
p1_var1 dw ?
a1_2 dw ?
b1_2 dw ?
ret_main dw ?
c1_4 dw ?
i1_4 dw ?
j1_4 dw ?
d1_4 dw ?
e1_4 dw 4 dup (?)

temp dw ?
.code

var proc
push ax
push bx
push cx
push dx
mov ch,p0_var
mov a1_1,ch
mov ch,p1_var
mov b1_1,ch
mov ah,a1_1
mov al,ah
mov bl,al
mov cl,bl
mov bl,cl
mov ah,b1_1
mov al,ah
mov bl,al
mov cl,bl
add bl,cl
mov bh,bl
mov dl,bh
mov bh,dl
mov ret_var,bh
pop dx
pop cx
pop bx
pop ax
var endp
var1 proc
push ax
push bx
push cx
push dx
mov ch,p0_var1
mov a1_2,ch
mov ch,p1_var1
mov b1_2,ch
pop dx
pop cx
pop bx
pop ax
var1 endp
foo proc
push ax
push bx
push cx
push dx
mov ah,x1
mov al,2
mov bl,al
mov cl,bl
mov bl,cl
mov bh,bl
mov dl,bh
mov bh,1
mov x1,dl
mov ah,y1
mov ah,x1
mov al,ah
mov bl,al
mov cl,bl
mov bl,cl
mov al,5
mov bl,al
mov cl,bl
sub bl,cl
mov bh,bl
mov dl,bh
mov bh,1
mov y1,dl
pop dx
pop cx
pop bx
pop ax
foo endp
main proc
mov  ax, @data
mov  ds, ax
mov ah,c1_4
mov al,2
mov bl,al
mov cl,bl
mov bl,cl
mov bh,bl
mov dl,bh
mov bh,1
mov c1_4,dl
mov ah,j1_4
mov al,2
mov bl,al
mov cl,bl
mov al,3
mov bl,al
mov temp,ax
mov al,cl
imul bl
mov cl,al
mov ax,temp
mov bl,cl
mov al,5
mov bl,al
mov cl,bl
mov al,3
mov bl,al
mov temp,ax
mov al,cl
cbw 
idiv bl
mov cl,ah
mov ax,temp
mov bl,cl
mov bh,bl
mov dl,bh
mov bh,dl
mov al,bh
mov bl,al
mov cl,bl
add bl,cl
mov al,2
mov bl,al
mov cl,bl
add bl,cl
mov bh,bl
mov dl,bh
mov bh,1
mov j1_4,dl
mov ah,i1_4
mov ah,c1_4
mov al,ah
mov bl,al
mov cl,bl
mov bl,cl
mov al,2
mov bl,al
mov cl,bl
add bl,cl
mov bh,bl
mov dl,bh
mov bh,1
mov i1_4,dl
mov ah,d1_4
mov al,1
mov bl,al
mov cl,bl
mov bl,cl
mov bh,bl
mov dl,bh
mov p0_var,dl
mov al,2
mov bl,al
mov cl,bl
mov al,3
mov bl,al
mov temp,ax
mov al,cl
imul bl
mov cl,al
mov ax,temp
mov bl,cl
mov bh,bl
mov dl,bh
mov p1_var,dl
call var
mov al,ret_var
mov bl,al
mov cl,bl
mov bl,cl
mov al,3
mov bl,al
mov cl,bl
mov al,2
mov bl,al
mov temp,ax
mov al,cl
imul bl
mov cl,al
mov ax,temp
add bl,cl
mov bh,bl
mov dl,bh
mov bh,1
mov d1_4,dl
mov al,0
mov bl,al
mov cl,bl
mov bl,cl
mov bh,bl
mov dl,bh
mov bh,dl
mov ret_main,bh
mov ah,4ch
int 21h
main endp
output proc
xor cx,cx 
 ;count=0 and dx=0
xor dx,dx
cmp ax,0
je printt 
begin1:
cmp ax,0
; if ax is zero
je repeat1
mov bx,10 ; extract the last digit and push it to stack
div bx
push dx
inc cx  
;count++             
xor dx,dx   
; dx=0
jmp begin1
repeat1: 
cmp cx,0 
;check if count>0 
je return
pop dx   
;pop the top of stack
add dx,48 
;print the digit 
mov ah,2 
int 21h  
dec cx       
;count--
jmp repeat1 
return:
ret 
printt:
mov dx,48
mov ah,2
int 21h
jmp return
output endp
end main