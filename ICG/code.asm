.model small
.stack 100h
.data
a1 dw ?
b1 dw ?
c1 dw ?
T0 dw ?
T1 dw ?
ret_foo dw ?
p0_foo dw ?
a1_2 dw ?
T2 dw ?
T3 dw ?
T4 dw ?
T5 dw ?
ret_bar dw ?
p0_bar dw ?
p1_bar dw ?
a1_3 dw ?
b1_3 dw ?
c1_3 dw ?
T6 dw ?
T7 dw ?
T8 dw ?
T9 dw ?
T10 dw ?
T11 dw ?
ret_main dw ?
i1_4 dw ?
j1_4 dw ?
k1_4 dw ?
l1_4 dw ?
T12 dw ?
T13 dw ?
T14 dw ?
T15 dw ?
T16 dw ?
T17 dw ?
T18 dw ?
T19 dw ?
T20 dw ?
T21 dw ?
T22 dw ?
T23 dw ?
T24 dw ?
T25 dw ?
T26 dw ?
T27 dw ?
T28 dw ?
T29 dw ?
T30 dw ?
T31 dw ?
T32 dw ?
T33 dw ?

.code

func_a proc
push ax
push bx
push cx
push dx

;a=7;


mov ax , a1
mov T0 , ax
mov T1 , 7
mov ax , T1
mov a1 , ax
mov T0 , 1
pop dx
pop cx
pop bx
pop ax
ret
func_a endp
foo proc
push ax
push bx
push cx
push dx
mov cx , p0_foo
mov a1_2 , cx

;a=a+3;


mov ax , a1_2
mov T2 , ax
mov ax , a1_2
mov T3 , ax
mov T4 , 3
mov ax , T4
add T3 , ax
mov ax , T3
mov a1_2 , ax
mov T2 , 1
mov ax , a1_2
mov T5 , ax
mov bx , T5
mov ret_foo , bx
pop dx
pop cx
pop bx
pop ax
ret
foo endp
bar proc
push ax
push bx
push cx
push dx
mov cx , p0_bar
mov a1_3 , cx
mov cx , p1_bar
mov b1_3 , cx

;c=4*a+2*b;


mov ax , c1_3
mov T6 , ax
mov T7 , 4
mov ax , a1_3
mov T8 , ax
mov ax ,  T7
imul T8
mov T7 , ax
mov T9 , 2
mov ax , b1_3
mov T10 , ax
mov ax ,  T9
imul T10
mov T9 , ax
mov ax , T9
add T7 , ax
mov ax , T7
mov c1_3 , ax
mov T6 , 1
mov ax , c1_3
mov T11 , ax
mov bx , T11
mov ret_bar , bx
pop dx
pop cx
pop bx
pop ax
ret
bar endp
main proc
mov  ax , @data
mov  ds , ax

;i=5;


mov ax , i1_4
mov T12 , ax
mov T13 , 5
mov ax , T13
mov i1_4 , ax
mov T12 , 1

;j=6;


mov ax , j1_4
mov T14 , ax
mov T15 , 6
mov ax , T15
mov j1_4 , ax
mov T14 , 1

;func_a();


call func_a
mov ax , ret_func_a
mov T16 , ax
mov ax , a1
mov bx,8000h
and bx,ax
jz L0
neg ax
mov a1,ax
mov ah,2
mov dl,'-'
int 21h
L0:
mov bx,a1
mov ax,bx
call output
mov ah,2
mov dl,0dh
int 21h
mov dl,0ah
int 21h

;k=foo(i);


mov ax , k1_4
mov T17 , ax
mov ax , i1_4
mov T18 , ax
mov ax , T18
mov p0_foo , ax
call foo
mov ax , ret_foo
mov T19 , ax
mov ax , T19
mov k1_4 , ax
mov T17 , 1
mov ax , k1_4
mov bx,8000h
and bx,ax
jz L1
neg ax
mov k1_4,ax
mov ah,2
mov dl,'-'
int 21h
L1:
mov bx,k1_4
mov ax,bx
call output
mov ah,2
mov dl,0dh
int 21h
mov dl,0ah
int 21h

;l=bar(i,j);


mov ax , l1_4
mov T20 , ax
mov ax , i1_4
mov T21 , ax
mov ax , T21
mov p0_bar , ax
mov ax , j1_4
mov T22 , ax
mov ax , T22
mov p1_bar , ax
call bar
mov ax , ret_bar
mov T23 , ax
mov ax , T23
mov l1_4 , ax
mov T20 , 1
mov ax , l1_4
mov bx,8000h
and bx,ax
jz L2
neg ax
mov l1_4,ax
mov ah,2
mov dl,'-'
int 21h
L2:
mov bx,l1_4
mov ax,bx
call output
mov ah,2
mov dl,0dh
int 21h
mov dl,0ah
int 21h

;j=6*bar(i,j)+2-3*foo(i);


mov ax , j1_4
mov T24 , ax
mov T25 , 6
mov ax , i1_4
mov T26 , ax
mov ax , T26
mov p0_bar , ax
mov ax , j1_4
mov T27 , ax
mov ax , T27
mov p1_bar , ax
call bar
mov ax , ret_bar
mov T28 , ax
mov ax ,  T25
imul T28
mov T25 , ax
mov T29 , 2
mov ax , T29
add T25 , ax
mov T30 , 3
mov ax , i1_4
mov T31 , ax
mov ax , T31
mov p0_foo , ax
call foo
mov ax , ret_foo
mov T32 , ax
mov ax ,  T30
imul T32
mov T30 , ax
mov ax , T30
sub T25 , ax
mov ax , T25
mov j1_4 , ax
mov T24 , 1
mov ax , j1_4
mov bx,8000h
and bx,ax
jz L3
neg ax
mov j1_4,ax
mov ah,2
mov dl,'-'
int 21h
L3:
mov bx,j1_4
mov ax,bx
call output
mov ah,2
mov dl,0dh
int 21h
mov dl,0ah
int 21h
mov T33 , 0
mov bx , T33
mov ret_main , bx
mov ah , 4ch
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