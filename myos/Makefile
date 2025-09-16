CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SRC=kernel.c memory.c keyboard.c print.c

all: myos.img

kernel.elf: $(SRC) linker.ld
	$(CC) -ffreestanding -c memory.c
	$(CC) -ffreestanding -c keyboard.c
	$(CC) -ffreestanding -c print.c
	$(CC) -ffreestanding -c kernel.c
	ld -T linker.ld kernel.o memory.o keyboard.o print.o -o kernel.elf -nostdlib

kernel.bin: kernel.elf
	objcopy -O binary kernel.elf kernel.bin

boot.bin: boot.asm
	nasm -f bin boot.asm -o boot.bin

myos.img: boot.bin kernel.bin
	cat boot.bin kernel.bin > myos.img

run: myos.img
	qemu-system-x86_64 -nographic -drive format=raw,file=myos.img

clean:
	rm -f *.bin *.o *.elf myos.img
	rm -f myprog

myprog: main.c
	$(CC) $(CFLAGS) main.c -o $@