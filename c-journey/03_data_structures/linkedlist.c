#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void append(Node **head, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *curr = *head;
    while (curr->next) curr = curr->next;
    curr->next = new_node;
}

void print_list(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    print_list(head);
    return 0;
}