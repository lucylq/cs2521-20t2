#include <stdio.h>
#include <stdlib.h>

#include "List.h"

List head (List l) {
    return l;
}

List tail (List l) {
    if (l == NULL) return NULL;
    return l->next;
}

int empty (List l) {
    if (l == NULL) return 1;
    return 0;
}

List arrayToList (int *a, int len) {
    if (len == 0) return NULL;
    // head
    List l = createNode (a[0]);
    // rest
    List curr = l;
    for (int i = 1; i < len; i++) {
        curr->next = createNode(a[i]);
        curr = curr->next;
    }
    return l;
}

void print (List l) {
    List cur = l;
    while (cur != NULL) {
        printf ("%d -> ", cur->val);
        cur = cur->next;
    }
    printf ("X\n");
}

List createNode(int v) {
    List n = malloc (sizeof (struct list));
    n->val = v;
    n->next = NULL;
    return n;
}

void freeList (List l) {
    List curr;
    while (l != NULL) {
        curr = l;
        l = l->next;
        free(curr);
    }
}