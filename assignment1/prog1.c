/*printing the K-th largest element*/
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
int arraySum(int a[], int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}
int main()
{
    // variable declaration "Time Complexity O(1)"
    int *arr, *arr2;
    int c = 0, i, j, n, k, sum = 0, arrSum, size;

    // creating DMA array with size n "Time Complexity O(1)"
    printf("Enter The Size of Array\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    // creating DMA array with size that can store combination of all sums "Time Complexity O(1)"
    size = ((n * (n + 1)) / 2);
    arr2 = (int *)malloc(size * sizeof(int));

    // taking element input "Time Complexity O(n)"
    printf("Enter The Elemets\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    arrSum = arraySum(arr, n); // total sum of the array "Time Complexity O(n)"

    // creating all possible sums and storing in array "Time Complexity O(n^3) because 3 loops upto n"
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            for (k = i; k <= j; k++)
            {
                sum = sum + arr[k];
            }
            arr2[c] = arrSum - sum;
            c++;
            sum = 0;
        }
    }

    MergeSort(arr2, 0, size); // sorting the sums in array "Time Complexity O(n log n) "

    printf("Enter The K-th largest: ");
    scanf("%d", &n);
    printf("The %d-th largest Sum is: %d\n", n, arr2[size - n]); // printing the K-th largest element
}
// Time complexity of the program O(n^3)