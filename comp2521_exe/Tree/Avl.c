#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the AVL tree
typedef struct AVLNode {
    int item;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

int height(AVLNode *N);
int max(int a, int b);
AVLNode* newNode(int item);
AVLNode *rotateRight(AVLNode *y);
AVLNode *rotateLeft(AVLNode *x);
AVLNode* avlInsert(AVLNode* node, int item);
void inOrder(AVLNode *root);

// A utility function to right rotate subtree rooted with y
AVLNode *rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
AVLNode *rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// A utility function to get the height of the tree
int height(AVLNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
AVLNode* newNode(int item) {
    AVLNode* node = (AVLNode*) malloc(sizeof(AVLNode));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return(node);
}

// Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree.
AVLNode* avlInsert(AVLNode* node, int item) {
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(item));

    if (item < node->item)
        node->left = avlInsert(node->left, item);
    else if (item > node->item)
        node->right = avlInsert(node->right, item);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
    int balance = height(node->left) - height(node->right);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && item < node->left->item)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && item > node->right->item)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && item > node->left->item) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && item < node->right->item) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void inOrder(AVLNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->item);
        inOrder(root->right);
    }
}

int main() {
    AVLNode *root = NULL;

     /* Constructing an unbalanced tree */
    // Insert 10. Tree is still balanced.
    //    10
    root = avlInsert(root, 10);

    // Insert 20. Tree is still balanced.
    //    10
    //      \
    //      20
    root = avlInsert(root, 20);

    // Insert 30. Tree becomes unbalanced (Right Right case).
    //    10
    //      \
    //      20
    //        \
    //        30
    // After rotation, tree becomes:
    //    20
    //   /  \
    // 10   30
    root = avlInsert(root, 30);

    // Insert 40. Tree is still balanced.
    //      20
    //     /  \
    //    10  30
    //          \
    //          40
    root = avlInsert(root, 40);

    // Insert 50. Tree becomes unbalanced (Right Right case).
    //      20
    //     /  \
    //    10  30
    //          \
    //          40
    //            \
    //            50
    // After rotation, tree becomes:
    //       30
    //      /  \
    //     20  40
    //    /     \
    //   10     50
    root = avlInsert(root, 50);

    // Insert 25. Tree becomes unbalanced (Left Right case).
    //       30
    //      /  \
    //     20  40
    //    /     \
    //   10     50
    //     \
    //     25
    // After rotations, tree becomes balanced.
    root = avlInsert(root, 25);

    printf("In-order traversal of the constructed AVL tree is \n");
    inOrder(root);

    return 0;
}