#include<stdio.h>

int main()
{
    int arr[6] = {2, 4, 8, 12, 16};

    //Updating the element, takes O(1)
    arr[1] = 6;


    //Insertion of the element if there is a capcity, takes O(n)
    //Let's say we have to add 4 at index 1

    int size = 5;
    int index = 1;
    int value = 4;

    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1]; // This shifts the elements to the right
    }
    
    arr[index] = value;
    size++;

    for (int  i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
    
    printf("\n");
    printf("---------------------------------------------------------------------------------------------- \n");

    //Deletion of the element too takes O(n)
    //Let's say we have to delete first element

    index = 2; //We will reuse the value of size from above

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1]; //This will shift elements to left which results in index overwriting
    }

    size--;
    
    for (int  i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }

    return 0;
}