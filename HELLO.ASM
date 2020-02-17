assume cs:code,ds:data
data segment
message db 0dh,0ah,"hello world",0dh,0ah,"$"
data ends
code segment
start: mov ax,data
mov ds,ax
mov ah,09h
mov dx,offset message
int 21h
mov ah,4ch
int 21h
code ends
end start

