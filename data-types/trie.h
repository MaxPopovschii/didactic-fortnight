#ifndef TRIE_H
#define TRIE_H

#define TRIE_ALPHABET 26

typedef struct TrieNode {
    struct TrieNode *children[TRIE_ALPHABET];
    int is_end;
} TrieNode;

TrieNode* trie_create();
void trie_insert(TrieNode *root, const char *word);
int  trie_search(TrieNode *root, const char *word);
void trie_free(TrieNode *root);

#endif // TRIE_H
