#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *node = malloc(sizeof(struct Node));

    node->data = value;
    node->next = NULL;

    return node;
}

void insertAtBeginning(int value, struct Node **head)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = *head;

    *head = newNode;
    newNode->next = temp;

}


int main()
{
    struct Node *head = NULL;

    insertAtBeginning(10, &head);


    return 0;
}