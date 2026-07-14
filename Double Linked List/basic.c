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

size_t length(LinkedList *list)
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
    if (index > list->size)
    {
        printf("Invalid Index!! \n");
        return;
    }

    if (index == 0)
    {
        insertAtBeginning(value, list);
        return;
    }

    if (index == list->size)
    {
        insertAtEnd(value, list);
        return;
    }

    Node *newNode = createNode(value);

    if (list->head == NULL)
    {
        printf("The List is Empty...\n");
        free(newNode);
        return;
    }

    int mid = list->size / 2;
    int dir = mid - index;

    if (dir >= 0)
    {
        int count = 0;
        Node *temp = list->head;

        while (count != mid && count < index - 1)
        {
            temp = temp->next;
            count++;
        }

        temp->next->prev = newNode;
        newNode->next = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    else
    {
        int count = list->size;
        Node *temp = list->tail;

        while (count > mid && count > index + 1)
        {
            temp = temp->prev;
            count--;
        }

        temp->prev->next = newNode;
        newNode->prev = temp->prev;

        newNode->next = temp;
        temp->prev = newNode;
    }

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

    if (list->head != NULL)
        list->head->prev = NULL;

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

    if (list->head == list->tail)
    {
        free(list->head);

        list->head = NULL;
        list->tail = NULL;

        list->size--;
        return;
    }

    Node *temp = list->tail->prev;

    free(temp->next);
    temp->next = NULL;
    list->tail = temp;

    list->size--;
}

void deleteAtPosition(int index, LinkedList *list)
{
    if (index >= list->size - 1)
    {
        printf("Invalid Index!! \n");
        return;
    }

    if (index == 0)
    {
        deleteStart(list);
        return;
    }

    if (index == list->size)
    {
        deleteEnd(list);
        return;
    }

    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int mid = list->size / 2;
    int dir = mid - index;

    if (dir >= 0)
    {
        int count = 0;
        Node *temp = list->head;

        while (count != mid && count < index - 1)
        {
            temp = temp->next;
            count++;
        }

        Node *toDelete = temp->next;
        Node *nextNode = toDelete->next;

        free(toDelete);

        if (nextNode != NULL)
        {
            temp->next = nextNode;
            nextNode->prev = temp;
        }

        else
        {
            list->tail = temp;
            temp->next = NULL;
        }
    }

    else
    {
        int count = list->size;
        Node *temp = list->tail;

        while (count > mid && count > index + 1)
        {
            temp = temp->prev;
            count--;
        }

        Node *toDelete = temp->prev;
        Node *nextNode = toDelete->prev;

        free(toDelete);

        if (nextNode != NULL)
        {
            temp->prev = nextNode;
            nextNode->next = temp;
        }

        else
        {
            list->head = temp;
            temp->prev = NULL;
        }
    }

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
    if (index >= list->size)
    {
        printf("Invalid Index!! \n");
        return;
    }

    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int mid = list->size / 2;
    int dir = mid - index;

    if (dir >= 0 || dir == mid)
    {
        int count = 0;
        Node *temp = list->head;

        while (count != mid && count < index)
        {
            temp = temp->next;
            count++;
        }

        temp->data = value;
    }

    else
    {
        int count = list->size;
        Node *temp = list->tail;

        while (count != mid && count > index)
        {
            temp = temp->prev;
            count--;
        }

        temp->data = value;
    }
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

void reverseData(LinkedList *list)
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

    insertAtBeginning(10, &List);
    insertAtEnd(30, &List);

    insertAtPosition(20, 1, &List);
    insertAtEnd(50, &List);
    insertAtPosition(40, 3, &List);

    insertAtBeginning(5, &List);
    insertAtEnd(60, &List);

    deleteStart(&List);
    deleteEnd(&List);

    displayList(&List);

    insertAtPosition(7, 3, &List);

    displayList(&List);

    deleteAtPosition(3, &List);

    displayList(&List);

    printf("The length of Linked List is %d \n", length(&List));

    cleanup(&List);

    return 0;
}