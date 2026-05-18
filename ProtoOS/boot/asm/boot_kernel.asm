[org 0x7c00]
    ; Save boot drive
    mov [BOOT_DRIVE], dl

    ; Set up stack (real mode)
    mov bp, 0x9000
    mov sp, bp

    ; Print a message so we know the boot sector started
    mov bx, MSG_REAL_MODE
    call print_string_16

    ; Load kernel (15 sectors) from disk
    mov bx, KERNEL_OFFSET       ; address to load at (0x1000)
    mov dh, 15                  ; number of sectors to read
    mov dl, [BOOT_DRIVE]
    call disk_load

    ; Switch to 32-bit protected mode
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:init_pm

[bits 16]
disk_load:
    push dx
    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02            ; sector 2
    int 0x13
    jc disk_error
    pop dx
    cmp al, dh
    jne disk_error
    ret

disk_error:
    mov bx, DISK_ERROR_MSG
    call print_string_16
    jmp $

print_string_16:
    pusha
    mov ah, 0x0e
.loop:
    mov al, [bx]
    cmp al, 0
    je .done
    int 0x10
    inc bx
    jmp .loop
.done:
    popa
    ret

; ---------- GDT ----------
gdt_start:
gdt_null:
    dd 0, 0
gdt_code:
    dw 0xffff
    dw 0
    db 0
    db 10011010b
    db 11001111b
    db 0
gdt_data:
    dw 0xffff
    dw 0
    db 0
    db 10010010b
    db 11001111b
    db 0
gdt_end:
gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

[bits 32]
init_pm:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov esp, 0x90000

    ; Jump to the loaded kernel
    call KERNEL_OFFSET

    jmp $

; ---------- Data ----------
KERNEL_OFFSET equ 0x1000
BOOT_DRIVE db 0
DISK_ERROR_MSG db "Disk read error!", 0
MSG_REAL_MODE db "Booting kernel...", 0

times 510-($-$$) db 0
dw 0xaa55