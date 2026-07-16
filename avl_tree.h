#pragma once

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Insert a value into the AVL tree
AVLNode* insertAVL(AVLNode* root, int key);

// Delete a value from the AVL tree
AVLNode* deleteAVL(AVLNode* root, int key);

// Traverse the tree in-order
void inorderAVL(AVLNode* root);

// Print the AVL tree structure (sideways)
void printAVLTree(AVLNode* root, int level);

// Free all memory used by the tree
void freeAVL(AVLNode* root);
