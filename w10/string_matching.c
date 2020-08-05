#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <string.h>

#define ALPH 26

int bm (char * pattern, char *text);
void print(char* pattern, char *text, int p, int t, int align, int index);
int kmp (char * pattern, char *text);

int main (int argc, char * argv[]) {
    if (argc < 4) {
        printf("Usage: ./substring <bm | kmp> <pattern> <text>\n");
        return 1;
    }
    int res;
    if (strcmp (argv[1], "bm") == 0) {
        res = bm(argv[2], argv[3]);
    } else if (strcmp (argv[1], "kmp") == 0) {
        res = kmp(argv[2], argv[3]);
    } else {
        printf("Usage: ./substring <bm | kmp> <pattern> <text>\n");
        return 1;
    }

    if (res == -1) {
        printf ("Did not find pattern \"%s\" in text \"%s\"\n", argv[2], argv[3]);
    } else {
        printf ("Found pattern \"%s\" at index %d of text \"%s\"\n", argv[2], res, argv[3]);
    }

    return 0;
}

int kmp (char * pattern, char *text) {
    printf ("\n=== Knuth-Morris-Pratt Algorithm ===\n");
    int p = strlen (pattern);
    int t = strlen (text);
    if (p > t) return 0;

    // compute the prefix array (tutorial calls it the failure function)
    printf ("\nPopulating the prefix table...\n");
    int *prefix = malloc (sizeof (int)*p);
    
    prefix[0] = 0;
    // find the longest prefix 0..i that is also a suffix 0..i
    for (int i = 1; i < p; i++) {
      int j = prefix[i-1];
      while (j > 0 && pattern[i] != pattern[j]) {
        j = prefix[j-1];
      }
      if(pattern[i] == pattern[j]) {
        j++;
      }
      prefix[i] = j;
    }

    for (int i = 0; i < p; i++) {
        printf ("%c ", pattern[i]);
    }
    printf ("\n");
    for (int i = 0; i < p; i++) {
        printf ("%d ", prefix[i]);
    }
    printf ("\n");

    // and then kmp algo 
    printf ("\nComputing the algorithm...\n");
    int ip = 0;
    int i = 0;
    int align = 0;
    while (i < t){
        print(pattern, text, p, t, align, i);
        if (ip == p) {
            return i - p;
        }
        // if match, move forward
        if (pattern[ip] == text[i]) {
            printf ("Match: continue\n\n");
            ip ++;
            i ++;
        } else {
            // if it doesnt match, go to the longest prefix that is also a suffix and continue
            if (ip > 0) { 
                printf ("No match: jump %d\n\n", ip - prefix[ip-1]);
                align += ip - prefix[ip-1];
                ip = prefix[ip - 1];
            } else {
                printf ("No match: jump 1\n\n");
                align++;
                i++;
            }
        }
    }
    if (ip == p) {
        return i - p;
    }
    free(prefix);
    return -1;
}

int bm (char * pattern, char * text) {
    printf ("\n=== Boyer-Moore Algorithm ===\n");
    int p = strlen(pattern);
    int t = strlen(text);
    if (p > t) return 0;

    // populate last array 
    printf ("\nPopulating the last array ... \n");
    int last[ALPH];
    for (int i = 0; i < ALPH; i++) {
        last[i] = -1;
    }
    for (int i = 0; i < p; i++) {
        last[pattern[i] - 'a'] = i;
    }

    for (int i = 0; i < p; i++) {
        printf ("last(%c) = %d\n", pattern[i], last[pattern[i] - 'a']);
    }

    printf ("\nComputing the algorithm ... \n");
    // computing the algo 
    int ip = p-1;
    int it = p-1;
    int align = 0;
    while (it < t) {
        print(pattern, text, p, t, align, it);
        if (pattern[ip] == text[it]) {
            if (ip == 0) {
                return it;
            }
            ip --;
            it --;
        } else {
            printf ("Mismatch: %c, %c\n", text[it], pattern[ip]);
            //ip = p-1;
            // if the character doesn't exist, shift it completely forwards 
            if (last[text[it] - 'a'] == -1) {
                printf ("Character '%c' not found in pattern - shift forwards\n", text[it]);
                it = it + p;
                ip = p-1;
                align = it - p + 1;
            } 
            // otherwise, shift it forwards by the last(c)
            else {
                int shift = (p-1) - last[text[it] - 'a'];
               // printf ("shift: %d, ip: %d, it: %d\n", shift, ip, it);
                if (shift < p - ip) {
                  printf ("Shift forwards: last '%c' exists before index %d\n", text[it], ip);
                  it = it + p;
                  ip = p - 1;
                  align = it - p + 1;
                } else {
                  printf ("Shift forwards by (%d - last(%c)) = %d\n", (p-1), text[it], (p-1) - last[text[it] - 'a']);
                  it = it + shift;
                  align = it - (p-1);
                }
            }
        }
    }
    return -1;
}

void print(char* pattern, char *text, int p, int t, int align, int index) {
    
    for (int i = 0; i < t; i++) {
        printf ("%c ", text[i]);
    }
    printf ("\n");
    for (int i = 0; i < align; i++) {
        printf ("  ");
    }
    for (int i = 0; i < p; i++) {
        printf ("%c ", pattern[i]);
    }
    printf ("\n");
    for (int i = 0; i < t; i++) {
        if (i == index) printf ("^ ");
        else printf ("  ");
    } 
    printf ("\n");
}