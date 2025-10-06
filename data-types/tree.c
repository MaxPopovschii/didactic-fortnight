#include "tree.h"
#include <stdlib.h>

TreeNode* tree_insert(TreeNode *root, int value) {
    if (!root) {
        TreeNode *node = malloc(sizeof(TreeNode));
        if (!node) return NULL;
        node->value = value;
        node->left = node->right = NULL;
        return node;
    }
    if (value < root->value)
        root->left = tree_insert(root->left, value);
    else
        root->right = tree_insert(root->right, value);
    return root;
}

void tree_free(TreeNode *root) {
    if (!root) return;
    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

void tree_inorder(TreeNode *root, void (*visit)(int)) {
    if (!root) return;
    tree_inorder(root->left, visit);
    visit(root->value);
    tree_inorder(root->right, visit);
}
