#include <stdio.h>
#include <stdlib.h>

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

void insertAtEnd(struct node **head, int data)
{
    struct node *ptr = *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

struct node *merge(struct node *head1, struct node *head2)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = NULL;
    struct node *ptr1 = head1, *ptr2 = head2;
    while (ptr1 != NULL)
    {
        if (ptr1->data % 2 == 0)
        {
            insertAtEnd(&temp, ptr1->data);
        }
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        if (ptr2->data % 2 == 0)
        {
            insertAtEnd(&temp, ptr2->data);
        }
        ptr2 = ptr2->next;
    }
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL)
    {
        if ((ptr1->data) % 2 != 0)
        {
            insertAtEnd(&temp, ptr1->data);
        }
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        if ((ptr2->data) % 2 != 0)
        {
            insertAtEnd(&temp, ptr2->data);
        }
        ptr2 = ptr2->next;
    }
    return temp;
}

int main()
{
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    head1 = NULL;
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    head2 = NULL;
    struct node *resultHead = (struct node *)malloc(sizeof(struct node));
    resultHead = NULL;

    int n = 0, data = 0, i = 0;
    printf("Enter The no of elements in list 1 :\n");
    scanf("%d", &n);
    printf("Enter The Elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertAtEnd(&head1, data);
    }

    printf("Enter The no of elements in list 1 :\n");
    scanf("%d", &n);
    printf("Enter The Elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertAtEnd(&head2, data);
    }

    printf("Final List \n");
    resultHead = merge(head1, head2);
    traverseList(resultHead);
}