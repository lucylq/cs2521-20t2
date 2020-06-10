
typedef struct _node* List;

// List set up
List createNode (int val);
List createListFromArray (int *a, int size);
void freeList (List l);
void print (List l);

// Iterative and recursive length functions
int lengthIterative (List l);
int lengthRecursive (List l);
int sumRecursive (List L);

// Iterative and recursive mean functions
float meanIterative (List l);
float meanRecursive (List l);
float meanRecursive2 (List l);
float meanRecursiveHelper (List L, float* sum, int* count);

List reverseIterative (List L);
List reverseRecursive (List L, List prev);