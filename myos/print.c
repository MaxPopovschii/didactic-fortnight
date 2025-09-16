#include "print.h"
#include <stdarg.h>

#define VIDEO_MEMORY ((char*)0xb8000)
#define VGA_WIDTH 80
static int cursor = 0;

void putchar(char c) {
    VIDEO_MEMORY[cursor * 2] = c;
    VIDEO_MEMORY[cursor * 2 + 1] = 0x07;
    cursor++;
    if (cursor >= VGA_WIDTH * 25) cursor = 0;
}

void printk(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    for (const char *p = fmt; *p; p++) {
        if (*p == '%' && *(p+1) == 'd') {
            int val = va_arg(args, int);
            char buf[16];
            int i = 0;
            if (val == 0) putchar('0');
            else {
                if (val < 0) { putchar('-'); val = -val; }
                while (val > 0) { buf[i++] = '0' + (val % 10); val /= 10; }
                while (i--) putchar(buf[i]);
            }
            p++;
        } else {
            putchar(*p);
        }
    }
    va_end(args);
}