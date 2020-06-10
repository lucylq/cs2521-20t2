#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (void) {
    // create a list
    int a[5] = {1,2,3,4,5};
    List l = createListFromArray(a, 5);

    printf ("Iterative length: %d\n", lengthIterative(l));
    printf ("Recursive length: %d\n", lengthRecursive(l));

    printf ("Iterative mean: %lf\n", meanIterative(l));
    printf ("Recursive mean: %lf\n", meanRecursive(l));
    printf ("Recursive mean2: %lf\n", meanRecursive2(l));

    l = reverseIterative(l);
    print(l);
    l = reverseRecursive(l, NULL);
    print(l);
    // free memory associated with list
    freeList(l);
    
    return 0;
}

// Abstract Data Types
