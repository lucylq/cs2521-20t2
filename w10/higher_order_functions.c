#include <stdio.h>
#include <stdlib.h>

#include "List.h"

// http://cseweb.ucsd.edu/~ricko/rt_lt.rule.html
// List (*f) (List) -> a pointer to a function that takes in a List and returns a List
// List *f (List); -> a function that takes in a List and returns a pointer to a List

List square (List l) {
    l->val = l->val * l->val;
    return l;
}

List addOne (List l) {
    l->val = l->val + 1;
    return l;
}

void map (List L, List (*f) (List))
{
	if (!empty (L)) {
		L = (*f) (head (L));
		map (tail (L), f);
	}
}

int add (int x, int y) { return x + y; }
int sub (int x, int y) { return x - y; }
int mult (int x, int y) { return x * y; }

// TRY: make foldl
int foldr (List L, int (*f) (int, int), int z) // z is the starting element
{
	if (empty (L))
		return z;
	else
        printf ("foldr: %d\n", L->val);
		return f (L->val, foldr (tail (L), f, z));
}

int (*chooseFunction(char c)) (int, int) {
    switch (c) {
        case '+':
            return add;
        case '-':
            return sub;
        case '*':
            return mult;
        default:
            return NULL;
    }
}

int main (void) {
    int a[5] = {1,2,3,4,5};
    List l = arrayToList (a, 5);

    // map [1,2,3], addOne -> [2,3,4]
    print (l);
    map (l, addOne);
    print (l);

    // foldr [1,2,3], add -> 6
    int result = foldr(l, mult, 1);
    printf ("foldr: %d\n", result);

    // returning a function
    int test = chooseFunction('-')(5, 6);
    printf ("test: %d\n", test);

    return 0;
}

// Functional Programming Languages
// Haskell, and others
