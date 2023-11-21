## Tree Ddata Structures

**Binary Search Tree 二叉树**
- Time Complexity: O(log n)
- 结构：root（树根）， leaf node/child node（没有孩子的节点）, internal node（至少有一个孩子的结点）
- Each node has at most 2 children (LEFT and RIGHT)
- If balanced, all values in any left subtree are < root, all values in any right subtree are > root
- 节点数量: 所有左子树和右子树节点数的和，加上根节点 -> N = LN + RN + 1 -> recursion
- 最小高度: 在平衡二叉树中，h = log n
- 深度: 深度是从根节点到该节点的唯一路径上的边的数目。深度为k的二叉树至多有2的k次方-1个结点(k≥1)。
