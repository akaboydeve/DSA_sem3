/*Given a matrix, sort the rows of matrix in ascending order followed by sorting the
columns in descending order
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

void sortRow(int **a, int row, int col)
{
    int i, j, k, key;
    for (i = 0; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            key = a[i][j];
            k = j - 1;
            while (a[i][k] > key && k >= 0)
            {
                a[i][k + 1] = a[i][k];
                k--;
            }
            a[i][k + 1] = key;
        }
    }
}

void sortCol(int **a, int row, int col)
{
    int i, j, k, key;
    for (i = 0; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            key = a[j][i];
            k = j - 1;
            while (k >= 0 && a[k][i] < key)
            {
                a[k + 1][i] = a[k][i];
                k--;
            }
            a[k + 1][i] = key;
        }
    }
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
    printf("Orginal array\n");
    printArray(arr, row, col);

    printf("\nArray after row sort\n");
    sortRow(arr, row, col);
    printArray(arr, row, col);

    printf("\nArray after col sort\n");
    sortCol(arr, row, col);
    printArray(arr, row, col);

    return 0;
}