
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int minDiff(struct node *t, int l) {
    int arr[1024];
    int size = 0;
    printLev(t, 0, l, arr[1024], size);
    return -1;
}

// do a print level traversal first, and then add into arr
void printLev(struct node *t, int currL, int l, int arr[1024], int *size) {
    if (t == NULL) {
        return;
    } 

    if (currL == l) {
        printf("%d\n", t->key);
        arr[*size] = t->key;
        *size += 1;
    } else if (currL < l) {
        printLev(t->left, currL + 1, l, arr, size);
        printLev(t->right, currL + 1, l, arr, size);
    } else {
        return;
    }
}

