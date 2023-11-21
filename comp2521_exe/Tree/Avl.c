#include <stdio.h>
#include <stdlib.h>

struct node *rotateRight(struct node *root);
struct node *rotateLeft(struct node *root);
struct node* newNode(int key);
struct node* insert(struct node* node, int key);
void inorder(struct node *root);
void printTree(struct node *root, int space);
void bstPreOrder(struct node *root);

// Define a structure for tree nodes.
struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *rotateRight(struct node *root) {
    // If the root is NULL or the left child of the root is NULL, rotation is not possible.
    if (root == NULL || root->left == NULL) return root;

    // The new root will be the left child of the current root.
    struct node *newRoot = root->left;

    // The right subtree of the new root will now become the left subtree of the original root.
    root->left = newRoot->right;

    // The original root becomes the right child of the new root.
    newRoot->right = root;

    // Return the new root of the subtree after rotation.
    return newRoot;
}

struct node *rotateLeft(struct node *root) {
    // If the root is NULL or the right child of the root is NULL, rotation is not possible.
    if (root == NULL || root->right == NULL) return root;

    // The new root will be the right child of the current root.
    struct node *newRoot = root->right;

    // The left subtree of the new root will now become the right subtree of the original root.
    root->right = newRoot->left;

    // The original root becomes the left child of the new root.
    newRoot->left = root;

    // Return the new root of the subtree after rotation.
    return newRoot;
}

// Function to create a new tree node.
struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node with a given key in the BST.
struct node* insert(struct node* node, int key) {
    // If the tree is empty, return a new node.
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree.
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer.
    return node;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void bstPreOrder(struct node *root) {
	if (root == NULL) return;

	printf("%d ", root->key);
	bstPreOrder(root->left);
	bstPreOrder(root->right);
}

// Driver program to test the above functions
int main() {
    struct node *root = NULL;

    // Constructing a more complex BST
    //         30
    //        /  \
    //       20  40
    //      /  \
    //     10  25
    //       \
    //        15
    //        /
    //        12
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 12);

    printf("Preorder traversal of the original tree: ");
    bstPreOrder(root);
    printf("\n");

    // Perform right rotation on the root
    root = rotateRight(root);
    printf("Inorder traversal after right rotation on root: ");
    inorder(root);
    printf("\n");

    // For the sake of example, let's perform a left rotation on the right child of the current root
    root->right = rotateLeft(root->right);
    printf("Inorder traversal after left rotation on right child: ");
    inorder(root);
    printf("\n");

    return 0;
}

