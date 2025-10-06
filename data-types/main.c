#include <stdio.h>
#include "list.h"
#include "linkedlist.h"
#include "tree.h"
#include "map.h"

void print_int(int v) { printf("%d ", v); }

int main() {
    // List
    List l; list_init(&l);
    list_push(&l, 10); list_push(&l, 20); list_push(&l, 30);
    printf("List: ");
    for (size_t i = 0; i < list_size(&l); ++i) printf("%d ", list_get(&l, i));
    printf("\n");
    list_free(&l);

    // LinkedList
    LinkedList ll; linkedlist_init(&ll);
    linkedlist_push_back(&ll, 1); linkedlist_push_back(&ll, 2); linkedlist_push_front(&ll, 0);
    printf("LinkedList: ");
    Node *cur = ll.head;
    while (cur) { printf("%d ", cur->value); cur = cur->next; }
    printf("\n");
    linkedlist_free(&ll);

    // Tree
    TreeNode *root = NULL;
    root = tree_insert(root, 5); root = tree_insert(root, 2); root = tree_insert(root, 8);
    printf("Tree inorder: ");
    tree_inorder(root, print_int); printf("\n");
    tree_free(root);

    // Map
    Map m; map_init(&m);
    map_put(&m, 42, 100); map_put(&m, 7, 77);
    int found;
    printf("Map get 42: %d\n", map_get(&m, 42, &found));
    printf("Map get 7: %d\n", map_get(&m, 7, &found));
    printf("Map get 99: %d (found=%d)\n", map_get(&m, 99, &found), found);
    map_free(&m);
    return 0;
}
