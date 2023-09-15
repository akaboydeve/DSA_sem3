/*.Consider a N X N matrix where each element is divided by a column number
(integer division), i.e. mat[i][j] = floor((i+1)/(j+1)) where 0 <= i < n and 0 <= j < n.
The task is to find the sum of all matrix elements
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arraySum(int **arr, int row, int col)
{
    int sum = 0, i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
    }
    return sum;
}

int main()
{
    int **arr, row, col, i, j;

    printf("Enter the  size:");
    scanf("%d", &row);
    col = row;

    arr = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < col; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            arr[i][j] = floor((i + 1) / (j + 1));
        }
    }

    printf("The sum of array according to mat[i][j] = floor((i+1)/(j+1)) where 0 <= i < n and 0 <= j < n is \n%d\n", arraySum(arr, row, col));

    return 0;
}