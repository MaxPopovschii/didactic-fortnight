// kernel.c
#include "memory.h"
#include "keyboard.h"
#include "disk.h"
#include "print.h"

void kernel_main() {
    const char *msg = "Hello from myOS kernel!\n";
    char *video = (char*)0xb8000;
    for (int i = 0; msg[i] != 0; i++) {
        video[i * 2] = msg[i];
        video[i * 2 + 1] = 0x07;
    }
    memory_init((void*)0x10000, 0x1000); // heap da 4KB a 0x10000
    char *buf1 = (char*)kmalloc(32);
    // usa buf1...
    unsigned char sc = keyboard_read_scancode();
    // usa sc...
    char buf2[512];
    // usa buf2 per la lettura disco...
    printk("Welcome to myOS!\n> ");
    while (1) {
        char c = keyboard_getchar();
        if (c) {
            putchar(c);
            if (c == '\n') printk("> ");
        }
    }
}