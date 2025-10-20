#include <stdio.h>
#include <string.h>
#include <ctype.h>

int conta_parole(const char *line) {
    int count = 0, in_word = 0;
    for (int i = 0; line[i]; i++) {
        if (isspace(line[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

int main() {
    FILE *f = fopen("testo.txt", "r");
    if (!f) {
        perror("Impossibile aprire il file");
        return 1;
    }
    char buffer[256];
    int totale = 0;
    while (fgets(buffer, sizeof(buffer), f)) {
        totale += conta_parole(buffer);
    }
    fclose(f);
    printf("Numero totale di parole: %d\n", totale);
    return 0;
}