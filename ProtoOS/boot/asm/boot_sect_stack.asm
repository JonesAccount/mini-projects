; Stack lesson
mov ah, 0x0e        ; tty mode (print character)

mov bp, 0x8000      ; set the base (bottom) of the stack far from 0x7c00
mov sp, bp          ; stack is empty -> top = base

push 'A'            ; store 'A' on stack (as 16-bit word: 0x0041)
push 'B'            ; store 'B'
push 'C'            ; store 'C'

; Now, sp = 0x7FFA (0x8000 - 3*2)
; The stack memory looks like:
; 0x7FFA: 'C'
; 0x7FFC: 'B'
; 0x7FFE: 'A'
; 0x8000: (untouched, garbage)

; Try to read 'A' directly from memory (0x8000-2)
mov al, [0x7ffe]    ; al = 0x41 ('A')
int 0x10            ; prints 'A'

; Try to read from the original base (0x8000) – nothing there
mov al, [0x8000]
int 0x10            ; prints garbage (random character)

; Now pop values back (last-in-first-out)
pop bx              ; bx = 'C' (0x0043)
mov al, bl          ; take lower byte
int 0x10            ; prints 'C'

pop bx
mov al, bl
int 0x10            ; prints 'B'

pop bx
mov al, bl
int 0x10            ; prints 'A'

; After all pops, sp = 0x8000 again, but the old data is considered garbage
mov al, [0x8000]
int 0x10            ; prints garbage (whatever was at 0x8000 originally)

jmp $               ; hang forever

times 510-($-$$) db 0
dw 0xaa55