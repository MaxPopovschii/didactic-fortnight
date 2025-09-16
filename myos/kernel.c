// kernel.c
#include "print.h"
#include "keyboard.h"
#include "memory.h"
#include "disk.h"

// Funzione strcmp minimale
int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// Funzione strncmp minimale
int strncmp(const char *s1, const char *s2, unsigned int n) {
    while (n && *s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0) return 0;
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// Funzione clear screen
void clear_screen() {
    char *video = (char*)0xb8000;
    for (int i = 0; i < 80 * 25; i++) {
        video[i * 2] = ' ';
        video[i * 2 + 1] = 0x07;
    }
}

void kernel_main() {
    char *video = (char*)0xb8000;
    video[0] = 'X';
    video[1] = 0x07;
    while (1) {}
}