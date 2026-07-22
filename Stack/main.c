#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAP 128
#define iNITIAL_CAP 2

typedef struct Stack
{
    int *data;
    int top;
    int size;
    int capacity;
} Stack;

// Initialzation
void initStack(Stack *stack)
{
    stack->top = -1;
    stack->size = 0;
    stack->capacity = iNITIAL_CAP;
    stack->data = malloc(iNITIAL_CAP * sizeof(int));

    if (!stack->data)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

// Reallocation
int *resize(Stack *stack)
{
    if (stack->capacity >= MAX_CAP)
    {
        stack->size = MAX_CAP;
    }

    int *temp = realloc(stack->data, stack->capacity * sizeof(int));

    if (!temp)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    return temp;
}

// Length Check
bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isFull(Stack *stack)
{
    return stack->size == MAX_CAP;
}

// Push(Adding on the top)
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow!! \n");
        return;
    }

    if (stack->size == stack->capacity)
    {
        stack->capacity *= 2;
        stack->data = resize(stack);
    }

    stack->data[++stack->top] = value;
    stack->size++;
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
    stack->size--;
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

    initStack(&stack);
    push(&stack, 40);
    push(&stack, 30);
    push(&stack, 20);
    push(&stack, 10);

    display(&stack);

    pop(&stack);
    peek(&stack);

    free(stack.data);

    return 0;
}