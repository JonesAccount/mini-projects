; 32bit-print.asm – 32-bit VGA print function
; Input:
;   EBX = VGA buffer (0xb8000)
;   EDX = offset into buffer (row*80 + col) * 2
;   ECX = address of null-terminated string
; Output: none (clobbers EAX, EBX, ECX, EDX inside pusha)
print_string_32bit:
    pusha
    add ebx, edx        ; EBX now points exactly where to write
    mov ah, 0x0f        ; white on black
.loop:
    mov al, [ecx]
    cmp al, 0
    je .done
    mov [ebx], ax
    add ebx, 2
    inc ecx
    jmp .loop
.done:
    popa
    ret