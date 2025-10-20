#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* insert(Node *root, int val) {
    if (!root) {
        Node *n = malloc(sizeof(Node));
        n->data = val;
        n->left = n->right = NULL;
        return n;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 4);
    printf("In-order: ");
    inorder(root);
    printf("\n");
    return 0;
}