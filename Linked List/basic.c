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

void insertAtPosition(int value, int index, struct Node **head)
{
    if (index < 0) return;

    if (index == 0)
    {
        insertAtBeginning(value, head);
        return;
    }
    
    
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        printf("The List is Empty...\n");
        free(newNode);
        return;
    }
    
    int count = 0;
    struct Node *temp = *head;

    while (temp != NULL && count < index - 1)
    {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL)
    {
        printf("Invalid Index!! \n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;

}


void deleteStart(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = temp->next;
    free(temp);

}



void displayList(struct Node *head)
{
    struct Node *temp = head;

    while (temp)
    {
        printf("%d -> ", temp->data);
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
    insertAtPosition(30, 2, &head);
    displayList(head);

    deleteStart(&head);
    displayList(head);

    return 0;
}