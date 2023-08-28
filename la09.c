
/* wap to perform addition of 2 Sparce Matrix and 3-tuple
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, row1, column1, n, k1, row2, column2, k2;
    int **arr;
    int **arr2;
    int **arr3;

    printf("Enter Sparce Matrix 1 in 3-tuple format\n");
    scanf("%d", &row1);
    scanf("%d", &column1);
    scanf("%d", &k1);
    arr = (int **)calloc(row1, sizeof(int *));
    for (i = 0; i < row1; i++)
    {
        arr[i] = (int *)calloc(column1, sizeof(int));
    }

    printf("Enter Sparce Matrix 2 in 3-tuple format\n");
    scanf("%d", &row2);
    scanf("%d", &column2);
    scanf("%d", &k2);
    arr2 = (int **)calloc(row2, sizeof(int *));
    for (i = 0; i < row2; i++)
    {
        arr2[i] = (int *)calloc(column2, sizeof(int));
    }

    arr3 = (int **)calloc(row1, sizeof(int *));
    for (i = 0; i < row1; i++)
    {
        arr3[i] = (int *)calloc(column1, sizeof(int));
    }

    printf("3-Tuple format for Added Resultanted Sparce Matrix\n");
    printf("%d %d %d\n", row1, column1, k1 + k2);

    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < column1; j++)
        {
            if (arr3[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, (arr3[i][j]));
            }
        }
    }
}