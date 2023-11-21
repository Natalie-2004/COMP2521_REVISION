#include <stdio.h>
#include <stdlib.h>

// 定义结点
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Node;

void preorder (Node *node);
void inorder (Node *node);
void posorder (Node *node);

int main() {
    // 初始化结点
    Node n1;
    Node n2;
    Node n3;
    Node n4;

    // 赋予结点value
    n1.data = 5;
    n2.data = 6;
    n3.data = 7;
    n4.data = 8;

    // 把每个零散的结点连起来
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = NULL;
    n3.left = NULL;
    n3.right = NULL;
    n4.left = NULL;
    n4.right = NULL;

    printf("顺序遍历：\n");
    preorder(&n1);
    printf("中序遍历：\n");
    inorder(&n1);
    printf("后序遍历：\n");
    posorder(&n1);
}

// 顺序遍历： 根 -》 左 -》 右
void preorder (Node *node) {
    // base case: 
    if (node != NULL) {
        printf("%d\n", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// 中序遍历： 左 -》 根 -》右
void inorder (Node *node) {
    // base case:
    if (node != NULL) {
        inorder(node->left);
        printf("%d\n", node->data);
        inorder(node->right);
    };
}

// 后序遍历： 左 -》 右 -》 根
void posorder(Node *node) {
    if (node != NULL) {
        posorder(node->left);
        posorder(node->right);
        printf("%d\n", node->data);
    }
}

