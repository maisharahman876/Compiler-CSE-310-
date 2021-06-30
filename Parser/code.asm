.model small
.stack 100h
.data
x1 db ?
y1 db ?
z1 db ?
ret_var db ?
p0_var db ?
p1_var db ?
a1_1 db ?
b1_1 db ?
p0_var1 db ?
p1_var1 db ?
a1_2 db ?
b1_2 db ?
ret_main db ?
c1_4 db ?
i1_4 db ?
j1_4 db ?
d1_4 db ?
e1_4 db 4 dup (?)

.code

var proc
push ax
push bx
push cx
push dx
mov ch,p1_var
mov b1_1,ch
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
mov ah,x1_3
mov al,2
mov bl,ah
mov al,bl
mov bl,al
mov bh,bl
mov dl,bh
mov bh,1
mov x1_3,dl
mov ah,y1_3
mov ah,x1_3
mov al,ah
mov bl,al
mov al,bl
mov bl,al
mov bh,bl
mov dl,bh
mov bh,1
mov y1_3,dl
pop dx
pop cx
pop bx
pop ax
foo endp
main proc
mov  ax, @data
mov  ds, ax
mov ah,j1_4
mov al,2
mov bl,ah
mov al,bl
mov bl,al
mov bh,bl
mov bh,1
mov j1_4,dl
mov ah,d1_4
mov al,1
mov bl,ah
mov al,bl
mov bl,al
mov bh,bl
mov dl,bh
mov p0_var,dl
mov al,2
mov bl,dl
mov al,bl
mov bl,al
mov bh,bl
mov dl,bh
mov p1_var,dl
call var
mov al,ret_var
mov bl,al
mov al,bl
mov bl,al
mov bh,bl
mov dl,bh
mov bh,1
mov d1_4,dl
main endp
end main