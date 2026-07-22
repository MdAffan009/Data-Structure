#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct Stack
{
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialzation
void initStack(Stack *stack)
{
    stack->top = -1;
}

// Length Check
bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Push(Adding on the top)
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow!! \n");
        return;
    }

    stack->data[++stack->top] = value;
}

// Pop(Deleting the top)
void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return;
    }

    stack->top--;
}

// Displaying the top element
void peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d \n", stack->data[stack->top]);
}

// Traversing through stack
void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->data[i]);
    }
}

int main()
{
    Stack stack;

    isEmpty(&stack);
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    peek(&stack);
    pop(&stack);
  
    printf("\n");

    display(&stack);

    return 0;
}