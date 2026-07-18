#include <stdio.h>
#include <stdlib.h>

int isSorted = 0;

// Initialization
int *initialize(int *size)
{
    printf("Enter the value of n: ");
    scanf("%d", size);

    if (*size <= 0)
    {
        printf("Invalid size.\n");
        return NULL;
    }

    int *arr = malloc(*size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < *size; i++)
    {
        printf("Enter the value of element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    return arr;
}

// Traversal
void traversal(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Sorting
void sort(int *arr, int size)
{
    // We are using Bubble Sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    isSorted = 1;
}

// Searching
void search(int *arr, int size)
{
    // We will implement binary search

    int target;
    printf("Enter the value to be searched: ");
    scanf("%d", &target);

    int left = 0, right = size - 1;

    if (isSorted == 0)
        sort(arr, size);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            printf("Found at %d\n", mid);
            return;
        }

        if (arr[mid] > target)
            right = mid - 1;

        else
            left = mid + 1;
    }

    printf("Element not found!! \n");
}

// Insertion
void insertion(int **arr, int *size)
{
    int value, index;

    printf("Enter the value and index to be added: ");
    scanf("%d %d", &value, &index);

    if (index < 0 || index > *size)
    {
        printf("Invalid Index!! \n");
        return;
    }

    int *temp = realloc(*arr, (*size + 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory reallocation failed.\n");
        return;
    }

    *arr = temp;

    if (index == *size)
    {
        (*arr)[*size] = value;
        (*size)++;
        return;
    }

    for (int i = *size; i > index; i--)
    {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[index] = value;
    (*size)++;
    isSorted = 0;
}

// Deletion
void deletion(int **arr, int *size)
{
    int index;

    printf("Enter the index to be deleted: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size)
    {
        printf("Invalid Index!! \n");
        return;
    }

    for (int i = index; i < *size - 1; i++)
    {
        (*arr)[i] = (*arr)[i + 1];
    }

    int *temp = realloc(*arr, (*size - 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory reallocation failed.\n");
        return;
    }

    *arr = temp;
    (*size)--;
    isSorted = 0;
}

void update(int **arr, int size)
{
    int index, value;

    printf("Enter the value and index to be changed: ");
    scanf("%d %d", &value, &index);

    if (index < 0 || index >= size)
    {
        printf("Invalid Index!! \n");
        return;
    }

    (*arr)[index] = value;
    isSorted = 0;
}

int main()
{
    int size;

    int *arr = initialize(&size);

    if (arr == NULL)
        return 1;

    traversal(arr, size);

    sort(arr, size);

    // traversal(arr, size);

    // search(arr, size);

    insertion(&arr, &size);

    traversal(arr, size);

    deletion(&arr, &size);

    traversal(arr, size);

    update(&arr, size);

    traversal(arr, size);

    free(arr);

    return 0;
}