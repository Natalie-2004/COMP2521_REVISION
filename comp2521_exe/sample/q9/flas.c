
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node *flas(struct node *l) {
    // TODO
    return NULL;
}

int increase_length(struct node *l) {
    int length = 0;

    while(l != NULL && l->next != NULL) {
        if (l->value >= l->next->value) {
            return length;
        }
    }
}

