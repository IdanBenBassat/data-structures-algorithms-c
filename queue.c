#include <stdio.h>
#include "queue.h"

void initQueue(Queue* q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isQueueEmpty(const Queue* q) 
{
    return q->size == 0;
}

bool isQueueFull(const Queue* q) 
{
    return q->size == QUEUE_SIZE;
}

bool enqueue(Queue* q, int value) 
{
    if (isQueueFull(q))
    {
        printf("Queue is full\n");
        return false;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = value;
    q->size++;
    return true;
}

bool dequeue(Queue* q, int* result) 
{
    if (isQueueEmpty(q)) 
    {
        printf("Queue is empty\n");
        return false;
    }
    *result = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->size--;
    return true;
}

bool peekQueue(const Queue* q, int* result) 
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return false;
    }
    *result = q->data[q->front];
    return true;
}

void clearQueue(Queue* q) 
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void printQueue(const Queue* q) 
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents (front to rear): ");
    for (int i = 0; i < q->size; i++) 
    {
        int index = (q->front + i) % QUEUE_SIZE;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}
