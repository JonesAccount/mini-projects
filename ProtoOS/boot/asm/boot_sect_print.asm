; Tell the assembler we are in 16‑bit mode and will be loaded at address 0x7c00
org 0x7c00
bits 16

start:
    ; Set all segment registers to 0 (BIOS may have loaded us with different values)
    cli                     ; disable interrupts
    mov ax, 0x00
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00          ; stack grows down from 0x7c00 (safe)
    sti                     ; enable interrupts again

    ; Put the address of our message into the SI register
    mov si, msg
    ; Call the function that prints the string
    call print_string

    ; Infinite loop – stop here
    jmp $

; ----------------------------------------------------------
; print_string – prints characters until a 0 byte is found
; Expects: SI points to a null‑terminated string
; ----------------------------------------------------------
print_string:
    lodsb                   ; load next byte from [SI] into AL, then SI = SI + 1
    or al, al               ; is AL = 0 ? (end of string)
    jz .done                ; if yes, we are done
    mov ah, 0x0e            ; BIOS teletype function (print character)
    int 0x10                ; call BIOS video interrupt
    jmp print_string        ; repeat for next character
.done:
    ret

; Our message (null‑terminated string)
msg db "Hello from Kazakhstaniwest boot sector!", 0

; Pad the rest of the 512‑byte sector with zeros and add the magic number
times 510-($-$$) db 0
dw 0xaa55