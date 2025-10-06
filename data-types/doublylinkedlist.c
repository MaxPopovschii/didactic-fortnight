#include "doublylinkedlist.h"
#include <stdlib.h>

void doublylinkedlist_init(DoublyLinkedList *list) {
    list->head = list->tail = NULL;
}

void doublylinkedlist_free(DoublyLinkedList *list) {
    DNode *cur = list->head;
    while (cur) {
        DNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = list->tail = NULL;
}

void doublylinkedlist_push_front(DoublyLinkedList *list, int value) {
    DNode *node = malloc(sizeof(DNode));
    if (!node) return;
    node->value = value;
    node->prev = NULL;
    node->next = list->head;
    if (list->head) list->head->prev = node;
    else list->tail = node;
    list->head = node;
}

void doublylinkedlist_push_back(DoublyLinkedList *list, int value) {
    DNode *node = malloc(sizeof(DNode));
    if (!node) return;
    node->value = value;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail) list->tail->next = node;
    else list->head = node;
    list->tail = node;
}

int doublylinkedlist_pop_front(DoublyLinkedList *list) {
    if (!list->head) return 0;
    DNode *tmp = list->head;
    int val = tmp->value;
    list->head = tmp->next;
    if (list->head) list->head->prev = NULL;
    else list->tail = NULL;
    free(tmp);
    return val;
}

int doublylinkedlist_pop_back(DoublyLinkedList *list) {
    if (!list->tail) return 0;
    DNode *tmp = list->tail;
    int val = tmp->value;
    list->tail = tmp->prev;
    if (list->tail) list->tail->next = NULL;
    else list->head = NULL;
    free(tmp);
    return val;
}
