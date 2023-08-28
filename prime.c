// prime number
#include <stdio.h>

int main()
{
    int n, i, k, j;

    printf("Enter The Number\n");
    scanf("%d", &n);

    for (i = 2; i <= n; i++)
    {
        k = 1;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                k = 0;
                break;
            }
        }

        if (k == 1)
        {
            printf("%d is prime\n", i);
        }
    }

    return 0;
}
