// 2d array test
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, x, y, n, k = 0;
    int **arr2;
    int *arr1;
    printf("Enter the Row Size of the Matrix\n");
    scanf("%d", &x);
    printf("Enter the column Size of the Matrix\n");
    scanf("%d", &y);

    arr1 = (int *)malloc(x * sizeof(int));
    printf("Element for 1d array\n");
    for (i = 0; i < x; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < x; i++)
    {
        printf("%d  ", arr1[i]);
    }

    arr2 = (int **)malloc(x * sizeof(int *));
    for (i = 0; i < y; i++)
    {
        arr2[i] = (int *)malloc(sizeof(int));
    }
    printf("Enter The elements for sparce Matrix\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            scanf("%d", (&arr2[i][j]));
        }
    }

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d", (arr2[i][j]));
        }
    }
}