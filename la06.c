/*a> wap to create an array of n elements using DMA.
b> Search an given Element in the Array.
c> Delete / Deallocate the memory of array afrer its use.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k = 0;
    int *arr;

    printf("Enter No. of Elements\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elemets\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter The Element to search\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == n)
        {
            printf("Element %d Found at position %d\n", n, i + 1);
            k++;
        }
    }
    if (k == 0)
    {
        printf("Element Not Present\n");
    }
    else
    {
        printf("Element %d has %d Occurence\n", n, k);
    }
    free(arr);
    printf("The array memory is Deleted using free(arr) \n");
    return 0;
}