
/* BST struct
typedef struct BSTNode *BSTLink;

typedef struct BSTNode {
	int value;
	BSTLink left, right;
} BSTNode;
*/

int BSTreeHeight(BSTree t) {
	if (t == NULL) return 0;
	int l = BSTreeHeight(t->left);
	int r = BSTreeHeight(t->right);
	if (l > r) return 1 + l;
	return 1 + r;
}

int countInternal (BSTree t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 0;
	return 1 + countInternal(t->left) + countInternal(t->right);
}

int nodeDepth (BSTree t, int key) {
	if (t == NULL) return -1;
	if (t->value == key) return 0;
	else if (key < t->value) {
		int depth = nodeDepth(t->left, key);
		if (depth == -1) return -1;
		return depth + 1;
	} else {
		int depth = nodeDepth(t->right, key);
		if (depth == -1) return -1;
		return depth + 1;
	}
}

// same as BSTreeHeight.
int BSTreeMaxBranchLen(BSTree t) {
	if (t == NULL) return 0;
	int l = BSTreeMaxBranchLen(t->left);
	int r = BSTreeMaxBranchLen(t->right);
	if (l > r) return 1 + l;
	return 1 + r;
}

int BSTWidth (BSTree t)
{
	if (t == NULL)
		return 0;
	else
		return 3 + BSTWidth (t->left) + BSTWidth (t->right);
}

// count all even values.
int countEven (BSTree t) {
    if (t == NULL) return 0;
    if (t->value%2 == 0) return t->value;
    return countEven (t->left) + countEven (t->right);
}

// are two trees identical? Values and shape.
// 0 is false.
// 1 is true.
int isIdentical (BSTree t1, BSTree t2) {
	if (t1 == NULL && t2 == NULL) return 1;
	if (t1 == NULL || t2 == NULL) return 0;
	if (t1->value != t2->value) return 0; // remove this line to just check shape.
	if (isIdentical(t1->left, t2->left) == 0) return 0;
	if (isIdentical(t1->right, t2->right) == 0) return 0;
	return 1;
}

// left and right branch have the same shape, reflected (disregard values).
// 0 is false.
// 1 is true.
int isSymmetric (BSTree t) {
	if (t == NULL) return 0;
	return isSymmetricHelper(t->left, t->right);
}

int isSymmetricHelper (BSTree t1, BSTree t2) {
	if (t1 == NULL && t2 == NULL) return 1;
	if (t1 == NULL || t2 == NULL) return 0;
	if (isSymmetricHelper(t1->left, t2->right) == 0) return 0;
	if (isSymmetricHelper(t1->right, t2->left) == 0) return 0;
	return 1;
}