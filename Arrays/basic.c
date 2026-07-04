#include<stdio.h>


int main() 
{

    int arr[5] = {10, 20, 30, 40, 50};


    //Accesing the element, takes O(1)
    printf("%d \n", arr[3]);

    
    //Searching the element, takes O(n)
    int target = 20;
    int index = -1;

    for (int i = 0; i < 5; i++)
    {
        if (target == arr[i])
        {
            index = i;
            break;
        }
    }
    
    if (index == -1)
    {
        printf("Element not found!!! \n");
        return 1;
    }
    
    else
    {
        printf("Found it! At index %d \n", index);
    }


    return 0;
}