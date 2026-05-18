; =============================================
; boot_sect_segmentation.asm
; A simple boot sector that shows how segmentation
; solves the problem of not knowing where we are loaded
; =============================================

[org 0x7c00]

mov ah, 0x0e        ; teletype mode

; --------------------------------------------------
; Attempt 1: Without setting segment registers
;            This prints garbage
; --------------------------------------------------
mov al, [the_secret]
int 0x10

; --------------------------------------------------
; Attempt 2: Properly set up the segment registers
; --------------------------------------------------
mov ax, 0x0
mov ds, ax          ; DS = 0
mov es, ax          ; ES = 0 (not strictly needed for this example)
mov ss, ax          ; SS = 0 (stack segment)

mov al, [the_secret]
int 0x10            ; now this prints 'X'

jmp $

the_secret:
    db "X"

times 510-($-$$) db 0
dw 0xaa55