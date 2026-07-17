#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    int key;
    printf("Enter the value to be found: ");
    scanf("%d", &key);

    // Binary Search
    int left = 0, right = 4;

    for (int i = 0; i < 4; i++)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
        {
            printf("Element found at index %d \n", mid);
            return 0;
        }

        else if (arr[mid] > key)
        {
            right = mid;
            continue;
        }

        else
        {
            left = mid;
        }
    }

    printf("Element not found!! \n");
    return 1;
}