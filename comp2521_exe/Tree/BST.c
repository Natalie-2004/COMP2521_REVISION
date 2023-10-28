#include <stdio.h>
#include <stdlib.h>

// 特点， 在任意一个子树上面，根结点 > 左， 根结点 < 右;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree {
    Node *root;
} Tree;

void insert(Tree *tree, int value);
void preorder (Node *node);

// 用动态存储给树插入一个数字叫value
// 只用保存树的节点
void insert(Tree *tree, int value) {
    Node *node = malloc(sizeof(Node));

    // 初始化根结点
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    // 插入新节点
    // 为空，
    if (tree->root == NULL) {
        tree->root = node;
    }
    else {
        // *temp = 当前需要和value比较的节点
        // 用来确定新结点要被安放的位置
        Node *temp = tree->root;

        while (temp != NULL) {
            // 如果向左走，
            if (value < temp->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                } 
                // 否则继续往左走
                else {
                    temp = temp->left;
                }
            } else {
                // 往右边走
                if (temp->right == NULL) {
                    temp->right = node;
                    return;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
} 

void preorder (Node *node) {
    // base case: 
    if (node != NULL) {
        printf("%d\n", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

int main() {
    int arr[7] = {6, 3, 8, 2, 5, 1, 7};
    Tree tree;
    tree.root = NULL;
    // 把value放进节点
    for (int i = 0; i < 7; i++) {
        insert(&tree, arr[i]);
    }

    preorder(tree.root);
}