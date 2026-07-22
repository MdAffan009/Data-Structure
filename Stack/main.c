#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct Stack
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}


void push(Stack *stack, int value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow!! \n");
        return;
    }

    stack->data[++stack->top] = value;
}


int main()
{
    Stack stack;

    isEmpty(&stack);
    initStack(&stack);

    push(&stack, 30);

    return 0;
}