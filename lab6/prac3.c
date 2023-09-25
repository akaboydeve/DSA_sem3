/*WAP to merge 2 SLL in fashion below
10->20->30
100->200->300->400
10->100->20->200->30->300->400
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
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        insertAtEnd(&temp, ptr1->data);
        insertAtEnd(&temp, ptr2->data);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr1 != NULL)
    {
        insertAtEnd(&temp, ptr1->data);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        insertAtEnd(&temp, ptr2->data);
        ptr2 = ptr2->next;
    }
    return temp;
}

int main()
{
    int size, data, i;
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    head1 = NULL;
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    head2 = NULL;
    struct node *resultHead = (struct node *)malloc(sizeof(struct node));
    resultHead = NULL;

    printf("Node 1\n");
    printf("Enter Size: ");
    scanf("%d", &size);
    printf("Enter Element: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &data);
        insertAtEnd(&head1, data);
    }

    printf("Node 2\n");
    printf("Enter Size: ");
    scanf("%d", &size);
    printf("Enter Element: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &data);
        insertAtEnd(&head2, data);
    }

    resultHead = merge(head1, head2);
    traverseList(resultHead);

    return 0;
}