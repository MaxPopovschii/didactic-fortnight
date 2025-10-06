#include "trie.h"
#include <stdlib.h>

TrieNode* trie_create() {
    TrieNode *node = malloc(sizeof(TrieNode));
    if (!node) return NULL;
    for (int i = 0; i < TRIE_ALPHABET; i++) node->children[i] = NULL;
    node->is_end = 0;
    return node;
}

void trie_insert(TrieNode *root, const char *word) {
    TrieNode *cur = root;
    for (const char *p = word; *p; p++) {
        int idx = *p - 'a';
        if (idx < 0 || idx >= TRIE_ALPHABET) continue;
        if (!cur->children[idx]) cur->children[idx] = trie_create();
        cur = cur->children[idx];
    }
    cur->is_end = 1;
}

int trie_search(TrieNode *root, const char *word) {
    TrieNode *cur = root;
    for (const char *p = word; *p; p++) {
        int idx = *p - 'a';
        if (idx < 0 || idx >= TRIE_ALPHABET) return 0;
        if (!cur->children[idx]) return 0;
        cur = cur->children[idx];
    }
    return cur->is_end;
}

void trie_free(TrieNode *root) {
    if (!root) return;
    for (int i = 0; i < TRIE_ALPHABET; i++) trie_free(root->children[i]);
    free(root);
}
