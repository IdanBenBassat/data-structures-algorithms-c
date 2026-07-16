#include <stdio.h>
#include "hash_table.h"

static int hash(int key) 
{
    return key % TABLE_SIZE;
}

void initHashTable(HashTable* ht) 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        ht->table[i].status = EMPTY;
        ht->table[i].key = 0;  // ערך סתמי, יתעדכן כשנכניס מפתח
    }
}

bool insert(HashTable* ht, int key) 
{
    int index = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (ht->table[probeIndex].status == EMPTY || ht->table[probeIndex].status == DELETED)
        {
            ht->table[probeIndex].key = key;
            ht->table[probeIndex].status = FILLED;
            return true;
        }
    }
    printf("Hash table is full\n");
    return false;
}

bool search(const HashTable* ht, int key) 
{
    int index = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (ht->table[probeIndex].status == EMPTY)
            return false;
        if (ht->table[probeIndex].status == FILLED && ht->table[probeIndex].key == key)
            return true;
    }
    return false;
}

bool deleteKey(HashTable* ht, int key)
{
    int index = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (ht->table[probeIndex].status == EMPTY)
            return false;
        if (ht->table[probeIndex].status == FILLED && ht->table[probeIndex].key == key) {
            ht->table[probeIndex].status = DELETED;
            return true;
        }
    }
    return false;
}

void printHashTable(const HashTable* ht) 
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        printf("[%d]: ", i);
        if (ht->table[i].status == EMPTY) 
        {
            printf("EMPTY\n");
        }
        else if (ht->table[i].status == FILLED) 
        {
            printf("%d\n", ht->table[i].key);
        }
        else if (ht->table[i].status == DELETED)
        {
            printf("DELETED\n");
        }
    }
}
