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
temp1_2_1 dw ?
T19 dw ?
T20 dw ?
T21 dw ?
T22 dw ?
T23 dw ?

.code

max proc
push ax
push bx
push cx
push dx
mov cx,p0_max
mov a1_1,cx
mov cx,p1_max
mov b1_1,cx
mov ax,a1_1
mov T0,ax
mov ax,b1_1
mov T1,ax
mov ax,T0
cmp ax,T1
jl L0
mov T0,1
jmp L1
L0:
mov T0,0
L1:
cmp T0,1
jne L2
mov ax,a1_1
mov T2,ax
mov bx,T2
mov ret_max,bx
L2:
mov ax,b1_1
mov T3,ax
mov bx,T3
mov ret_max,bx
pop dx
pop cx
pop bx
pop ax
ret
max endp
main proc
mov  ax, @data
mov  ds, ax

;d=4;


mov ax,d1_2
mov T4,ax
mov T5,4
mov ax,T5
mov d1_2,ax
mov T4,1

;i=0;


mov ax,i1_2
mov T6,ax
mov T7,0
mov ax,T7
mov i1_2,ax
mov T6,1
L5:


;i<d;


mov ax,i1_2
mov T8,ax
mov ax,d1_2
mov T9,ax
mov ax,T8
cmp ax,T9
jnl L3
mov T8,1
jmp L4
L3:
mov T8,0
L4:
cmp T8,1
jne L6

;e[i]=i*2;


mov ax,i1_2
mov T11,ax
mov bx,T11
sal bx,2
inc bx
mov ax,e1_2[bx]
mov T12,ax
mov ax,i1_2
mov T13,ax
mov T14,2
mov ax, T13
imul T14
mov T13,ax
mov bx,T11
sal bx,2
inc bx
mov ax,T13
mov e1_2[bx],ax
mov T12,1
mov ax,i1_2
mov T10,ax
inc T10
inc i1_2
jmp L5
L6:

;j=0;


mov ax,j1_2
mov T15,ax
mov T16,0
mov ax,T16
mov j1_2,ax
mov T15,1
L9:
mov ax,d1_2
mov T17,ax
mov ax,j1_2
mov T18,ax
mov ax,T17
cmp ax,T18
jng L7
mov T17,1
jmp L8
L7:
mov T17,0
L8:
cmp T17,1
jne L10


;d--;


mov ax,d1_2
mov T19,ax
dec T19
dec d1_2

;temp=e[d];


mov ax,temp1_2_1
mov T20,ax
mov ax,d1_2
mov T21,ax
mov bx,T21
sal bx,2
inc bx
mov ax,e1_2[bx]
mov T22,ax
mov ax,T22
mov temp1_2_1,ax
mov T20,1
mov ax,temp1_2_1
call output
jmp L9
L10:
mov T23,0
mov bx,T23
mov ret_main,bx
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