#include <stdio.h>
#include <stdlib.h>

int main (void) {
    char ch = getchar();
    switch (ch) {                              
        case 'a':  
        case 'e':  
        case 'i':  
        case 'o':  
        case 'u':  printf("is a vowel"); break;
        default: printf ("not a vowel");
    }
    printf ("\n");

    // switch (ch) {                              
    //     case 'a':  printf("eh? "); break;
    //     case 'e':  printf("eee "); break;
    //     case 'i':  printf("eye "); break;
    //     case 'o':  printf("ohh "); break;
    //     case 'u':  printf("you "); break;
    // }
    // printf("\n");                              
    return 0;
}

/*
Switch statements exhibit 'fall-through' behaviour. Without a break statement to exit from the switch construct, each switch case after the succeeding one will be executed.
*/