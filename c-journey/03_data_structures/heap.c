#include <stdio.h>
#define MAX 20

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify_up(MinHeap *h, int idx) {
    while (idx > 0 && h->arr[idx] < h->arr[(idx - 1) / 2]) {
        swap(&h->arr[idx], &h->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void insert(MinHeap *h, int val) {
    if (h->size < MAX) {
        h->arr[h->size] = val;
        heapify_up(h, h->size);
        h->size++;
    }
}

void heapify_down(MinHeap *h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < h->size && h->arr[left] < h->arr[smallest]) smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest]) smallest = right;
    if (smallest != idx) {
        swap(&h->arr[idx], &h->arr[smallest]);
        heapify_down(h, smallest);
    }
}

int extract_min(MinHeap *h) {
    if (h->size == 0) return -1;
    int min = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapify_down(h, 0);
    return min;
}

int main() {
    MinHeap h = {.size = 0};
    insert(&h, 5);
    insert(&h, 3);
    insert(&h, 8);
    insert(&h, 1);
    printf("Estrai min: %d\n", extract_min(&h));
    printf("Estrai min: %d\n", extract_min(&h));
    return 0;
}