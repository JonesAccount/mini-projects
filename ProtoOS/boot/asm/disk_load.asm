; disk_load.asm
; Load DH sectors to memory at ES:BX from drive DL
; ES:BX = destination address
; DH = number of sectors to read
; DL = drive number (BIOS sets it to 0 for floppy, 0x80 for hard disk – keep as-is)
disk_load:
    push dx             ; save DH (number of sectors)
    
    mov ah, 0x02        ; BIOS read sector function
    mov al, dh          ; number of sectors to read
    mov ch, 0x00        ; cylinder 0
    mov dh, 0x00        ; head 0
    mov cl, 0x02        ; start from sector 2 (just after boot sector)
    int 0x13            ; call BIOS disk interrupt
    
    jc disk_error       ; if carry flag set, error occurred
    
    pop dx              ; restore DH
    cmp dh, al          ; check if BIOS read the expected number of sectors
    jne disk_error      ; if not, error
    ret

disk_error:
    mov bx, DISK_ERROR_MSG
    call print_string   ; print error message (must have print_string included)
    jmp $

DISK_ERROR_MSG db "Disk read error!", 0