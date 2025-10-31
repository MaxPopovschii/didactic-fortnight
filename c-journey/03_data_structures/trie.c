#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end;
} TrieNode;

TrieNode* create_node() {
    TrieNode *node = malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    node->is_end = 0;
    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!curr->children[idx])
            curr->children[idx] = create_node();
        curr = curr->children[idx];
    }
    curr->is_end = 1;
}

int search(TrieNode *root, const char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!curr->children[idx])
            return 0;
        curr = curr->children[idx];
    }
    return curr->is_end;
}

int main() {
    TrieNode *root = create_node();
    insert(root, "ciao");
    insert(root, "cane");
    insert(root, "gatto");
    printf("ciao? %s\n", search(root, "ciao") ? "Si" : "No");
    printf("cane? %s\n", search(root, "cane") ? "Si" : "No");
    printf("gatto? %s\n", search(root, "gatto") ? "Si" : "No");
    printf("casa? %s\n", search(root, "casa") ? "Si" : "No");
    return 0;
}