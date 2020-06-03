#include <stdio.h>
#include <stdlib.h>

struct list {
    int val;
    struct list *next;
};

// create a list node
struct list * createNode (int val) {
    struct list *n = malloc (sizeof (struct list));
    n->val = val;
    n->next = NULL;
}

// create a list from an array
struct list * createListFromArray (int *a, int size) {
    if (size == 0) return NULL;
    struct list * l = createNode (a[0]);
    struct list *curr = l;
    for (int i = 1; i < size; i++) {
        curr->next = createNode(a[i]);
        curr = curr->next;
    }
    return l;
}

int sumListWhile (struct list* head) {
    int sum = 0;
    struct list *curr = head;
    while (curr != NULL) {
        sum += curr->val;
        curr = curr->next;
    }
    return sum;
}

int sumListFor (struct list* head) {
    int sum = 0;
    for (struct list* curr = head; curr != NULL; curr = curr->next) {
        sum += curr->val;
    }
    return sum;
}

int sumListRecursive (struct list* head) {
    // base case
    if (head == NULL) return 0;
    // recursive case
    return head->val + sumListRecursive(head->next);
}

int main (int argc, char *argv[]) {

    // create a list
    int a[5] = {1,2,3,4,5};
    struct list *l = createListFromArray(a, 5);

    printf ("sumListWhile: %d\n", sumListWhile(l));
    printf ("sumListFor: %d\n", sumListFor(l));
    printf ("sumListRecursive: %d\n", sumListRecursive(l));

    return 0;
}