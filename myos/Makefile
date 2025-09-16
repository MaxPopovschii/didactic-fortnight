CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SRC=kernel.c memory.c keyboard.c print.c

all: myos.img

kernel.bin: $(SRC) linker.ld
	gcc -ffreestanding -c memory.c
	gcc -ffreestanding -c keyboard.c
	gcc -ffreestanding -c print.c
	gcc -ffreestanding -c kernel.c
	ld -T linker.ld kernel.o memory.o keyboard.o print.o -o kernel.bin -nostdlib

boot.bin: boot.asm
	nasm -f bin boot.asm -o boot.bin

myos.img: boot.bin kernel.bin
	cat boot.bin kernel.bin > myos.img

run: myos.img
	qemu-system-x86_64 -nographic -drive format=raw,file=myos.img

clean:
	rm -f *.bin *.o myos.img
	rm -f myprog

myprog: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@