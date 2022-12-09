## Binary Tree

---

- atmost two child nodes
- n node -> n-1 edges
- degree -> no of direct children
- binary tree -> degree 2

---

> Types of binary tree:

- Full or strict Binary Tree  
  All nodes have either 0 or 2 nodes

- Perfect Binary Tree  
  Internal nodes have 2 children + all leaf nodes are on same level

- Complete Binary Tree  
  All levels are completely filled except posssibly the last level +
  last levele must have its keys as left as possible.

- Degenerate Tree  
  Parent node has exactly one child

- Skewed Trees  
  - Left Skewed
  - Right Skewed

---

> REPRESENTATION:

- Array :
  stores nodes from left to right at each level in a single array, place NULL in place of no children in a level

  - Linked REPRESENTATION:
    - left<- root ->right

---

> TRAVERSAL:

- Inorder: left -> root -> right
- Preorder: root -> left -> right
- Postorder: left -> right -> root

---

AVL Tree

- Height balanced binary search tree.
- Height difference is not more than one.
- Balanced factor = height of right subtree - height of left subtree.
- |B.f| <= 1
