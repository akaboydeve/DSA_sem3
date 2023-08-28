/* wap to perform transpose of a given sparce matrirow in 3 tuple format
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, row, column, n, k;
    int **arr;
    int **arr2;
    printf("Enter Sparce Matrix in 3-tuple format\n");
    scanf("%d", &row);
    scanf("%d", &column);
    scanf("%d", &k);

    arr = (int **)calloc(row, sizeof(int *));
    for (i = 0; i < row; i++)
    {
        arr[i] = (int *)calloc(column, sizeof(int));
    }
    arr2 = (int **)calloc(column, sizeof(int *));
    for (i = 0; i < column; i++)
    {
        arr2[i] = (int *)calloc(row, sizeof(int));
    }

    for (i = 0; i < k; i++)
    {
        scanf("%d", &j);
        scanf("%d", &n);
        scanf("%d", &arr[j][n]);
    }

    for (i = 0; i < column; i++)
    {
        for (j = 0; j < row; j++)
        {
            arr2[i][j] = arr[j][i];
        }
    }

    printf("3-Tuple format for TRANSPOSE Sparce Matrix\n");
    printf("%d %d %d\n", column, row, k);

    for (i = 0; i < column; i++)
    {
        for (j = 0; j < row; j++)
        {
            if (arr2[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, arr2[i][j]);
            }
        }
    }
}