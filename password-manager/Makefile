CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SRC=src/main.c src/password_manager.c
OUT=password-manager

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) passwords.dat

.PHONY: all clean