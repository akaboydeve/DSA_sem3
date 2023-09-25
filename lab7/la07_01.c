/* Write a menu driven program to create a stack using array and perform the following
operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements
 */

#include <stdio.h>

int stack[5], size = 5, top = -1;

int isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(int data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[top] = data;
        top++;
    }
}

int Pop()
{
    if (isEmpty)
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        top--;
        return stack[top + 1];
    }
}

void PrintStack()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int ch, n;
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check Empty\n");
    printf("4. Check Full\n");
    printf("5. Display Stack Elements\n");

    while (1)
    {
        printf("Enter Choice\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter Element to Push\n");
            scanf("%d", &ch);
            Push(n);
            PrintStack();
        }
        else if (ch == 2)
        {
            printf("Element %d is Poped from top\n", Pop());
            PrintStack();
        }
        else if (ch == 3)
        {
            if (isEmpty())
            {
                printf("Stack Empty\n");
            }
            else
            {
                printf("Stack Not Empty\n");
            }
        }
        else if (ch == 4)
        {
            if (isFull())
            {
                printf("Stack Full\n");
            }
            else
            {
                printf("Stack Not Full\n");
            }
        }
        else if (ch == 5)
        {
            PrintStack();
        }
        else
        {
            break;
        }
    }
    return 0;
}