## Tree Ddata Structures

**Binary Search Tree 二叉树**
- Time Complexity: O(log n); Balanced O(n) -> 所有叶节点在同一层（深度）
- 结构：root（树根）， leaf node（没有孩子的节点）, internal node（至少有一个孩子的结点）
- Each node has at most 2 children (LEFT and RIGHT)
- If balanced, all values in any left subtree are < root, all values in any right subtree are > root
- 节点数量: 所有左子树和右子树节点数的和，加上根节点 -> N = LN + RN + 1 -> recursion
- 最小高度: 在平衡二叉树中，h = log n
- 深度: 深度是从根节点到该节点的唯一路径上的边的数目。深度为k的二叉树至多有2的k次方-1个结点(k≥1)。

基本操作：（create bst/node, free, insert, find）wk4 lab

Define Tree structure:

<img width="553" alt="Screen Shot 2023-11-21 at 19 14 45" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/91f11709-0f66-4566-8396-a64e0bcc0b44">

Counting numbers of Leaves:
using recursion -> 
<img width="904" alt="Screen Shot 2023-11-21 at 19 20 53" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/c149bae1-21e4-410e-802b-fca992398f53">

Finding the Range of Bst:
<img width="939" alt="Screen Shot 2023-11-21 at 19 21 26" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/b62c2aa4-69e0-44a5-bc47-7cf54f5985e0">

Delete the leaves node:
<img width="934" alt="Screen Shot 2023-11-21 at 19 24 39" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/2d6c8ec8-b583-4862-ac12-d561acc82871">

Find the value in the BST which is closest to the given value:
<img width="949" alt="Screen Shot 2023-11-21 at 19 25 22" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/69d07ce6-bfde-4b3c-a475-cb62dee98616">


