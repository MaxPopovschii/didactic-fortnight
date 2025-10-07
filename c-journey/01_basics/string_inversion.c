#include <stdio.h>


int main() {
    char str[100];
    char inverted[100];
    printf("Enter a string: ");
    scanf("%99s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        inverted[i] = str[len - 1 - i];
    }
    inverted[len] = '\0';
    printf("Inverted string: %s\n", inverted);
    return 0;
}