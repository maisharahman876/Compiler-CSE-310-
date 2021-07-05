.model small
.stack 100h
.data
ret_max dw ?
p0_max dw ?
p1_max dw ?
a1_1 dw ?
b1_1 dw ?
T0 dw ?
T1 dw ?
T2 dw ?
T3 dw ?
ret_main dw ?
a1_2 dw ?
c1_2 dw ?
i1_2 dw ?
j1_2 dw ?
d1_2 dw ?
e1_2 dw 4 dup (?)
T4 dw ?
T5 dw ?
T6 dw ?
T7 dw ?
T8 dw ?
T9 dw ?
T10 dw ?
T11 dw ?
T12 dw ?
T13 dw ?
T14 dw ?
T15 dw ?
T16 dw ?
T17 dw ?
T18 dw ?
T19 dw ?
T20 dw ?
temp1_2_1 dw ?
T21 dw ?
T22 dw ?
T23 dw ?
T24 dw ?
T25 dw ?

.code

max proc
push ax
push bx
push cx
push dx
mov cx , p0_max
mov a1_1 , cx
mov cx , p1_max
mov b1_1 , cx
mov ax , a1_1
mov T0 , ax
mov ax , b1_1
mov T1 , ax
mov ax , T0
cmp ax , T1
jl L0
mov T0 , 1
jmp L1
L0:
mov T0 , 0
L1:
cmp T0,1
jne L2
mov ax , a1_1
mov T2 , ax
mov bx , T2
mov ret_max , bx
L2:
mov ax , b1_1
mov T3 , ax
mov bx , T3
mov ret_max , bx
pop dx
pop cx
pop bx
pop ax
ret
max endp
main proc
mov  ax , @data
mov  ds , ax

;j=i;


mov ax , j1_2
mov T4 , ax
mov ax , i1_2
mov T5 , ax
mov ax , T5
mov j1_2 , ax
mov T4 , 1

;d=4;


mov ax , d1_2
mov T6 , ax
mov T7 , 4
mov ax , T7
mov d1_2 , ax
mov T6 , 1

;i=0;


mov ax , i1_2
mov T8 , ax
mov T9 , 0
mov ax , T9
mov i1_2 , ax
mov T8 , 1
L5:


;i<d;


mov ax , i1_2
mov T10 , ax
mov ax , d1_2
mov T11 , ax
mov ax , T10
cmp ax , T11
jnl L3
mov T10,1
jmp L4
L3:
mov T10 , 0
L4:
cmp T10,1
jne L6

;e[i]=i*2;


mov ax , i1_2
mov T13 , ax
mov bx , T13
sal bx , 2
inc bx
mov ax , e1_2[bx]
mov T14 , ax
mov ax , i1_2
mov T15 , ax
mov T16 , 2
mov ax ,  T15
imul T16
mov T15 , ax
mov bx , T13
sal bx , 2
inc bx
mov ax , T15
mov e1_2[bx] , ax
mov T14 , 1
mov ax , i1_2
mov T12 , ax
inc T12
inc i1_2
jmp L5
L6:

;j=0;


mov ax , j1_2
mov T17 , ax
mov T18 , 0
mov ax , T18
mov j1_2 , ax
mov T17 , 1
L9:
mov ax , d1_2
mov T19 , ax
mov ax , j1_2
mov T20 , ax
mov ax , T19
cmp ax , T20
jng L7
mov T19 , 1
jmp L8
L7:
mov T19 , 0
L8:
cmp T19,1
jne L10


;d--;


mov ax , d1_2
mov T21 , ax
dec T21
dec d1_2

;temp=e[d];


mov ax , temp1_2_1
mov T22 , ax
mov ax , d1_2
mov T23 , ax
mov bx , T23
sal bx , 2
inc bx
mov ax , e1_2[bx]
mov T24 , ax
mov ax , T24
mov temp1_2_1 , ax
mov T22 , 1
mov ax , temp1_2_1
call output
jmp L9
L10:
mov T25 , 0
mov bx , T25
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