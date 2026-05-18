[org 0x7c00]

mov ah, 0x0e

; Attempt 1: low byte of the label address
mov al, the_secret
int 0x10

; Attempt 2: correct, because we have org
mov al, [the_secret]
int 0x10

; Attempt 3: adds offset again -> wrong
mov al, [the_secret + 0x7c00]
int 0x10

; Attempt 4: also wrong now
mov al, [0x2d + 0x7c00]
int 0x10

jmp $

the_secret:
    db "X"

times 510-($-$$) db 0
dw 0xaa55