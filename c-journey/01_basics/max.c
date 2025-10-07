#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Invalid input.\n");
        return 1;
    }
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("The maximum is: %d\n", max);
    return 0;
}