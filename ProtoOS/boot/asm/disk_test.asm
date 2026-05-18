[org 0x8000]

start:
    mov bx, LOADED_MSG
    mov ah, 0x0e
.next_char:
    mov al, [bx]
    cmp al, 0
    je .done
    int 0x10
    inc bx
    jmp .next_char
.done:
    jmp $

LOADED_MSG db "Second sector loaded successfully!", 0

times 512 db 0