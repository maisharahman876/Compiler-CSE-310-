.model small
.stack 100h
.data
ret_main dw ?
c1_1 dw ?
i1_1 dw ?
j1_1 dw ?
d1_1 dw ?
e1_1 dw 4 dup (?)
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

temp dw ?
.code

main proc
mov  ax, @data
mov  ds, ax
mov T0,0
mov bx,T0
inc bx
mov ax,e1_1[bx]
mov T1,ax
mov T2,2
mov bx,T0
inc bx
mov ax,T2
mov e1_1[bx],ax
mov T1,1
mov T3,1
mov bx,T3
inc bx
mov ax,e1_1[bx]
mov T4,ax
mov T5,3
mov bx,T3
inc bx
mov ax,T5
mov e1_1[bx],ax
mov T4,1
mov ax,j1_1
mov T6,ax
mov T7,1
mov bx,T7
inc bx
mov ax,e1_1[bx]
mov T8,ax
mov T9,5
mov ax,T8
cmp ax,T9
jng L0
mov T8,1
jmp L1
L0:
mov T8,0
L1:
mov ax,T8
mov j1_1,ax
mov T6,1
mov ax,c1_1
mov T10,ax
mov T11,2
mov ax,T11
mov c1_1,ax
mov T10,1
mov ax,j1_1
mov T12,ax
mov T13,2
mov T14,3
mov ax, T13
imul T14
mov T13,ax
mov T15,5
mov T16,3
mov ax,T15
and ax,T16
cmp ax,0
je L2
mov T15,1
jmp L3
L2:
mov T15,0
L3:
mov ax,T15
add T13,ax
mov T17,2
mov ax,T17
add T13,ax
mov ax,T13
mov j1_1,ax
mov T12,1
mov ax,d1_1
mov T18,ax
mov ax,i1_1
mov T19,ax
mov T20,1
mov ax,T19
cmp ax,T20
jnl L4
mov T19,1
jmp L5
L4:
mov T19,0
L5:
mov ax,T19
mov d1_1,ax
mov T18,1
mov ax,i1_1
mov T21,ax
mov ax,d1_1
mov T22,ax
mov T23,0
mov ax,T22
or ax,T23
cmp ax,0
je L6
mov T22,1
jmp L7
L6:
mov T22,0
L7:
mov ax,T22
mov i1_1,ax
mov T21,1
mov ax,d1_1
mov T24,ax
mov ax,c1_1
mov T25,ax
mov ax,d1_1
mov T26,ax
mov T27,1
mov ax,T26
cmp ax,T27
je L8
mov T26,1
jmp L9
L8:
mov T26,0
L9:
mov ax,T25
and ax,T26
cmp ax,0
je L10
mov T25,1
jmp L11
L10:
mov T25,0
L11:
mov ax,T25
mov d1_1,ax
mov T24,1
mov ax,j1_1
mov T28,ax
mov T29,50
mov ax,T29
mov j1_1,ax
mov T28,1
mov ax,j1_1
call output
mov T30,0
mov bx,T30
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