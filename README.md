# COMP2521 REVISION Outline

LeetCode and HackerRank exercises
<https://gist.github.com/jedavidson/1a99b8944897d532271fe164d4ce3049>

## Data Structure
- Trees, Graphs, Hash Tables, Heap, Tries

## Algorithm Analysis
- Times/Spacess Complexity
- main cases: loops recursion functions
- wrong case: ask 1. how many times does it run 
- (and then) + 1; (for each) * n

i.e in this case it's O(n)
```
int sum = 0;
for (int i = 0; i < n; i++) {
  sum += i % 3;
return sum
```
i.e in this case it's O(log n)
```
int f2(int n) {
if n <= 0 {
  return 0;
}
return n + f2(n/3)
}
```

``` O(n log n)
int f3(int n) {
int count = 0;
int sum = 0;
while (count < (n / 2))
  sum += f2(count)
  count++
}
return sum
```
## Sorting
- Stable Sorting
  If elements being sorted have the same value, then the order of those elements in the unsorted list, is the same in the sorted list.

- Unstable/Adaptive Sorting
  Elements with the same value aren't necessarily kept in the same order after sorted

- Time Complexity Table
  
<img width="650" alt="Screen Shot 2023-11-20 at 00 05 45" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/f00d67a4-4797-4314-baeb-1ac449790e83">

## Abstract Data Type (ADT)
- the interface of ADT is defined at .h file, while the actual implementation is at .c file
- the naming of ADT should starts at CAPITAL LETTER, and the functions are in pascalCase with the begin name of that ADT
- examples: Stack, Queue, Set, Multiset, Map, Graph, Priority Queue

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week03mon-adts.pdf>

## Tree
- Binary Search Trees
- Avl Trees
- Huffman Tree
- Red Black Tree(option)

## Searching Techniques
- bfs
- dfs

## Graph Algorithm
- Dijkstra
- Prim
- Krustal
