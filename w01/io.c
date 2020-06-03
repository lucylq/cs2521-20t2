#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    printf ("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf ("argv[%d]: %s\n", i, argv[i]);
    }

    FILE* fp = fopen ("myFile", "r");
    char word[100];
    fscanf (fp, "%s", word);
    fprintf (fp, "%s\n", word);

    return 0;
}

/*
commandline input: argc, argv

runtime input/output from stdin:
scanf
getchar
printf 

runtime input/output for files:
fgets fscanf
fprintf

*/