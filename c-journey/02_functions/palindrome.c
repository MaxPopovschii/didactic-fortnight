#include <stdio.h>

int is_palindrome(const char *str) {
    int len = strlen(str);
    int left = 0, right = len - 1;
    while (left < right) {
        if (str[left] != str[right]) return 0;
        left++;
        right--;    
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);
    if (is_palindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    return 0;
}