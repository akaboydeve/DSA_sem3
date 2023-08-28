/* wap to represent a given sparce matrirow in 3 tuple format using 2d array
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, row, column, n, k = 0;
    int **arr;
    printf("Enter the Row Size of the Matrix\n");
    scanf("%d", &row);
    printf("Enter the column Size of the Matrix\n");
    scanf("%d", &column);

    arr = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(column * sizeof(int));
    }
    printf("Enter The elements for sparce Matrix\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", (&arr[i][j]));
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
            {
                k++;
            }
        }
    }
    printf("3-Tuple format\n");
    printf("%d %d %d\n", row, column, k);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, (arr[i][j]));
            }
        }
    }
}