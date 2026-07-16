#pragma once
#include <stdbool.h>

#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

// Initializes the stack
void initStack(Stack* s);

// Pushes a value onto the stack
bool push(Stack* s, int value);

// Pops a value from the stack into `result`
bool pop(Stack* s, int* result);

// Gets the top value without removing it
bool peek(Stack* s, int* result);

// Prints the contents of the stack
void printStack(const Stack* s);

// Checks if the stack is empty
bool isEmpty(const Stack* s);

// Checks if the stack is full
bool isFull(const Stack* s);
