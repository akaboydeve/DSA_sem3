/* Write a program to represent the polynomial equation of single variable using single linked
list and perform the addition of two polynomial equations
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe;
    int pow;
    struct node *next;
};

void insertAtEnd(struct node *head, int coe, int pow)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coe = coe;
    temp->pow = pow;
    temp->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void sumPolyLinkList(struct node *poly1, struct node *poly2)
{
    printf("Sum ");
    struct node *ptr1 = poly1, *ptr2 = poly2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->pow == ptr2->pow)
        {
            printf("%dx^%d", ptr1->coe + ptr2->coe, ptr1->pow);
            if (ptr1->next != NULL || ptr2->next != NULL)
            {
                printf(" + ");
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->pow > ptr2->pow)
        {
            printf("%dx^%d", ptr1->coe, ptr1->pow);
            if (ptr1->next != NULL || ptr2->next != NULL)
            {
                printf(" + ");
            }
            ptr1 = ptr1->next;
        }
        else
        {
            printf("%dx^%d", ptr2->coe, ptr2->pow);
            if (ptr1->next != NULL || ptr2->next != NULL)
            {
                printf(" + ");
            }
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        printf("%dx^%d", ptr1->coe, ptr1->pow);
        if (ptr1->next != NULL || ptr2->next != NULL)
        {
            printf(" + ");
        }
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        printf("%dx^%d", ptr2->coe, ptr2->pow);
        if (ptr1->next != NULL || ptr2->next != NULL)
        {
            printf(" + ");
        }
        ptr2 = ptr2->next;
    }
    printf("\n");
}

int main()
{
    int pow, coe, n, i;
    struct node *poly1 = (struct node *)malloc(sizeof(struct node));
    poly1->next = NULL;
    struct node *poly2 = (struct node *)malloc(sizeof(struct node));
    poly2->next = NULL;

    printf("Polynomial 1\n");
    printf("Enter The maximum Power of X: ");
    scanf("%d", &pow);
    printf("Enter the Coefficient of x^%d: ", pow);
    scanf("%d", &coe);
    poly1->coe = coe;
    poly1->pow = pow;
    for (i = pow - 1; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d: ", i);
        scanf("%d", &coe);
        insertAtEnd(poly1, coe, i);
    }

    printf("\nPolynomial 2\n");
    printf("Enter The maximum Power of X: ");
    scanf("%d", &pow);
    printf("Enter the Coefficient of x^%d: ", pow);
    scanf("%d", &coe);
    poly2->coe = coe;
    poly2->pow = pow;
    for (i = pow - 1; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d: ", i);
        scanf("%d", &coe);
        insertAtEnd(poly2, coe, i);
    }

    sumPolyLinkList(poly1, poly2);

    return 0;
}