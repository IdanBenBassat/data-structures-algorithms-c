#include <stdio.h>
#include "stack.h"

void initStack(Stack* s) 
{
    s->top = -1;
}

bool isEmpty(const Stack* s) 
{
    return s->top == -1;
}

bool isFull(const Stack* s)
{
    return s->top == STACK_SIZE - 1;
}

bool push(Stack* s, int value) 
{
    if (isFull(s)) {
        printf("Stack overflow\n");
        return false;
    }
    s->data[++(s->top)] = value;
    return true;
}

bool pop(Stack* s, int* result) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        return false;
    }
    *result = s->data[(s->top)--];
    return true;
}

bool peek(Stack* s, int* result) 
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty\n");
        return false;
    }
    *result = s->data[s->top];
    return true;
}

void printStack(const Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents (top to bottom): ");
    for (int i = s->top; i >= 0; i--) 
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
