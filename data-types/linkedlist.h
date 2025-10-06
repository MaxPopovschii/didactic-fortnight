#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Singly linked list for int
typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void linkedlist_init(LinkedList *list);
void linkedlist_free(LinkedList *list);
void linkedlist_push_front(LinkedList *list, int value);
void linkedlist_push_back(LinkedList *list, int value);
int  linkedlist_pop_front(LinkedList *list);

#endif // LINKEDLIST_H
