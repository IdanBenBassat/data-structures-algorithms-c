#pragma once
#include <stdbool.h>

#define TABLE_SIZE 10

typedef enum {
    EMPTY,
    FILLED,
    DELETED
} SlotStatus;

typedef struct {
    int key;
    SlotStatus status;
} HashSlot;

typedef struct {
    HashSlot table[TABLE_SIZE];
} HashTable;

// Initializes the hash table
void initHashTable(HashTable* ht);

// Inserts a value into the hash table
bool insert(HashTable* ht, int key);

// Searches for a value
bool search(const HashTable* ht, int key);

// Deletes a value
bool deleteKey(HashTable* ht, int key);

// Prints the table contents
void printHashTable(const HashTable* ht);
