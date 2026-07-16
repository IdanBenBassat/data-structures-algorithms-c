#pragma once
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at the beginning
void insertAtStart(Node** head, int value);

// Insert at the end
void insertAtEnd(Node** head, int value);

// Delete first node with matching value
bool deleteNode(Node** head, int value);

// Search for a node by value
Node* searchNode(Node* head, int value);

// Insert a new node after a node with specific value
bool insertAfter(Node* head, int afterValue, int newValue);

// Reverse the linked list
void reverseList(Node** head);

// Print the list
void printList(const Node* head);

// Free all nodes
void freeList(Node* head);
