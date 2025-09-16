#include "keyboard.h"

static const char scancode_ascii[] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0, '\\',
    'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ', 0,
    // ... (puoi estendere se vuoi)
};

unsigned char inb(unsigned short port) {
    unsigned char ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

unsigned char keyboard_read_scancode() {
    return inb(0x60);
}

char keyboard_getchar() {
    unsigned char sc = keyboard_read_scancode();
    if (sc > 0 && sc < sizeof(scancode_ascii) && scancode_ascii[sc])
        return scancode_ascii[sc];
    return 0;
}