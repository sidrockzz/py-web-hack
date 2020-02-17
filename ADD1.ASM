assume cs:code,ds:data
data segment
num1 dw 0a53h
num2 dw 5467h
result dw 1 dup(?)
data ends
code segment
start: mov ax,data
mov ds,ax
mov ax,num1
mov bx,num2
clc
add ax,bx
mov di,offset result
mov [di],ax
mov ah,4ch
int 21h
code ends
end start
