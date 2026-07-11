#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
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
    Node *temp = list->head;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;

        newNode->next = NULL;
    }

    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }

    list->size++;
}

void insertAtEnd(int value, LinkedList *list)
{

    if (list->head == NULL)
    {
        insertAtBeginning(10, list);
        return;
    }

    Node *newNode = createNode(value);

    list->tail->next = newNode; // This overwrites the NULL to new Node
    list->tail = newNode;
    list->size++;
}

void insertAtPosition(int value, int index, LinkedList *list)
{
    if (index < 0)
        return;

    if (index == 0)
    {
        insertAtBeginning(10, list);
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

    newNode->next = temp->next;
    temp->next = newNode;
    list->size++;

    if (newNode->next == NULL)
        list->tail = newNode;
}

void deleteStart(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;
    *head = temp->next;

    if (*head == NULL)
        *tail = NULL;

    free(temp);
}

void deleteEnd(Node **head, Node **tail)
{

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;

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

        temp = temp->next;
    }
}

void deleteAtPosition(int index, Node **head, Node **tail)
{
    if (index < 0)
        return;

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

    Node *temp = *head;
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
        *tail = temp; // We just deleted the Last Node

    free(toDelete);
    temp->next = nextNode;
}

void search(int value, Node *head)
{
    int count = 0;
    Node *temp = head;

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

void update(int value, int index, Node *head)
{
    if (index < 0)
        return;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int count = 0;
    Node *temp = head;

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

void reverse(Node **head, Node **tail)
{
    Node *prev = NULL;
    Node *curr = *head;

    while (curr != NULL)
    {
        Node *next = curr->next; // Points to next node

        curr->next = prev; // Points to previous node

        prev = curr; // Moves previous node to current node

        curr = next; // Moves current node to next node
    }

    *tail = *head;
    *head = prev;
}

void cleanup(Node **head, Node **tail)
{
    while (*head != NULL)
    {
        deleteStart(head, tail);
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
}

int main()
{
    LinkedList List = {NULL, NULL, 0};

    insertAtBeginning(10, &List);
    insertAtEnd(30, &List);
    insertAtPosition(20, 1, &List);

    displayList(&List);

    printf("The length of Linked List is %d \n", length(&List));

    return 0;
}