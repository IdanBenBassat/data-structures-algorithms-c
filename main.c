#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
#include "bst.h"
#include "avl_tree.h"
#include "hash_table.h"
#include "sort.h"

// ==== Function Prototypes ====
void run_stack_demo();
void run_queue_demo();
void run_linked_list_demo();
void run_bst_demo();
void run_avl_demo();
void run_hash_table_demo();
void run_sorting_demo();

static void print_menu() 
{
    printf("\n===== Data Structures Menu =====\n");
    printf("1. Stack\n");
    printf("2. Queue\n");
    printf("3. Linked List\n");
    printf("4. Binary Search Tree (BST)\n");
    printf("5. AVL Tree\n");
    printf("6. Hash Table\n");
    printf("7. Sorting Algorithms\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() 
{
    int choice;
    while (1) 
    {
        print_menu();
        if (scanf_s("%d", &choice) != 1) 
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) 
        {
        case 1: run_stack_demo(); break;
        case 2: run_queue_demo(); break;
        case 3: run_linked_list_demo(); break;
        case 4: run_bst_demo(); break;
        case 5: run_avl_demo(); break;
        case 6: run_hash_table_demo(); break;
        case 7: run_sorting_demo(); break;
        case 0: printf("Exiting program.\n"); return 0;
        default: printf("Invalid option. Try again.\n");
        }
    }
}

// ===== Stack Demo =====
void run_stack_demo() 
{
    printf("\n--- Stack Demo ---\n");
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Pushed 10, 20, 30 onto stack.\n");

    printStack(&s);  // Expected: 30 20 10

    int value;
    if (peek(&s, &value))
        printf("Peek: %d\n", value);
    if (pop(&s, &value))
        printf("Pop: %d\n", value);
    if (peek(&s, &value))
        printf("Peek after pop: %d\n", value);

    printStack(&s);  // Expected: 20 10
}

// ===== Queue Demo =====
void run_queue_demo() 
{
    printf("\n--- Queue Demo ---\n");
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Enqueued 1, 2, 3.\n");

    printQueue(&q);  // Expected: 1 2 3

    int value;
    if (dequeue(&q, &value))
        printf("Dequeue: %d\n", value);
    if (peekQueue(&q, &value))
        printf("Front after dequeue: %d\n", value);

    printQueue(&q);  // Expected: 2 3
}

// ===== Linked List Demo =====
void run_linked_list_demo()
{
    printf("\n--- Linked List Demo ---\n");
    Node* list = NULL;

    insertAtEnd(&list, 10);
    insertAtStart(&list, 5);
    insertAtEnd(&list, 20);
    insertAfter(list, 10, 15);
    printf("Inserted 5, 10, 15, 20\n");

    printList(list);  // Expected: 5 10 15 20

    deleteNode(&list, 10);
    printf("After deleting 10:\n");
    printList(list);  // Expected: 5 15 20

    reverseList(&list);
    printf("After reversing:\n");
    printList(list);  // Expected: 20 15 5

    freeList(list);
}

// ===== BST Demo =====
void run_bst_demo() 
{
    printf("\n--- BST Demo ---\n");
    BSTNode* root = NULL;

    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);

    printf("In-order traversal: ");
    inOrderBST(root);  // Expected: 30 50 60 70 80
    printf("\n");

    root = deleteBSTNode(root, 70);
    printf("After deleting 70: ");
    inOrderBST(root);  // Expected: 30 50 60 80
    printf("\n");

    printTreeBST(root, 0);  // fixed: requires 'level' parameter
    freeTreeBST(root);
}

// ===== AVL Tree Demo =====
void run_avl_demo() 
{
    printf("\n--- AVL Tree Demo ---\n");
    AVLNode* root = NULL;

    root = insertAVL(root, 30);
    root = insertAVL(root, 20);
    root = insertAVL(root, 40);
    root = insertAVL(root, 10);

    inorderAVL(root);  // Expected: 10 20 30 40
    printf("\n");

    root = deleteAVL(root, 20);
    inorderAVL(root);  // Expected: 10 30 40
    printf("\n");

    printAVLTree(root, 0);  // fixed: requires 'level' parameter
    freeAVL(root);
}

// ===== Hash Table Demo =====
void run_hash_table_demo() 
{
    printf("\n--- Hash Table Demo ---\n");
    HashTable table;
    initHashTable(&table);

    insert(&table, 5);
    insert(&table, 15); // collision if size is small
    insert(&table, 25);

    printHashTable(&table);

    if (search(&table, 15))
        printf("15 found in table.\n");
    else
        printf("15 not found.\n");

    deleteKey(&table, 15);
    printf("Deleted 15.\n");

    printHashTable(&table);
}

// ===== Sorting Demo =====
void run_sorting_demo() 
{
    printf("\n--- Sorting Demo ---\n");
    int arr[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    printf("Bubble Sort:\n");
    bubbleSort(arr, size);
    printArray(arr, size);

    int arr2[] = { 64, 25, 12, 22, 11 };
    printf("Quick Sort:\n");
    quickSort(arr2, 0, size - 1);
    printArray(arr2, size);

    int arr3[] = { 64, 25, 12, 22, 11 };
    printf("Merge Sort:\n");
    mergeSort(arr3, 0, size - 1);
    printArray(arr3, size);

    compareSortTimes(arr, size);  // fixed: added array + size
}
