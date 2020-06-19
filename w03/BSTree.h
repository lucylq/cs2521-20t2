// BSTree.h ... interface to binary search tree ADT

#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode *BSTree;

// Tutorial Functions.
int BSTreeHeight (BSTree t);
int countInternal (BSTree t);
int nodeDepth (BSTree t, int key);
int BSTreeMaxBranchLen(BSTree t);
int BSTWidth (BSTree t);

// Other functions (Try them out!)
// count all even values.
int countEven (BSTree t);
// are two trees identical? 1 = true, 0 = false
int isIdentical (BSTree t1, BSTree t2);
// balanced: left and right branch differ by 1
int isBalanced (BSTree t);
// symmetric: left and right branch have the same shape, reflected (disregard values).
int isSymmetric (BSTree t);
int isSymmetricHelper (BSTree t1, BSTree t2);
// is sub a subtree of t?
int isSubTree (BSTree tree, BSTree sub);
int isSubTreeHelper (BSTree tree, BSTree sub);

// BSTree Functions.
// create an empty BSTree
BSTree newBSTree (void);
// free memory associated with BSTree
void dropBSTree (BSTree);
// display a BSTree
void showBSTree (BSTree);
// display BSTree root node
void showBSTreeNode (BSTree);

// print values in infix order
void BSTreeInfix (BSTree);
// print values in prefix order
void BSTreePrefix (BSTree);
// print values in postfix order
void BSTreePostfix (BSTree);
// print values in level-order
void BSTreeLevelOrder (BSTree);

// count #nodes in BSTree
int BSTreeNumNodes (BSTree);
// count #leaves in BSTree
int BSTreeNumLeaves (BSTree);

// insert a new value into a BSTree
BSTree BSTreeInsert (BSTree, int);
// check whether a value is in a BSTree
int BSTreeFind (BSTree, int);
// delete a value from a BSTree
BSTree BSTreeDelete (BSTree, int);

#endif
