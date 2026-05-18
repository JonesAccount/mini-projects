[org 0x7c00]

    mov [BOOT_DRIVE], dl

    ; clear segment registers
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00

    ; switch to 32-bit protected mode
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:init_32bit

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

; ---------- 32-bit code ----------
[bits 32]
init_32bit:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov esp, 0x90000

    ; clear screen
    mov edi, 0xb8000
    mov ecx, 2000
    mov ax, 0x0f20
    rep stosw

    ; print "32-bit mode entered!"
    mov esi, msg
    mov edi, 0xb8000 + (12*80 + 32)*2   ; center
    mov ah, 0x0f
.loop:
    lodsb
    cmp al, 0
    je .done
    mov [edi], ax
    add edi, 2
    jmp .loop
.done:
    jmp $

; ---------- Data ----------
msg db "32-bit mode entered!", 0
BOOT_DRIVE db 0

; Padding and magic number
times 510-($-$$) db 0
dw 0xaa55