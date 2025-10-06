#ifndef TREE_H
#define TREE_H

// Simple binary search tree for int
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* tree_insert(TreeNode *root, int value);
void tree_free(TreeNode *root);
void tree_inorder(TreeNode *root, void (*visit)(int));

#endif // TREE_H
