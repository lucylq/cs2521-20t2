#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N_CHARS 26
#define MAX_WORD 100

typedef struct trie * Trie;
struct trie {
    int isEnd;
    Trie children[N_CHARS];
};

Trie newTrie ();
void freeTrie (Trie t);

void insertWord (Trie t, char *word);
void removeWord (Trie t, char *word);

int findWord (Trie t, char *word); // Try implement this

void printKeys(Trie t);
void printKeysHelper (Trie t, char *word, int index);

int main (void) {
    Trie t = newTrie();
    insertWord(t, "lq");
    insertWord(t, "apple");
    insertWord(t, "ant");
    printKeys(t);
    return 0;
}

Trie newTrie () {
    Trie t = malloc (sizeof (struct trie));
    t->isEnd = 0;
    for (int i = 0; i < N_CHARS; i ++) {
        t->children[i] = NULL;
    }
    return t;
}

void insertWord (Trie t, char *word) {
    assert(t != NULL);
    Trie cur = t;
    for (int i = 0; word[i] != 0; i++) {
        int index = word[i] - 'a';
        if (cur->children[index] == NULL) {
            cur->children[index] = newTrie();
        }
        cur = cur->children[index];
    }
    cur->isEnd = 1;
}

void printKeys(Trie t) {
    char word[100];
    printKeysHelper(t, word, 0);
}

void printKeysHelper (Trie t, char *word, int index) {
    if (t == NULL) return;
    if (t->isEnd) {
        word[index] = 0;
        printf("%s\n", word);
    }
    for (int i = 0; i < N_CHARS; i++) {
        if (t->children[i] != NULL) {
            word[index] = i + 'a';
            printKeysHelper (t->children[i], word, index + 1);
        }
    }
}
