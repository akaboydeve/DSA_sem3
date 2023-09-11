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

void traverseList(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%d ", head->coe);
        printf("%d ", head->pow);
        if (head->next != NULL)
            printf(" -> ");
        traverseList(head->next);
    }
}

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

void insertAtEndII(struct node **head, int coe, int pow)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    ptr->coe = coe;
    ptr->pow = pow;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

void printPoly(struct node *poly)
{
    if (poly == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%dx^%d", poly->coe, poly->pow);
        if (poly->next != NULL)
        {
            printf(" + ");
        }
        printPoly(poly->next);
    }
}

void sumPolyLinkList(struct node *poly1, struct node *poly2, struct node **result)
{
    printf("Sum ");
    struct node *ptr1 = poly1, *ptr2 = poly2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->pow == ptr2->pow)
        {
            insertAtEndII(result, ptr1->coe + ptr2->coe, ptr1->pow);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->pow > ptr2->pow)
        {
            insertAtEndII(result, ptr1->coe, ptr1->pow);
            ptr1 = ptr1->next;
        }
        else
        {
            insertAtEndII(result, ptr2->coe, ptr2->pow);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        insertAtEndII(result, ptr1->coe, ptr1->pow);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        insertAtEndII(result, ptr2->coe, ptr2->pow);
        ptr2 = ptr2->next;
    }
}

void prodPolyLinkList(struct node *poly1, struct node *poly2, struct node **result)
{
    printf("Product ");
    struct node *ptr1 = poly1, *ptr2;
    while (ptr1 != NULL)
    {
        ptr2 = poly2;
        while (ptr2 != NULL)
        {
            insertAtEndII(result, (ptr1->coe) * (ptr2->coe), (ptr1->pow) + (ptr2->pow));
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void deleteAtIndex(struct node *head, int index)
{
    struct node *ptr = head, *ptr_prev;
    while (ptr != NULL && index != 0)
    {
        ptr_prev = ptr;
        ptr = ptr->next;
        index--;
    }
    ptr_prev->next = ptr->next;
    free(ptr);
}

void samePowSum(struct node *poly)
{
    struct node *ptr = poly, *ptr2 = poly, *dup;
    while (ptr != NULL && ptr->next != NULL)
    {
        ptr2 = ptr;
        while (ptr2->next != NULL)
        {
            if ((ptr->pow) == (ptr2->next->pow))
            {

                ptr->coe = ptr->coe + ptr2->next->coe;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }

        ptr = ptr->next;
    }
}

int main()
{
    int pow, coe, n, i;
    struct node *poly1 = (struct node *)malloc(sizeof(struct node));
    poly1 = NULL;
    struct node *poly2 = (struct node *)malloc(sizeof(struct node));
    poly2 = NULL;
    struct node *resultPoly = (struct node *)malloc(sizeof(struct node));
    resultPoly = NULL;

    printf("Polynomial 1\n");
    printf("Enter The maximum Power of X: ");
    scanf("%d", &pow);
    for (i = pow; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d: ", i);
        scanf("%d", &coe);
        insertAtEndII(&poly1, coe, i);
    }

    printf("\nPolynomial 2\n");
    printf("Enter The maximum Power of X: ");
    scanf("%d", &pow);
    for (i = pow; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d: ", i);
        scanf("%d", &coe);
        insertAtEndII(&poly2, coe, i);
    }

    sumPolyLinkList(poly1, poly2, &resultPoly);
    printPoly(resultPoly);

    resultPoly = NULL;

    prodPolyLinkList(poly1, poly2, &resultPoly);
    printPoly(resultPoly);

    samePowSum(resultPoly);
    printPoly(resultPoly);

    return 0;
}