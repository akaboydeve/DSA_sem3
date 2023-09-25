/* Given an array of n numbers and a positive integer k. The problem is to find k
numbers with most occurrences, i.e., the top k numbers having the maximum
frequency. If two numbers have the same frequency then the larger number should
be given preference. The numbers should be displayed in decreasing order of their
frequencies. It is assumed that the array consists of k numbers with most
occurrences
*/
#include <stdio.h>
#include <stdlib.h>

// to print array
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int findOccurrence(int a[], int size, int element)
{
    int i, k = 0;
    for (i = 0; i < size; i++)
    {
        if (a[i] == element)
        {
            k++;
        }
    }
    return k;
}

void sortOccurrence(int a[], int size)
{
    int i, j, key, key2, *b;
    b = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
    for (i = 1; i < size; i++)
    {
        key = findOccurrence(b, size, a[i]);
        key2 = a[i];
        j = i - 1;
        while (findOccurrence(b, size, a[j]) < key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key2;
    }
}

void sortDesend(int a[], int size)
{
    int i, j, key, key2;
    for (i = 1; i < size; i++)
    {
        key = a[i];
        key2 = a[i];
        j = i - 1;
        while (a[j] < key && j >= 0)
        {

            a[j + 1] = a[j];

            j--;
        }
        a[j + 1] = key;
    }
}
void removeDuplicate(int a[], int b[], int *size)
{
    int i, j, k;
    for (i = 0; i < (*size); i++)
    {
        b[i] = a[i];
    }

    for (i = 0; i < (*size); i++)
    {
        for (j = i + 1; j < *size; j++)
        {
            if (b[i] == b[j])
            {
                for (k = j; k < (*size); k++)
                {
                    b[k] = b[k + 1];
                }
                (*size)--;
                j--;
            }
        }
    }
}

int main()
{
    // variable declaration "Time Complexity O(1)"
    int *arr, *arr2;
    int size, size2, n, i, k;

    // taking size input "Time Complexity O(1)"
    printf("Enter The Size of Array\n");
    scanf("%d", &size);

    // creating 2 DMA array with same size n "Time Complexity O(1)"
    size2 = size;
    arr = (int *)malloc(size * sizeof(int));
    arr2 = (int *)calloc(size2, sizeof(int));

    // taking input in the array "Time Complexity O(n)"
    printf("Enter The Elemets\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }

    sortDesend(arr, size); // sorting the array in desending order "Time Complexity O(n^2)"

    sortOccurrence(arr, size); // sorting the array according to occurrences or frequency "Time Complexity O(n^3)"

    removeDuplicate(arr, arr2, &size2); // removing duplicate items = deleting items that has more than 1 occurrences "Time Complexity O(n^3)"

    printf("Enter K: \n");
    scanf("%d", &k);

    printArray(arr2, k); // printing the new array upto K "Time Complexity O(n)"

    return 0;
}
// Time complexity of the program O(n^3)