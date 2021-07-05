.model small
.stack 100h
.data
ret_main dw ?
a1_1 dw ?
b1_1 dw ?
c1_1 dw ?
i1_1 dw ?
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

.code

main proc
mov  ax , @data
mov  ds , ax

;b=0;


mov ax , b1_1
mov T0 , ax
mov T1 , 0
mov ax , T1
mov b1_1 , ax
mov T0 , 1

;c=1;


mov ax , c1_1
mov T2 , ax
mov T3 , 1
mov ax , T3
mov c1_1 , ax
mov T2 , 1

;i=0;


mov ax , i1_1
mov T4 , ax
mov T5 , 0
mov ax , T5
mov i1_1 , ax
mov T4 , 1
L4:


;i<4;


mov ax , i1_1
mov T6 , ax
mov T7 , 4
mov ax , T6
cmp ax , T7
jnl L0
mov T6,1
jmp L1
L0:
mov T6 , 0
L1:
cmp T6,1
jnge L5

;a=3;


mov ax , a1_1
mov T9 , ax
mov T10 , 3
mov ax , T10
mov a1_1 , ax
mov T9 , 1
L2:
mov ax , a1_1
mov T11 , ax
dec T11
dec a1_1
cmp T11,1
jnge L3


;b++;


mov ax , b1_1
mov T12 , ax
inc T12
inc b1_1
jmp L2
L3:
mov ax , i1_1
mov T8 , ax
inc T8
inc i1_1
jmp L4
L5:
mov ax , a1_1
call output
mov ax , b1_1
call output
mov ax , c1_1
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