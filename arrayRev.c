#include <stdio.h>

int main()
{
    int size = 7, temp, i;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    for (i = 0; i < size; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1];
        arr[size - 1] = temp;
        size--;
    }

    for (i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}