#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAP 128
#define INITIAL_CAP 2

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
    stack->capacity = INITIAL_CAP;
    stack->data = malloc(INITIAL_CAP * sizeof(int));

    if (!stack->data)
    {
        printf("relloc failed\n");
        exit(EXIT_FAILURE);
    }
}

// Reallocation
int *resize(Stack *stack)
{
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
        if (stack->capacity * 2 > MAX_CAP)
            stack->capacity = MAX_CAP;
        else
            stack->capacity *= 2;

        stack->data = resize(stack);
    }

    stack->data[++stack->top] = value;
    stack->size++;
}

// Pop(Deleting the top)
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int value = stack->data[stack->top];
    stack->top--;
    stack->size--;

    return value;
}

// Displaying the top element
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack->data[stack->top];
}

// Traversing through stack
void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack:\n");

    for (int i = stack->top; i >= 0; i--)
    {
        printf("| %d |\n", stack->data[i]);
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
            int value;
            printf("Please Enter the value: ");
            if (scanf("%d", &choice) != 1)
            {
                printf("Invalid input\n");
                break;
            }

            push(&stack, value);
            printf("Operation Successful!");
            continue;

        case 2:
            printf("Successfully delted %d !!", pop(&stack));
            continue;

        case 3:
            printf(isEmpty(&stack) ? "The Stack is empty" : "The Stack isn't empty");
            continue;

        case 4:
            printf(isFull(&stack) ? "The Stack is Full" : "The Stack isn't Full");
            continue;

        case 5:
            printf("%d ", peek(&stack));
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