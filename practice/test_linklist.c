#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void TraversalNode(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *InsertAtHead(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    (*ptr).next = head;
    return ptr;
}

struct node InsertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *newNode;
    newNode->data = data;
    newNode->next = NULL;
    while (head != NULL)
    {
        head = head->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    head = ptr;
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;
    printf("Size =%d\n", sizeof(head));
    printf("%u\n", &head);
    TraversalNode(head);
    head = InsertAtHead(head, 2);
    printf("Size =%d\n", sizeof(head));
    printf("%u\n", &head);
    TraversalNode(head);
    head = InsertAtHead(head, 23);
    head = InsertAtHead(head, 244);
    printf("Size =%d\n", sizeof(*head));
    printf("%u\n", &head);
    TraversalNode(head);

    return 0;
}