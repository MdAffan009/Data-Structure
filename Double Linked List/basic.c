#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

Node *createNode(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    node->prev = NULL;
    node->data = value;
    node->next = NULL;

    return node;
}

int length(LinkedList *list)
{
    return list->size;
}

void insertAtBeginning(int value, LinkedList *list)
{
    Node *newNode = createNode(value);

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;

        newNode->next = NULL;
        newNode->prev = NULL;
    }

    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }

    list->size++;
}

void insertAtEnd(int value, LinkedList *list)
{

    if (list->head == NULL)
    {
        insertAtBeginning(value, list);
        return;
    }

    Node *newNode = createNode(value);

    list->tail->next = newNode; // This overwrites the NULL to new Node
    newNode->prev = list->tail;
    list->tail = newNode;
    list->size++;
}

void insertAtPosition(int value, int index, LinkedList *list)
{
    if (index < 0)
        return;

    if (index == 0)
    {
        insertAtBeginning(value, list);
        return;
    }

    Node *newNode = createNode(value);

    if (list->head == NULL)
    {
        printf("The List is Empty...\n");
        free(newNode);
        return;
    }

    int count = 0;
    Node *temp = list->head;

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


    temp->next->prev = newNode;
    newNode->next = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    list->size++;

    if (newNode->next == NULL)
        list->tail = newNode;
}

void deleteStart(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->head;
    list->head = temp->next;
    
    if (list->head != NULL) list->head->prev = NULL;

    if (list->head == NULL)
        list->tail = NULL;

    free(temp);

    list->size--;
}

void deleteEnd(LinkedList *list)
{

    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->head;

    if (temp->next == NULL)
    {
        list->head = NULL;
        list->tail = NULL;

        free(temp);

        list->size--;
        return;
    }

    while (temp->next)
    {

        if (temp->next->next == NULL)
        {
            free(temp->next);
            temp->next = NULL;
            list->tail = temp;

            list->size--;
            return;
        }

        temp = temp->next;
    }
}

void deleteAtPosition(int index, LinkedList *list)
{
    if (index < 0)
        return;

    if (index == 0)
    {
        deleteStart(list);
        return;
    }

    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->head;
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

    Node *toDelete = temp->next;
    Node *nextNode = toDelete->next;

    if (nextNode == NULL)
        list->tail = temp; // We just deleted the Last Node

    free(toDelete);
    temp->next = nextNode;
    nextNode->prev = temp;

    list->size--;
}

void search(int value, LinkedList *list)
{
    int count = 0;
    Node *temp = list->head;

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

void update(int value, int index, LinkedList *list)
{
    if (index < 0)
        return;

    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int count = 0;
    Node *temp = list->head;

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

void reverseList(LinkedList *list)
{
    
    Node *curr = list->head;

    while (curr != NULL)
    {
        Node *next = curr->next; // Points to next node

        curr->next = curr->prev; // Points to previous node

        curr->prev = next; // Moves previous node to current node

        curr = next; // Moves current node to next node
    }

    Node *temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}


void reverse(LinkedList *list)
{

    Node *left = list->head;
    Node *right = list->tail;

    for (int i = 0; i < list->size / 2; i++)
    {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->prev;
        
    }
    
}

void cleanup(LinkedList *list)
{
    while (list->size != 0)
    {
        deleteStart(list);
    }

    printf("Cleanup Successful!! \n");
}

void displayList(LinkedList *list)
{
    Node *temp = list->head;

    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");

    // List in reverse  
    // temp = list->tail;

    // while (temp)
    // {
    //     printf("%d -> ", temp->data);
    //     temp = temp->prev;
    // }
    // printf("NULL \n");


}


int main()
{
    LinkedList List = {NULL, NULL, 0};

    insertAtBeginning(30, &List);
    insertAtBeginning(20, &List);
    insertAtBeginning(10, &List);

    insertAtEnd(50, &List);

    insertAtPosition(40, 3, &List);

    insertAtEnd(55, &List);
    insertAtEnd(66, &List);
    insertAtPosition(60, 5, &List);
    insertAtBeginning(5, &List);
    
    
    displayList(&List);

    deleteStart(&List);
    deleteAtPosition(6, &List);
    deleteEnd(&List);

    displayList(&List);

    printf("\n");
    reverseList(&List);
    displayList(&List);
    
    printf("The length of Linked List is %d \n", length(&List));

    cleanup(&List);

    return 0;
}