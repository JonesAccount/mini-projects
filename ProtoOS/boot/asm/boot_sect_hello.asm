mov ah, 0x0e      ; function: print one character
mov al, 'H'       ; letter H
int 0x10          ; call BIOS

mov al, 'e'
int 0x10

mov al, 'l'
int 0x10
int 0x10          ; another 'l'

mov al, 'o'
int 0x10

jmp $             ; stop forever

times 510-($-$$) db 0
dw 0xaa55