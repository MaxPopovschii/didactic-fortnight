#include <stdio.h>
#include <string.h>

void print_with_line_numbers(FILE *file) {
    int c, line = 1;
    printf("%6d  ", line++);
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
        if (c == '\n' && !feof(file)) {
            printf("%6d  ", line++);
        }
    }
}

void print_plain(FILE *file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
}

int main(int argc, char *argv[]) {
    int use_line_numbers = 0;
    int arg_start = 1;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        use_line_numbers = 1;
        arg_start = 2;
    }

    if (argc == 1 || (use_line_numbers && argc == 2)) {
        // No files: read from stdin
        if (use_line_numbers)
            print_with_line_numbers(stdin);
        else
            print_plain(stdin);
        return 0;
    }

    for (int i = arg_start; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (!file) {
            perror(argv[i]);
            continue;
        }
        if (use_line_numbers)
            print_with_line_numbers(file);
        else
            print_plain(file);
        fclose(file);
    }
    return 0;
}