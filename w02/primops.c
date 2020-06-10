#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int n = 5; 
	//  5 4 3 2 1 0
	for(int i = n; i >= 1; i--)  // n + n + 1
	{
		// 5-> 5 iterations: 1
		// 5-> 4 iterations: 2
		// 5-> 3 iterations: 3
		// ...
		for(int j = n; j >= i; j--) // (1 + n)*n + n =  n^2 + 2n
		{
			printf("%d %d\n", i, j); // A[i], A[j] (1 + n)*n = n^2 + n
		}
		printf("\n");
	}
    return 0;
}

// 2n^2 + 5n + 1 -> O(n^2)

/*
Evaluating an expression
Array indexing
Arithmetic sum: (first + last)*numItems/2
*/

/*
while n>0 do
	push (n mod 2) onto S
	n = ⌊ n/2 ⌋
end while

n = 10
10
5
2
1

ceiling (log10)
*/
// logarithmic algorithms: look for when the input size halves
// eg. binary search, the tutorial example, mergesort O(nlogn), quicksort O(nlogn)

