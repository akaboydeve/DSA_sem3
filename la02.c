// wap to find sum of odd no. present in an array

#include <stdio.h>

int main()
{
    int arr[5];
    int i, s = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Enter index %d \n", i);
        scanf("%d", (arr + i));
    }

    for (i = 0; i < 5; i++)
    {
        if (((arr[i]) % 2) != 0)
        {
            s = s + (*arr + i);
        }
    }
    printf("odd sum is %d\n", s);

    return 0;
}