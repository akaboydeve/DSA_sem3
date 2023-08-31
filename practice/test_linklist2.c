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
    struct node **head_reff;
    head_reff = &head;
    printf("head_reff %u\n", head_reff);
    printf("*head_reff %u\n", *head_reff);
    printf("**head_reff %u\n", **head_reff);
    printf("head %u\n", head);
    printf("&head %u\n", &head);
    printf("&head->data %u\n", &head->data);
    printf("*head %u\n", *head);
    printf("&*head %u\n", &*head);
    printf("*&*&head %u\n", *&*&head);

    return 0;
}