[org 0x7c00]
    mov [BOOT_DRIVE], dl

    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00

    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:init_pm

[bits 32]
init_pm:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov esp, 0x90000

    mov edi, 0xb8000
    mov ecx, 2000
    mov ax, 0x0f20
    rep stosw

    mov ebx, 0xb8000
    mov edx, (12*80 + 32)*2
    mov ecx, msg
    call print_string_32bit

    jmp $

%include "gdt.asm"
%include "32bit-print.asm"

msg db "Hello, world!", 0
BOOT_DRIVE db 0

times 510-($-$$) db 0
dw 0xaa55