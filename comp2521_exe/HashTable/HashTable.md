## Hsah Table
- Takes a key as input and computes an index. Key index range: 0 ~ abs(N-1) where n is the size of array
- Buckets or Slots: The hash table stores data in an array-like structure, where each slot can hold an item or a pointer to an item.
- Collision Resolution: When two keys hash to the same index, a collision occurs. Common methods to resolve collisions include chaining (where each bucket holds multiple items, typically using a linked list) and open addressing (where the algorithm probes the hash table to find an empty slot).
- Efficient in Insertion, Search/Retrieve, Deletion

Time Complexity:
    - Lookup for a value O(1)
    - Lookup for a key O(n)

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week08mon-hash-tables.pdf>
