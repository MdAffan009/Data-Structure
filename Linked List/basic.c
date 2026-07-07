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

void insertAtEnd(int value, struct Node **head)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    struct Node *temp = *head;

    while (temp->next) //It will access the NEXT memeber in temp and check whether if it is NULL. If it isn't, the loop is true.
        temp = temp->next; //This updates the temp pointer, which will now point to NEXT Node.

    temp->next = newNode; //This overwrites the NULL to new Node
    
}

void displayList(struct Node *head)
{
    struct Node *temp = head;

    while (temp)
    {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL \n");
}


int main()
{
    struct Node *head = NULL;

    insertAtBeginning(10, &head);
    insertAtEnd(20, &head);
    insertAtEnd(40, &head);

    displayList(head);

    return 0;
}