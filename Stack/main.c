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
        stack->capacity = MAX_CAP;
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

// Validation
void sizeValidation(Stack *stack, bool (*operation)(Stack *stack))
{

    bool result = operation(stack);

    if (operation == isEmpty)
    {
        printf(result ? "The Stack is Empty!!\n" : "The Stack isn't Empty.\n");
    }
    else if (operation == isFull)
    {
        printf(result ? "The Stack is Full!!\n" : "The Stack isn't Full.\n");
    }
}

// Push(Adding on the top)
void push(Stack *stack)
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

    int value;
    printf("Please Enter the value: ");
    scanf("%d", &value);

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

void interface()
{
    Stack stack;

    initStack(&stack);

    int choice;

    printf("Greetings!!");

    while (true)
    {
        printf("\n=================================\n");
        printf("         STACK OPERATIONS\n");
        printf("=================================\n");
        printf("1. Push\t\t2. Pop\n");
        printf("3. Is Empty\t4. Is Full\n");
        printf("5. Peek\t\t6. Display\n");
        printf("0. Exit\n");
        printf("=================================\n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Thanks for using this software!\n");
            break;

        case 1:
            push(&stack);
            printf("Operation Successful!");
            continue;

        case 2:
            pop(&stack);
            printf("Operation Successful!!");
            continue;

        case 3:
            sizeValidation(&stack, isEmpty);
            continue;

        case 4:
            sizeValidation(&stack, isFull);
            continue;

        case 5:
            peek(&stack);
            continue;

        case 6:
            display(&stack);
            continue;

        default:
            printf("Invalid Option try again! \n");
            continue;
        }

        break;
    }

    free(stack.data);
}

int main()
{
    interface();

    return 0;
}