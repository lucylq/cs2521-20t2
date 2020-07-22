#include <stdio.h>
#include <stdlib.h>

// max heap
typedef struct heap * Heap; 
struct heap {
    int nitems;
    int nslots;
    int *items;
};

Heap newHeap(int size);
void freeHeap(Heap h);

void insertHeap(Heap h, int v);
int removeHeap(Heap h, int v);
void fixUp(int *items, int max);
void fixDown(int *items, int max);

void printHeap(Heap h);

int main (void) {
    Heap h = newHeap(16);
    insertHeap(h, 1);
    insertHeap(h, 5);
    insertHeap(h, 0);
    insertHeap(h, 10);
    insertHeap(h, 7);
    removeHeap(h, 10);
    printHeap(h);
    return 0;
}

Heap newHeap(int N) {
    Heap h = malloc (sizeof (struct heap));
    h->nslots = N;
    h->nitems = 0;
    h->items = malloc (sizeof (int) * (N+1));
    return h;
}

void insertHeap(Heap h, int v) {
    if (h->nitems >= h->nslots) {
        // resize
        return;
    }
    h->nitems++;
    h->items[h->nitems] = v;
    fixUp(h->items, h->nitems);
}

int removeHeap(Heap h, int v) {
    if (h->nitems == 0) {
        printf ("removeHeap: heap is empty\n");
        return 0;
    }
    int top = h->items[1];
    // replace first element with last element.
    h->items[1] = h->items[h->nitems];
    h->nitems--;
    fixDown(h->items, h->nitems);
    return top;
}

void fixUp(int *items, int i)  {
    while (i>1) {
        // swap
        if (items[i] > items[i/2]) {
            int tmp = items[i];
            items[i] = items[i/2];
            items[i/2] = tmp;
        } 
        // no swaps, invariant OK
        else {
            break;
        }
        // move down
        i = i/2;
    }
}

void fixDown(int *items, int max) {
    int i = 1;
    while (i*2 <= max) {
        int j = 2*i;
        // choose larger of two children
        if (j+1 <= max && items[j+1] < items[j]) j++;
        // swap
        if (items[j] < items[i]) {
            int tmp = items[j];
            items[j] = items[i];
            items[i] = tmp;
        } 
        // no swaps, invariant OK
        else {
            break;
        }
        // move up
        i = j;
    }
}

void printHeap(Heap h) {
    int two = 1;
    for (int i = 1; i <= h->nitems; i++) {
        printf ("%d ", h->items[i]);
        if (i == two) {
            two = two*2+1;
            printf ("\n");
        }
    }
    printf ("\n");
}