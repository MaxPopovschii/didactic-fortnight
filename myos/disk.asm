; filepath: myos/disk.asm
global disk_read
disk_read:
    pusha
    mov ah, 0x02
    mov al, 1
    mov ch, 0
    mov cl, [esp+36] ; settore
    mov dh, 0
    mov dl, 0
    mov bx, [esp+40] ; buffer
    int 0x13
    popa
    ret