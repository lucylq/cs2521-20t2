#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Sorting
void bubbleSort (int *a, int lo, int hi);

void shellSort(int *a, int lo, int hi);

void quickSort (int *a, int lo, int hi);
int qsort_ (int *a, int lo, int hi);

void mergeSort (int *a, int lo, int hi);
void msort (int *a, int *tmp, int lo, int hi);
int partition (int *a, int *tmp, int lo, int hi);

// Utility
void swap (int *a, int i, int j);
void print (int *a, int lo, int hi);

int main (int argc, char *argv[]) {
  int *a = malloc (sizeof (int) *MAX);
  int len = 0;
  while (len < MAX && scanf ("%d", &a[len]) == 1) len++;
  quickSort(a, 0, len);
  // mergeSort(a, 0, len);
  // bubbleSort(a, 0, len);
  // shellSort (a, 0, len);
  printf ("result\n");
  print(a, 0, len);

  free(a);
  return 0;
}

// ascending, early exit.
void bubbleSort (int *a, int lo, int hi) {
  int sorted = 1;
  for (int i = lo; i < hi; i++) {
    for (int j = lo; j < hi - i; j++) {
      if (a[j-1] > a[j]) {
        swap (a, j-1, j);
        sorted = 0;
      }
    }
    if (sorted) break;
  }
}

/* Shellsort pseudocode

  calculate #gaps
  for h from largest to smallest gap size
    sort every h'th element

  Sample tutorial code from Tutorial 9
  https://cgi.cse.unsw.edu.au/~cs2521/20T2/tutes/week09/index.php

*/
void shellSort(int *a, int lo, int hi)
{
   int i, j, h, val;
   for (h = 1; h <= (hi-lo)/9; h = 3*h+1) ;
   for ( ; h > 0; h /= 3) {
      for (i = lo+h; i <= hi; i++) {
         j = i;  val = a[i];
         while (j >= lo+h && val < a[j-h]) {
            a[j] = a[j-h];
            j -= h;
         }
         a[j] = val;
      }
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
void quickSort (int *a, int lo, int hi) {
  // one item
  if (hi - lo <= 1) return;
  int p = qsort_ (a, lo, hi);
  quickSort (a, lo, p);
  quickSort (a, p+1, hi);
}

// array valid from lo..hi-1
int qsort_ (int *a, int lo, int hi) {
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
void mergeSort (int *a, int lo, int hi) {
  int *tmp = malloc (sizeof (int) *lo);
  for (int i = 0; i < hi; i++) tmp[i] = a[i];
  msort (a, tmp, lo, hi);
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
