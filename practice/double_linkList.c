#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
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

struct node *insertAtHead(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    return ptr;
}

void insertAtEnd(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void insertAtIndex(struct node *head, int index, int data)
{
    int i = 0;
    struct node *ptr = head;
    struct node *ptr2;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    while (i < index - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    ptr2 = ptr->next;
    ptr->next = temp;
    ptr2->prev = temp;
    temp->next = ptr2;
    temp->prev = ptr;
}

struct node *deleteAtHead(struct node *head)
{
    struct node *ptr = head;
    if (head->next != NULL)
    {
        head = head->next;
        head->prev = NULL;
    }
    free(ptr);
    return head;
}
void deleteAtEnd(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    int n, data, i;

    printf("Enter Size of Node\n");
    scanf("%d", &n);
    printf("Enter Elements\n");
    scanf("%d", &data);
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
    traverseList(head);
    head = insertAtHead(head, 10);
    traverseList(head);
    insertAtEnd(head, 20);
    traverseList(head);
    insertAtIndex(head, 2, 15);
    traverseList(head);
    deleteAtEnd(head);
    traverseList(head);
    return 0;
}