// wap to compare 2 using function . 1> call by value  2> call by address/ referrence

#include <stdio.h>

void compare_value(int a, int b);
void compare_reff(int *a, int *b);

int main()
{

    int x = 0, y = 0;
    printf("Enter x\n");
    scanf("%d", &x);

    printf("Enter y\n");
    scanf("%d", &y);

    compare_value(x, y);
    compare_reff(&x, &y);

    return 0;
}

void compare_value(int a, int b)
{
    printf("Compare by call by value %d \n", a - b);
}

void compare_reff(int *a, int *b)
{
    printf("Compare by call by reff %d \n", *a - *b);
}