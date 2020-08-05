typedef struct list * List;
struct list {
    int val;
    List next;
};

List head (List l);
List tail (List l);
int empty (List l);

void print (List l);
List arrayToList (int *a, int len);
List createNode (int v);
void freeList (List l);