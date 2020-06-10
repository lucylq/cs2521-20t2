#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fib (int n)
{
   assert (n > 0);
   if (n == 1 || n == 2)
      return 1;
   else
      return fib(n-1) + fib(n-2);
}

int main (int argc, char* argv[]) {
    if (argc < 2) {
        printf ("Usage: ./fib <n>\n");
        return 1;
    }
    int n = atoi(argv[1]);

    int result = fib(n);
    printf ("fib (%d) = %d\n", n, result);
    return 0;
}

