#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, b[high + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int *arr;
    int i, n, k;
    printf("Enter The Size of Array\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter The Elemets\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    MergeSort(arr, 0, n);
    printArray(arr, n);
}