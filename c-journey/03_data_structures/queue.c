#include <stdio.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int front, rear, size;
} Queue;

void enqueue(Queue *q, int val) {
    if (q->size < MAX) {
        q->arr[q->rear] = val;
        q->rear = (q->rear + 1) % MAX;
        q->size++;
    }
}

int dequeue(Queue *q) {
    if (q->size > 0) {
        int val = q->arr[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return val;
    }
    return -1;
}

int main() {
    Queue q = {.front = 0, .rear = 0, .size = 0};
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    return 0;
}