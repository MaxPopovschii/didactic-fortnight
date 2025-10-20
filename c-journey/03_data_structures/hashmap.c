#include <stdio.h>
#define SIZE 10

typedef struct {
    int keys[SIZE];
    int values[SIZE];
} HashMap;

int hash(int key) { return key % SIZE; }

void put(HashMap *hm, int key, int value) {
    int idx = hash(key);
    while (hm->keys[idx] != 0 && hm->keys[idx] != key)
        idx = (idx + 1) % SIZE;
    hm->keys[idx] = key;
    hm->values[idx] = value;
}

int get(HashMap *hm, int key) {
    int idx = hash(key);
    while (hm->keys[idx] != 0) {
        if (hm->keys[idx] == key)
            return hm->values[idx];
        idx = (idx + 1) % SIZE;
    }
    return -1;
}

int main() {
    HashMap hm = {0};
    put(&hm, 5, 100);
    put(&hm, 15, 200);
    printf("Valore per chiave 5: %d\n", get(&hm, 5));
    printf("Valore per chiave 15: %d\n", get(&hm, 15));
    printf("Valore per chiave 7: %d\n", get(&hm, 7));
    return 0;
}