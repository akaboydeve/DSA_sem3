// wap to create an array of 10 elements and display the elements present in array
// insert element at a given position
/*I/P new Element : 5
position :2
O/P updated array list

Delete an element at given position
I/P postion 8
O/P updated array
*/

#include <stdio.h>
#include <stdlib.h>

void PrintArray(int array[], int length);
int main()
{
    int n, p;
    int *arr;

    arr = (int *)calloc(12, sizeof(int));
    printf("Enter all Elemets for array\n");
    for (int i = 0; i < 11; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Insertion\n");
    printf("Enter the position \n");
    scanf("%d", &p);
    printf("enter the element for position %d\n", p);
    scanf("%d", &n);
    for (int i = 12 - i; i >= p; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[p - 1] = n;
    PrintArray(arr, 12);

    printf("Deletion\n");
    printf("Enter the position \n");
    scanf("%d", &p);
    for (int i = p - 1; i < 12; i++)
    {
        arr[i] = arr[i + 1];
    }
    PrintArray(arr, 12 - 1);

    return 0;
}

void PrintArray(int array[], int length)
{
    printf("The updaed array is\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }
}