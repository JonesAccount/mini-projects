[org 0x7c00]

xor ax, ax
mov ds, ax
mov es, ax
mov ss, ax
mov sp, 0x7c00

mov [BOOT_DRIVE], dl   ; <-- ADD THIS LINE (save the real boot drive)

mov bx, LOADING_MSG
call print_string

mov bx, 0x8000
mov dh, 1
mov dl, [BOOT_DRIVE]   ; now uses the saved value
call disk_load

jmp 0x0000:0x8000

%include "asm/print_string.asm"    ; adjust paths as needed
%include "asm/disk_load.asm"

LOADING_MSG db "Loading second sector...", 0
BOOT_DRIVE db 0

times 510-($-$$) db 0
dw 0xaa55