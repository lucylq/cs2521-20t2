#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Sorting
void bubblesort (int *a, int length);

void quicksort (int *a, int length);
void qsort_ (int *a, int lo, int hi);
int qs_partition (int *a, int lo, int hi);

void mergesort (int *a, int length);
void msort (int *a, int *tmp, int lo, int hi);
int partition (int *a, int *tmp, int lo, int hi);

// Utility
void swap (int *a, int i, int j);
void print (int *a, int lo, int hi);

int main (int argc, char *argv[]) {
  int *a = malloc (sizeof (int) *MAX);
  int len = 0;
  while (len < MAX && scanf ("%d", &a[len]) == 1) len++;
  // quicksort(a, len);
  // mergesort(a, len);
  // bubblesort(a, len);
  printf ("result\n");
  print(a, 0, len);

  free(a);
  return 0;
}


// ascending, early exit.
void bubblesort (int *a, int length) {
  int sorted = 1;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - i; j++) {
      if (a[j-1] > a[j]) {
        swap (a, j-1, j);
        sorted = 0;
      }
    }
    if (sorted) break;
  }
}

/* Quicksort pseudocode

qsort (a, lo, hi)
  partition
  qsort (a, lo, mid)
  qsort (a, mid, hi)

partition (a, lo, hi)
  pivot at lo
  pointer at lo+1
  pointer at hi-1
  swap when necessary

*/
void quicksort (int *a, int length) {
  qsort_(a, 0, length);
}

// array valid from lo..hi-1
void qsort_ (int *a, int lo, int hi) {
  // one item
  if (hi - lo <= 1) return;
  int p = qs_partition (a, lo, hi);
  qsort_ (a, lo, p);
  qsort_ (a, p+1, hi);
}

// array valid from lo..hi-1
int qs_partition (int *a, int lo, int hi) {
  int pivot = a[lo];
  int min = lo;
  for (int i = lo + 1; i < hi; i++) {
    if (a[i] < pivot) {
      min++;
      swap(a, i, min);
    }
  }
  swap (a, lo, min);
  return min;
}

/* Mergesort pseudocode

msort (a, lo, hi)
  partition
  merge

partition (a, lo, hi)
  msort (a, lo, mid)
  msort (a, mid, hi)

*/

void mergesort (int *a, int length) {
  int *tmp = malloc (sizeof (int) *length);
  for (int i = 0; i < length; i++) tmp[i] = a[i];
  msort (a, tmp, 0, length);
  free(tmp);
}

// array valid from lo..hi-1
void msort (int *a, int *tmp, int lo, int hi) {
  // one item
  if (hi - lo <= 1) return;

  // divide
  int p = partition(a, tmp, lo, hi);
  int mid = p;
  int l = lo;

  // merge
  for (int i = lo; i < hi; i++) {
    if (l >= p) {
      tmp[i] = a[mid];
      mid++;
    } else if (mid >= hi) {
      tmp[i] = a[l];
      l++;
    } else {
      if (a[l] <= a[mid]) {
        tmp[i] = a[l];
        l++;
      } else {
        tmp[i] = a[mid];
        mid++;
      }
    }
  }

  // copy
  for (int i = lo; i < hi; i++) a[i] = tmp[i];
}

// array valid from lo..hi-1
int partition (int *a, int *tmp, int lo, int hi) {
  if (hi - lo <= 1) {
    return hi;
  } else {
    int mid = (hi + lo)/2;
    msort (a, tmp, lo, mid);
    msort (a, tmp, mid, hi);
    return mid;
  }
}

void swap (int *a, int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void print (int *a, int lo, int hi) {
  for (int i = lo; i < hi; i++) {
    printf ("%d ", a[i]);
  }
  printf ("\n");
}
