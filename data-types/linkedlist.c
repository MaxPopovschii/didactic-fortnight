#include "linkedlist.h"
#include <stdlib.h>

void linkedlist_init(LinkedList *list) {
    list->head = NULL;
}

void linkedlist_free(LinkedList *list) {
    Node *cur = list->head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}

void linkedlist_push_front(LinkedList *list, int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) return;
    node->value = value;
    node->next = list->head;
    list->head = node;
}

void linkedlist_push_back(LinkedList *list, int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) return;
    node->value = value;
    node->next = NULL;
    if (!list->head) {
        list->head = node;
        return;
    }
    Node *cur = list->head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

int linkedlist_pop_front(LinkedList *list) {
    if (!list->head) return 0;
    Node *tmp = list->head;
    int val = tmp->value;
    list->head = tmp->next;
    free(tmp);
    return val;
}
