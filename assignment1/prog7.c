/*Given a matrix mat[][], we have to check if the sum of i-th row is equal to the sum
of i-th column or not
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int **a, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int rowSum(int **arr, int row, int col, int i)
{
    int j, sum = 0;
    for (j = 0; j < col; j++)
    {
        sum = sum + arr[i][j];
    }
    return sum;
}

int colSum(int **arr, int row, int col, int i)
{
    int j, sum = 0;
    for (j = 0; j < row; j++)
    {
        sum = sum + arr[j][i];
    }
    return sum;
}

int main()
{
    int **arr, row, col, n, i, j;

    printf("Enter the row size:");
    scanf("%d", &row);
    printf("Enter the col size:");
    scanf("%d", &col);

    arr = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < col; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter the Elements:");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter value of i:");
    scanf("%d", &i);
    i--;
    if (rowSum(arr, row, col, i) == colSum(arr, row, col, i))
    {
        printf("Yes\n");
        printf("Sums of %d row = %d and %d column are same, that is %d\n", i, rowSum(arr, row, col, i), i, colSum(arr, row, col, i));
    }
    else
    {
        printf("No\n");
        printf("Sums of %d row = %d and %d column are NOT same, that is %d\n", i, rowSum(arr, row, col, i), i, colSum(arr, row, col, i));
    }

    return 0;
}