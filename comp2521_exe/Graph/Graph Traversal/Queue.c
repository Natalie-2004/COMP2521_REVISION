// Implementation of the Queue ADT using a linked list

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

struct queue {
    struct node *head;
    struct node *tail;
    int size;
}

struct node {
    Item item;
    struct node *next;
}

static struct node *newNode(Item it);

// Creates a new, empty Queue
Queue QueueNew(void) {
    Queue q = malloc(sizeof(struct queue));

    if (q == NULL) {
        fprintf(sterr, "error: out of memory");
        exit(EXIT_FAILURE);
    } ]

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

// free memory allocated to a Queue
void QueueFree(Queue q) {
    struct node *curr = q->head;

    while (curr->next != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(q);
}

// Adds an item to the end of a queue
void QueueEnqueue(Queue q, Item it) {
    struct node *n = newNode(it);

    if (q->size == 0) {
        q->head = 0;
    } else {
        q->tail->next = 0;
    }
    q->tail = n;
    q->size++;
}

static struct node *newNode (Item it) {
    struct node *n = malloc(sizeof(*n));

    if (n == NULL) {
        fprintf(stderr, "error: out of memory");
        exit(EXIT_FAILURE);
    }

    n->item = it;
    n->next = NULL;
    return n;
}

// Removes an item from the front of a Queue
// We assumes that the Queue is not empty
Item QueueDequeue(Queue q) {
    if (q->size == 0) {
        fprintf(stderr, "error: queue is empty");
        return 0;
    }

    struct node *newHead = q->head->next;
    Item it = q->head->item;

    free(q->head);

    q->head = newHead;

    if (newHead == NULL) {
        q->tail = NULL;
    }

    q->size--;

    return it;
}


// gets the num of items in a Queue
int QueueSize(Queue q) {
    return q->size;
}

// Gets the item at the front of a Queue without removing it
// Assume that the Queue is not empty
Item QueuePeek(Queue q) {
    if (q->size == 0) {
        fprintf(stderr, "error: queue is empty");
        return 0;
    }

    return q->head->item;
}
