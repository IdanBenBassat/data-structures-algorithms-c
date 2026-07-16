#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

static int height(AVLNode* node) 
{
    return node ? node->height : 0;
}

static int maxAVL(int a, int b)
{
    return (a > b) ? a : b;
}

static AVLNode* createAVLNode(int key)
{
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    if (!node) 
    {
        printf("Allocation failed\n");
        return NULL;
    }
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

static AVLNode* rightRotate(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxAVL(height(y->left), height(y->right)) + 1;
    x->height = maxAVL(height(x->left), height(x->right)) + 1;

    return x;
}

static AVLNode* leftRotate(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxAVL(height(x->left), height(x->right)) + 1;
    y->height = maxAVL(height(y->left), height(y->right)) + 1;

    return y;
}

static int getBalance(AVLNode* node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* insertAVL(AVLNode* node, int key) 
{
    if (!node) return createAVLNode(key);

    if (key < node->data)
        node->left = insertAVL(node->left, key);
    else if (key > node->data)
        node->right = insertAVL(node->right, key);
    else
        return node;

    node->height = 1 + maxAVL(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

static AVLNode* minValueNode(AVLNode* node)
{
    AVLNode* current = node;
    while (current->left)
        current = current->left;
    return current;
}

AVLNode* deleteAVL(AVLNode* root, int key) 
{
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteAVL(root->left, key);
    else if (key > root->data)
        root->right = deleteAVL(root->right, key);
    else 
    {
        if (!root->left || !root->right) 
        {
            AVLNode* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        AVLNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteAVL(root->right, temp->data);
    }

    root->height = 1 + maxAVL(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) 
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) 
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderAVL(AVLNode* root) 
{
    if (root) 
    {
        inorderAVL(root->left);
        printf("%d ", root->data);
        inorderAVL(root->right);
    }
}

void printAVLTree(AVLNode* root, int level)
{
    if (!root) return;

    printAVLTree(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("\t");
    printf("%d\n", root->data);

    printAVLTree(root->left, level + 1);
}

void freeAVL(AVLNode* root) {
    if (root) {
        freeAVL(root->left);
        freeAVL(root->right);
        free(root);
    }
}
