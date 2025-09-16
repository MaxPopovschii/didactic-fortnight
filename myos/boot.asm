; filepath: myos/boot.asm
BITS 16
ORG 0x7C00

mov si, msg
call print

jmp 0x0000:0x7E00

print:
    mov ah, 0x0E
.next:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .next
.done:
    ret

msg db "Booting myOS...", 0

times 510-($-$$) db 0
dw 0xAA55