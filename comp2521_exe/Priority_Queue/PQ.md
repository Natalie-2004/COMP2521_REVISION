## Priority Queue
- Each element in a priority queue has a priority value, and the order of elements is determined by their priority rather than their insertion order.
- Very fast implementation, in between O(1) - O(n) time complexcity 
- We may involve **Heaps** into PQ

## Heaps
- A heap is a tree-based data structure which satisfies the heap property.
    - max heap -> the value in each node must be greater than or equal to the values in its children
    - min heap -> the value in each node must be less than or equal to the values in its children
- Aka. **binary heap**: A complete binary tree (the storage structure is the same as a binary tree, 
    but the elements in the tree are stored only at the low index)
- A binary Heap also needs to satisfy such *completeness property*
    - all levels of the tree must be fully filled and the last level must be filled from left to right
    - always contains log(n) + 1 levels where n is the num of nodes
- We usually set ind 1 of the array contains the root items, where
    - left child ind: 2i
    - right child ind: 2i + 1
    - find a node' partents: i/2

Heap ADT:
```c
struct heap {
    int *items;
    int numItems;
    int capacity
}
```

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week09mon-priority-queues.pdf>
