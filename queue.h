#pragma once
#include <stdbool.h>

#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Initializes the queue
void initQueue(Queue* q);

// Adds a value to the queue
bool enqueue(Queue* q, int value);

// Removes a value from the queue into `result`
bool dequeue(Queue* q, int* result);

// Peeks at the front value without removing it
bool peekQueue(const Queue* q, int* result);

// Checks if the queue is empty
bool isQueueEmpty(const Queue* q);

// Checks if the queue is full
bool isQueueFull(const Queue* q);

// Clears the queue (resets indices)
void clearQueue(Queue* q);

// Prints the contents of the queue
void printQueue(const Queue* q);
