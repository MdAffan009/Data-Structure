#include<stdio.h>

int main()
{
    int arr[4] = {2, 4, 8};

    //Updating the element, takes O(1)
    arr[1] = 6;


    //Insertion of the element if there is a capcity, in worst case it takes O(n)
    //Let's say we have to add 4 at index 1

    int size = 3;
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
    

    return 0;
}