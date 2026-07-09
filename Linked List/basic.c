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

int length(struct Node *head)
{
    struct Node *temp = head;

    int count = 0;

    while (temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
    
}

void insertAtBeginning(int value, struct Node **head, struct Node **tail)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = *head;


    if (length(*head) == 0)
    {
        *head = newNode;
        *tail = newNode;

        newNode->next = NULL;
    }

    else if (length(*head) == 1)
    {
        *head = newNode;
        newNode->next = temp;
        *tail = newNode->next;
    }
    
    else
    {
        *head = newNode;
        newNode->next = temp;
    }

}

void insertAtEnd(int value, struct Node **head, struct Node **tail)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        insertAtBeginning(value, head, tail);
        return;
    }

    (*tail)->next = newNode; //This overwrites the NULL to new Node
    *tail = newNode;
    
}

void insertAtPosition(int value, int index, struct Node **head, struct Node **tail)
{
    if (index < 0) return;

    if (index == 0)
    {
        insertAtBeginning(value, head, tail);
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

void deleteEnd(struct Node **head)
{

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    struct Node *temp = *head;

    if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
        return;
    }
    

    while (temp->next)
    {

        if (temp->next->next == NULL) 
        {
            free(temp->next);
            temp->next = NULL;
            return;
        }

        temp = temp -> next;
           
    }

}

void deleteAtPosition(int index, struct Node **head)
{
    if (index < 0) return;

    if (index == 0)
    {
        deleteStart(head);
        return;
    }

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    int count = 0;

    while (temp != NULL && count < index - 1)
    {
        temp = temp->next;
        count++;
    }   
    
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid Index!! \n");
        return;
    }
    

    struct Node *nextNode = temp->next->next;

    free(temp->next);
    temp->next = nextNode;

}

void cleanup(struct Node **head)
{
    while (*head != NULL)
    {
        deleteStart(head);
    }

    printf("Cleanup Successful!! \n");

}


void displayList(struct Node *head)
{
    struct Node *temp = head;

    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}


int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    insertAtBeginning(20, &head, &tail);

    insertAtEnd(30, &head, &tail);
    insertAtEnd(50, &head, &tail);

    insertAtBeginning(10, &head, &tail);

    insertAtPosition(40, 3, &head, &tail);

    displayList(head);

    printf("%d and %d \n", head->data, tail->data);
   
    cleanup(&head);

    return 0;
}