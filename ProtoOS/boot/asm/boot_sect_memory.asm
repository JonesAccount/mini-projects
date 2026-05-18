; This code tries to print an 'X' stored at label "the_secret"
; using four different methods. Only methods 3 and 4 will work
; because they account for the BIOS load address 0x7C00.

mov ah, 0x0e              ; BIOS teletype function

; Attempt 1: move the address itself (will print the low byte of address)
mov al, the_secret
int 0x10

; Attempt 2: try to read the byte at the_secret – but without offset 0x7C00
mov al, [the_secret]
int 0x10

; Attempt 3: manually add the offset 0x7C00 -> this works!
mov al, [the_secret + 0x7C00]
int 0x10

; Attempt 4: use the absolute byte offset (0x2d) + 0x7C00 -> also works
; (If you add or remove instructions, 0x2d may change! Count bytes from start of file to 'X'.)
mov al, [0x2d + 0x7C00]
int 0x10

jmp $                     ; hang forever

the_secret:
    db "X"

times 510-($-$$) db 0
dw 0xaa55