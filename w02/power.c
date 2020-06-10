#include <stdio.h>
#include <stdlib.h>

int pow_iterative(int x, unsigned int n)
{
   int res = 1;
   for (int i = 1; i <= n; i++)
      res = res * x;
   return res;
}

int main (int argc, char* argv[]) {
    if(argc < 3) {
        printf ("Usage: ./power <base> <exp>\n");
        return 1;
    }
    int base = atoi(argv[1]);
    unsigned int exp = atoi(argv[2]);

    printf ("%d^%u = %d\n", base, exp, pow_iterative(base, exp));
    return 0;
}