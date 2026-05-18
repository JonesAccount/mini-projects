; 32bit-switch.asm – switch to 32-bit protected mode
[bits 16]
switch_to_32bit:
    cli                     ; disable interrupts
    lgdt [gdt_descriptor]   ; load GDT
    mov eax, cr0
    or eax, 0x1             ; set protected mode bit
    mov cr0, eax
    jmp CODE_SEG:init_32bit ; far jump to flush pipeline