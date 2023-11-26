#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the TrieNode structure
typedef struct TrieNode {
    int count;
    int prefix;
    struct TrieNode *nextNode[26];
} TrieNode;

// Function to create a new TrieNode
TrieNode* createTrieNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->count = 0;
    node->prefix = 0;
    for (int i = 0; i < 26; i++) {
        node->nextNode[i] = NULL;
    }
    return node;
}

// Function to insert a new word into the trie
void insert(TrieNode *root, const char *str) {
    if (root == NULL || strlen(str) == 0) {
        return;
    }
    TrieNode *current = root;
    for (int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a';
        if (current->nextNode[index] == NULL) {
            current->nextNode[index] = createTrieNode();
        }
        current = current->nextNode[index];
        current->prefix++;
    }
    current->count++;
}

// Function to search for a word in the trie
int search(TrieNode *root, const char *str) {
    if (root == NULL || strlen(str) == 0) {
        return -1;
    }
    TrieNode *current = root;
    for (int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a';
        if (current->nextNode[index] == NULL) {
            return -1;
        }
        current = current->nextNode[index];
    }
    return (current->count == 0) ? -1 : current->count;
}

// Function to search for the number of words with a given prefix
int searchPrefix(TrieNode *root, const char *str) {
    if (root == NULL || strlen(str) == 0) {
        return -1;
    }
    TrieNode *current = root;
    for (int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a';
        if (current->nextNode[index] == NULL) {
            return -1;
        }
        current = current->nextNode[index];
    }
    return current->prefix;
}

int main() {
    TrieNode *root = createTrieNode();
    insert(root, "hello");
    insert(root, "hello");
    insert(root, "hello");
    insert(root, "helloworld");
    printf("%d\n", search(root, "hello"));       // Output: 3
    printf("%d\n", searchPrefix(root, "he"));    // Output: 4

    // Free memory (not shown for simplicity)
    return 0;
}
