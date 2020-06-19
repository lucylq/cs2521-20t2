CC=gcc
CFLAGS=-Wall -Werror -g
OBJS=bst.o BSTree.o
BINS=bst

all : $(BINS)

bst : $(OBJS)
	$(CC) -o bst $(OBJS)

bst.o : bst.c BSTree.h
BSTree.o : BSTree.c BSTree.h 

clean :
	rm -fr $(BINS) $(OBJS)



