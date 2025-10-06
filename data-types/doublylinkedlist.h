#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct DNode {
    int value;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct {
    DNode *head;
    DNode *tail;
} DoublyLinkedList;

void doublylinkedlist_init(DoublyLinkedList *list);
void doublylinkedlist_free(DoublyLinkedList *list);
void doublylinkedlist_push_front(DoublyLinkedList *list, int value);
void doublylinkedlist_push_back(DoublyLinkedList *list, int value);
int  doublylinkedlist_pop_front(DoublyLinkedList *list);
int  doublylinkedlist_pop_back(DoublyLinkedList *list);

#endif // DOUBLYLINKEDLIST_H
