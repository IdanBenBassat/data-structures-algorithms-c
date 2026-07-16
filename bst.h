#pragma once

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Insert a value into the tree
BSTNode* insertBST(BSTNode* root, int value);

// Search for a value in the tree
BSTNode* searchBST(BSTNode* root, int value);

// Delete a value from the tree
BSTNode* deleteBSTNode(BSTNode* root, int value);

// Inorder traversal (LNR)
void inOrderBST(BSTNode* root);

// Preorder traversal (NLR)
void preOrderBST(BSTNode* root);

// Postorder traversal (LRN)
void postOrderBST(BSTNode* root);

// Print tree graphically (sideways)
void printTreeBST(BSTNode* root, int level);

// Free the entire tree
void freeTreeBST(BSTNode* root);
