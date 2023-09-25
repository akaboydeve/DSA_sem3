/* Write a menu driven program to create a stack using linked list and perform the following
operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverseList(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%d ", head->data);
        if (head->next != NULL)
            printf("-> ");
        traverseList(head->next);
    }
}

int isEmpty(struct node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *Push(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    return temp;
}

int Pop(struct node *head)
{
    if (!isEmpty)
    {
        head = head->next;
        struct node *temp = head;
        free(temp);
    }
    else
    {
        printf("Nothing to Pop");
    }
    return head->data;
}

int main()
{
    struct node *stack = (struct node *)malloc(sizeof(struct node));
    stack = NULL;
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
            stack = Push(stack, n);
            traverseList(stack);
        }
        else if (ch == 2)
        {
            printf("Element %d is Poped from top\n", Pop(stack));
            traverseList(stack);
        }
        else if (ch == 3)
        {
            if (isEmpty(stack))
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
            traverseList(stack);
        }
        else
        {
            break;
        }
    }
    return 0;
}