#include <stdio.h>

int main() {
    FILE *tmp = tmpfile();
    if (!tmp) {
        perror("Impossibile creare file temporaneo");
        return 1;
    }
    fprintf(tmp, "Questo è un file temporaneo!\n");
    rewind(tmp);
    char buffer[64];
    fgets(buffer, sizeof(buffer), tmp);
    printf("Letto dal file temporaneo: %s", buffer);
    fclose(tmp);
    return 0;
}