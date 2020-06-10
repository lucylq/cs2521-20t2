#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _node {
   int data;
   struct _node *next;
} Node;


// try it out!
List reverseIterative (List L) {
    return NULL;
}
List reverseRecursive (List L, List prev) {
    return NULL;
}

int lengthIterative (List L) {
    List cur = L;
    int count = 0;
    while (cur != NULL) {
        count += 1;
        cur = cur->next;
    }
    return count;
}
/* 
Recursive function calls for length on L = 1->2->3->X
 1 2 3
 L
 1 + f(2 3)
       L 
       1 + f (3)
              L
              1 + f(NULL)
 3     2      1  0
*/      
int lengthRecursive (List L) {
    if (L == NULL) return 0;
    return 1 + lengthRecursive(L->next);
}

int sumRecursive (List L) {
    List cur = L;
    int sum = 0;
    while (cur != NULL) {
        sum += cur->data;
        cur = cur->next;
    }
    return sum;
}
    

float meanIterative (List L) {
    List cur = L;
    int count = 0;
    float sum = 0;
    while (cur != NULL) {
        count += 1;
        sum += cur->data;
        cur = cur->next;
    }
    if (count == 0) return 0;
    return sum/count;
}

float meanRecursive (List L) {
    int count = lengthRecursive(L);
    float sum = sumRecursive(L);
    if (count == 0) return 0;
    return sum/count;
}

float meanRecursive2 (List L) {
    float sum = 0;
    int count = 0;
    float result = meanRecursiveHelper (L, &sum, &count);
}

float meanRecursiveHelper (List L, float* sum, int* count) {
    if (L == NULL) {
        if (*count == 0) return 0;
        return *sum / *count;
    }
    *count = *count + 1;
    *sum = *sum + L->data;
    return meanRecursiveHelper (L->next, sum, count);
}

// create a list node
List createNode (int val) {
    List n = malloc (sizeof (struct _node));
    n->data = val;
    n->next = NULL;
}

// create a list from an array
List createListFromArray (int *a, int size) {
    if (size == 0) return NULL;
    List l = createNode (a[0]);
    List curr = l;
    for (int i = 1; i < size; i++) {
        curr->next = createNode(a[i]);
        curr = curr->next;
    }
    return l;
}

// free memory associated with the list
void freeList (List l) {
    while (l != NULL) {
        List tmp = l->next;
        free(l);
        l = tmp;
    }
}

void print (List l) {
    List cur = l;
    while (cur != NULL) {
        printf ("[%d]->", cur->data);
        cur = cur->next;
    }
    printf ("X\n");
}