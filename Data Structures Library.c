#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

static BSTNode* createNode(int value) 
{
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if (!node) 
    {
        printf("Memory allocation failed (createNode)\n");
        return NULL;
    }
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

BSTNode* insertBST(BSTNode* root, int value) 
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);

    return root;
}

BSTNode* searchBST(BSTNode* root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return searchBST(root->left, value);
    else
        return searchBST(root->right, value);
}

// Helper: find the minimum node in a tree
static BSTNode* findMinBST(BSTNode* root) 
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
BSTNode* deleteBSTNode(BSTNode* root, int value) 
{
    if (root == NULL)
        return NULL;

    if (value < root->data) 
    {
        root->left = deleteBSTNode(root->left, value);
    }
    else if (value > root->data) 
    {
        root->right = deleteBSTNode(root->right, value);
    }
    else 
    {
        // Node found
        if (root->left == NULL) 
        {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        else 
        {
            // Two children
            BSTNode* temp = findMinBST(root->right);
            root->data = temp->data;
            root->right = deleteBSTNode(root->right, temp->data);
        }
    }

    return root;
}

// Traversals
void inOrderBST(BSTNode* root)
{
    if (root) 
    {
        inOrderBST(root->left);
        printf("%d ", root->data);
        inOrderBST(root->right);
    }
}

void preOrderBST(BSTNode* root) 
{
    if (root) 
    {
        printf("%d ", root->data);
        preOrderBST(root->left);
        preOrderBST(root->right);
    }
}

void postOrderBST(BSTNode* root) 
{
    if (root)
    {
        postOrderBST(root->left);
        postOrderBST(root->right);
        printf("%d ", root->data);
    }
}

// Print the tree structure (rotated sideways)
void printTreeBST(BSTNode* root, int level) 
{
    if (root == NULL)
        return;

    printTreeBST(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("\t");
    printf("%d\n", root->data);

    printTreeBST(root->left, level + 1);
}

void freeTreeBST(BSTNode* root) 
{
    if (root) 
    {
        freeTreeBST(root->left);
        freeTreeBST(root->right);
        free(root);
    }
}
