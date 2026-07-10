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


    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;

        newNode->next = NULL;
    }
    
    else
    {
        newNode->next = *head;
        *head = newNode;
    }

}

void insertAtEnd(int value, struct Node **head, struct Node **tail)
{

    if (*head == NULL)
    {
        insertAtBeginning(value, head, tail);
        return;
    }

    struct Node *newNode = createNode(value);

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

    if (newNode->next == NULL) *tail = newNode;

}


void deleteStart(struct Node **head, struct Node **tail)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = temp->next;

     if (*head == NULL) *tail = NULL;

    free(temp);

}

void deleteEnd(struct Node **head, struct Node **tail)
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
        *tail = NULL;

        free(temp);
        return;
    }
    

    while (temp->next)
    {

        if (temp->next->next == NULL) 
        {
            free(temp->next);
            temp->next = NULL;
            *tail = temp;
            return;
        }

        temp = temp -> next;
           
    }

}

void deleteAtPosition(int index, struct Node **head, struct Node **tail)
{
    if (index < 0) return;

    if (index == 0)
    {
        deleteStart(head, tail);
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
    

    struct Node *toDelete = temp->next;
    struct Node *nextNode = toDelete->next;

    if (nextNode == NULL)  *tail = temp; //We just deleted the Last Node

    free(toDelete);
    temp->next = nextNode;

}

void search(int value, struct Node *head)
{
    int count = 0;
    struct Node *temp = head;

    while (temp)
    {
        if (temp->data == value)
        {
            printf("Element found at %d index \n", count);
            return;
        }

        temp = temp->next;
        count++;
    }
    
    printf("Element not found \n");
}

void update(int value, int index, struct Node *head)
{
    if (index < 0) return;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int count = 0;
    struct Node *temp = head;

    while (temp != NULL && count < index)
    {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL)
    {
        printf("Invalid Index!! \n");
        return;
    }

    temp->data = value;

}


void cleanup(struct Node **head, struct Node **tail)
{
    while (*head != NULL)
    {
        deleteStart(head, tail);
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
    insertAtEnd(60, &head, &tail);
    insertAtEnd(70, &head, &tail);

    insertAtBeginning(10, &head, &tail);

    displayList(head);
    insertAtPosition(40, 3, &head, &tail);
    displayList(head);

    deleteStart(&head, &tail);
    displayList(head);

    deleteEnd(&head, &tail);
    displayList(head);

    deleteAtPosition(1, &head, &tail);
    displayList(head);

    search(60, head);
    update(55, 2, head);
    displayList(head);
    

    printf("The length of Linked List is %d \n", length(head));
   
    cleanup(&head, &tail);

    return 0;
}