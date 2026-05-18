[org 0x7c00]            ; BIOS loads us here

mov bx, HELLO_MSG       ; put address of first message into BX
call print_string       ; call our function

mov bx, GOODBYE_MSG     ; address of second message
call print_string

jmp $                   ; hang forever

%include "asm/print_string.asm"

; Data
HELLO_MSG:
    db 'Hello, World!', 0
GOODBYE_MSG:
    db 'Goodbye!', 0

; Padding and magic number
times 510-($-$$) db 0
dw 0xaa55