# Balanced Trees

## Splay Trees
For every operation, splay the affected node to the top. Splay using tree rotations: L, R, LL, RR, LR, RL.

Operations:
- Insert: insert node at leaf, splay to root. 
- Find: walk to node, splay the node to root. If it doesn't exist, splay the last accessed node to the root.
- Delete: delete node, splay the parent of the deleted node to the root.

### Analysis
- Amortized O(logn) performance for each operation. In the long run, the splays tend to balance the tree.
- Worst case O(n), when tree is a linked list and search key is at the bottom.
- Best case O(1), when searching identical keys repeatedly.
- In general, fast access to recently used keys, as they will be near the top of the tree from a previous splay.

## AVL Trees
For every operation, rebalance the tree using left and right rotations.

Operations:
- Insert: insert node at leaf, rebalance.
- Find: find.
- Delete: delete node, rebalance.
- Balanced: |height (left) - height (right)| < 1

### Analysis
- O(logn) performance for each operation. Very consistent. 
- Requires an extra field in the tree to store the height of the current node.

## 234 Trees
B-tree that has up to 3 values and up to 4 children. Ordering is maintained in a similar way to a binary tree: given a node containing values (x, y, z), the four possible children contain values within the ranges: [, x), (x,z), (y, z), (z,]

- Insertion: insert at leaf, if full, promote the second value in the node.
- Find: as with a bst, except comparisons with each value in the node must be made.

### Analysis
- O(logn) performance for each operation.
- Insertion and deletion are complicated, many cases to consider.

## Red Black Trees
- Each node is red or black
- No two red nodes can appear consecutively
- See lecture notes for the insertion/deletion cases for red black tree

Operations
- Insert: insert as a red node at leaf, re-color.
- Find: find
- Delete: delete node, recolor. 
- Balanced: number of black nodes on the left subtree = number of black nodes on the right subtree. This means that one subtree is at most twice as large as the other subtree (where one subtree has red-black alternating, and the other has all black)

### Analysis
- O(logn) performance for each operation.
- Requires an extra bit to store the color of a node.
- Insertion and deletion are complicated, many cases to consider.

### Comparison to AVL
- Faster insertion and deletion, as the definition of balanced is looser.
- Slower find, as the tree is not guaranteed to be height balanced like an AVL tree. 
- Requires less memory space if the color field is implemented as a bit. AVL tree requires an int to store the height.