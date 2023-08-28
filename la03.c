// wap to find sum of prime no present in array

#include <stdio.h>
int main()
{
    int arr[5];
    int i, k, j, l, s = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Enter index %d \n", i);
        scanf("%d", (&arr[i]));
    }
    for (i = 0; i < 5; i++)
    {
        k = 1;
        for (j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                k = 0;
                break;
            }
            if (k == 1)
            {
                s = s + arr[i];
                break;
            }
        }
    }

    printf("prime sum is %d\n", s);
    return 0;
}