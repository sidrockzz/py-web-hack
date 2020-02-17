assume cs:code,ds:data
data segment
num1 db 53h
num2 db 0ah
result db 1 dup(?)
data ends
code segment
start: mov ax,data
mov ds,ax
mov al,num1
mov bl,num2
clc
add al,bl
mov di,offset result
mov [di],al
mov ah,4ch
int 21h
code ends
end start
