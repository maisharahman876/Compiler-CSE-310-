.model small
.stack 100h
.data
ret_main dw ?
a1_1 dw ?
b1_1 dw ?
c1_1 dw 3 dup (?)
T0 dw ?
T1 dw ?
T2 dw ?
T3 dw ?
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

.code

main proc
mov  ax , @data
mov  ds , ax

;a=1*(2+3)%3;


mov ax , a1_1
mov T0 , ax
mov T1 , 1
mov T2 , 2
mov T3 , 3
mov ax , T3
add T2 , ax
mov ax ,  T1
imul T2
mov T1 , ax
mov T4 , 3
mov ax ,  T1
cwd
idiv T4
mov T1 , dx
mov ax , T1
mov a1_1 , ax
mov T0 , 1

;b=1<5;


mov ax , b1_1
mov T5 , ax
mov T6 , 1
mov T7 , 5
mov ax , T6
cmp ax , T7
jnl L0
mov T6,1
jmp L1
L0:
mov T6 , 0
L1:
mov ax , T6
mov b1_1 , ax
mov T5 , 1

;c[0]=2;


mov T8 , 0
mov bx , T8
sal bx , 2
inc bx
mov ax , c1_1[bx]
mov T9 , ax
mov T10 , 2
mov bx , T8
sal bx , 2
inc bx
mov ax , T10
mov c1_1[bx] , ax
mov T9 , 1
mov ax , a1_1
mov T11 , ax
mov ax , b1_1
mov T12 , ax
mov ax , T11
or ax , T12
cmp ax , 0
je L2
mov T11 , 1
jmp L3
L2:
mov T11 , 0
L3:
cmp T11,1
jne L4

;c[0]++;


mov T13 , 0
mov bx , T13
sal bx , 2
inc bx
mov ax , c1_1[bx]
mov T14 , ax
inc T14
inc c1_1
L4:

;c[1]=c[0];


mov T15 , 1
mov bx , T15
sal bx , 2
inc bx
mov ax , c1_1[bx]
mov T16 , ax
mov T17 , 0
mov bx , T17
sal bx , 2
inc bx
mov ax , c1_1[bx]
mov T18 , ax
mov bx , T17
sal bx , 2
inc bx
mov ax , T18
mov c1_1[bx] , ax
mov T16 , 1
mov ax , a1_1
call output
mov ax , b1_1
call output
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