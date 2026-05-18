; Print a null-terminated string pointed to by BX
print_string:
    pusha               ; save all registers
    mov ah, 0x0e        ; BIOS teletype function
.loop:
    mov al, [bx]        ; load next character
    cmp al, 0           ; check if it's the zero terminator
    je .done            ; if zero, we are done
    int 0x10            ; print the character
    inc bx              ; move to next character
    jmp .loop           ; repeat
.done:
    popa                ; restore all registers
    ret                 ; return from the function