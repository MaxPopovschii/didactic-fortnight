#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

void grep_stream(FILE *file, const char *pattern) {
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern)) {
            fputs(line, stdout);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <pattern> [file ...]\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];

    if (argc == 2) {
        // No files: read from stdin
        grep_stream(stdin, pattern);
    } else {
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (!file) {
                perror(argv[i]);
                continue;
            }
            grep_stream(file, pattern);
            fclose(file);
        }
    }
    return 0;
}