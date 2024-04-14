
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

static BSTree newNode(int value) {
	BSTree newNode = malloc(sizeof(struct BSTNode));
    if (newNode == NULL) {
        return NULL;  // Memory allocation failed
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTree BSTreeInsert(BSTree t, int val) {

	if (t == NULL) return newNode(val);
	if (val == t->value) return t;
	
	if (val < t->value) {
		t->left = BSTreeInsert(t->left, val);
	} else if (val > t->value) {
		t->right = BSTreeInsert(t->right, val);
	}

	return t;
}

