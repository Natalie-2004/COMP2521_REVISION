## Tree Data Structures

### Binary Search Tree 二叉树
- Time Complexity: O(log n); Balanced O(n) -> 所有叶节点在同一层（深度）
- 结构：root（树根）， leaf node（没有孩子的节点）, internal node（至少有一个孩子的结点）
- Each node has at most 2 children (LEFT and RIGHT)
- If balanced, all values in any left subtree are < root, all values in any right subtree are > root
- 节点数量: 所有左子树和右子树节点数的和，加上根节点 -> N = LN + RN + 1 -> recursion
- 最小高度: 在平衡二叉树中，h = log n
- 深度: 深度是从根节点到该节点的唯一路径上的边的数目。深度为k的二叉树至多有2的k次方-1个结点(k≥1)。

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week03wed-bsts.pdf>

基本操作：（create bst/node, free, insert, find）wk4 lab

**Define Tree structure:**
<img width="904" alt="Screen Shot 2023-11-21 at 19 14 45" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/91f11709-0f66-4566-8396-a64e0bcc0b44">

**Counting numbers of Leaves:**
using recursion -> 
<img width="904" alt="Screen Shot 2023-11-21 at 19 20 53" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/c149bae1-21e4-410e-802b-fca992398f53">

**Couting Nodes:**
<img width="900" alt="Screen Shot 2023-11-21 at 19 50 20" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/1e3baea5-dd74-46ba-aca8-64651e71f178">

**Finding the Range of Bst:**
<img width="939" alt="Screen Shot 2023-11-21 at 19 21 26" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/b62c2aa4-69e0-44a5-bc47-7cf54f5985e0">

**Delete the leaves Node:**
- 如果要删除leave并保证它是平衡二叉树要复杂很多，考虑四种情况
  1. 直接删除叶子结点-》两边都没有孩子
  2. 被删除结点没有右子树 -》 用左子树根结点代替
  3. 被删除结点没有左子树 -》 用右子树根结点代替
  4. 左右都有孩子
<img width="934" alt="Screen Shot 2023-11-21 at 19 24 39" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/2d6c8ec8-b583-4862-ac12-d561acc82871">

**Find the value in the BST which is closest to the given value:**
<img width="949" alt="Screen Shot 2023-11-21 at 19 25 22" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/69d07ce6-bfde-4b3c-a475-cb62dee98616">

**Tree Traversal**
大部分涉及Recursion 归递
其实归递 i.e TreeBST(root->left) 本质就是Depth First Search
从根出发，一直到左子树的叶子结点，停止。
（如果开头的base case是 !root return root），则马上返回叶子结点。

- PreOrder 顺序遍历： 根 -》 左 -》 右
<img width="900" alt="Screen Shot 2023-11-21 at 19 52 25" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/bc9e411e-b169-465c-8d8d-13feb112d62d">

- InOrder 中序遍历： 左 -》 根 -》右
<img width="900" alt="Screen Shot 2023-11-21 at 19 53 15" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/94b2de69-06e4-4e73-89fa-dc1586bf9418">

- PostOrder 后序遍历： 左 -》 右 -》 根
<img width="900" alt="Screen Shot 2023-11-21 at 19 53 40" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/3ac5553a-f189-41fa-a3a2-e81f38965214">

- LeaveOrder 层序遍历： （即逐层地，从左到右访问所有节点）
**涉及Queue，有Queue.h**
<img width="900" alt="Screen Shot 2023-11-21 at 19 56 55" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/9e3aea9c-cf85-4256-bc0a-6d50d8a94be9">

### Balanced BST 平衡二叉树 -> AVL Tree (in particular)
- 二叉树要满足每个结点的平衡因子的绝对值（左子树 - 右子树）不大于1才能叫平衡二叉树。
- <img width="301" alt="Screen Shot 2023-11-21 at 23 55 24" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/044a4538-1cf4-4ee1-a8d6-bcde174b11f4">
- 二叉树旋转（左旋，右旋，左右旋，右左旋） -》 查看ipad笔记
<img width="843" alt="Screen Shot 2023-11-21 at 23 34 25" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/bea64760-80f8-4cd7-b7d8-a2970992a6f4">
<img width="843" alt="Screen Shot 2023-11-21 at 23 34 41" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/6da65401-f57b-4d97-a08c-d6488d7db728">

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week04mon-balanced-bsts.pdf>

### Tries(Prefix Tree) 字典树
- 一种哈希树的变种, 特点空间换时间
- Adv: Use the common prefix of the string to reduce query time and minimize unnecessary string comparisons
- The root node contains no characters, and every node except the root node contains only one character.
- From the root node to a node, the characters that pass through the path are connected, which is the string corresponding to the node.
- All children of each node contain different characters.
- Has Time complexity O(L), the length of string for insertion, search and deletion
- Has Space O(nR), where n is the total number of characters in all keys, and R is the size of the underlying alphabet (e.g 26)

<img width="800" alt="Screen Shot 2023-11-26 at 14 25 57" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/ffdb0d1d-de7a-465b-8e0e-11553543553d">

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week09wed-tries.pdf>
