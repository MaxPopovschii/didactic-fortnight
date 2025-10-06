#include "priorityqueue.h"
#include <stdlib.h>

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void pq_init(PriorityQueue *pq) {
    pq->data = NULL;
    pq->size = 0;
    pq->capacity = 0;
}

void pq_free(PriorityQueue *pq) {
    free(pq->data);
    pq->data = NULL;
    pq->size = 0;
    pq->capacity = 0;
}

void pq_push(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        size_t new_capacity = pq->capacity == 0 ? 4 : pq->capacity * 2;
        int *new_data = realloc(pq->data, new_capacity * sizeof(int));
        if (!new_data) return;
        pq->data = new_data;
        pq->capacity = new_capacity;
    }
    size_t i = pq->size++;
    pq->data[i] = value;
    while (i > 0) {
        size_t parent = (i - 1) / 2;
        if (pq->data[parent] <= pq->data[i]) break;
        swap(&pq->data[parent], &pq->data[i]);
        i = parent;
    }
}

int pq_pop(PriorityQueue *pq) {
    if (pq->size == 0) return 0;
    int ret = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    size_t i = 0;
    while (1) {
        size_t left = 2 * i + 1, right = 2 * i + 2, min = i;
        if (left < pq->size && pq->data[left] < pq->data[min]) min = left;
        if (right < pq->size && pq->data[right] < pq->data[min]) min = right;
        if (min == i) break;
        swap(&pq->data[i], &pq->data[min]);
        i = min;
    }
    return ret;
}

int pq_top(const PriorityQueue *pq) {
    if (pq->size == 0) return 0;
    return pq->data[0];
}

size_t pq_size(const PriorityQueue *pq) {
    return pq->size;
}
