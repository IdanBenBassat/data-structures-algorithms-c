#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void insertAtStart(Node** head, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed (insertAtStart)\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed (insertAtEnd)\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
    }
    else 
    {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

bool deleteNode(Node** head, int value) 
{
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return false;

    if (prev == NULL) 
    {
        *head = temp->next;
    }
    else 
    {
        prev->next = temp->next;
    }

    free(temp);
    return true;
}

Node* searchNode(Node* head, int value)
{
    while (head != NULL) 
    {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

bool insertAfter(Node* head, int afterValue, int newValue) 
{
    Node* target = searchNode(head, afterValue);
    if (!target)
        return false;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) 
    {
        printf("Memory allocation failed (insertAfter)\n");
        return false;
    }

    newNode->data = newValue;
    newNode->next = target->next;
    target->next = newNode;

    return true;
}

void reverseList(Node** head) 
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void printList(const Node* head) 
{
    printf("Linked List: ");
    while (head != NULL) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) 
{
    while (head != NULL) 
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
