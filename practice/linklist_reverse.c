#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverseLinkList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
        if (head != NULL)
        {
            printf("-> ");
        }
    }
    printf("\n");
}

void recursive_reverseLinkList(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        recursive_reverseLinkList(head->next);
        printf("%d ", head->data);
    }
}

struct node *reverseLinkList(struct node *head)
{
    struct node *prev = NULL;
    // struct node *cur = head;
    struct node *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    struct node *node4 = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = node4;

    node4->data = 40;
    node4->next = NULL;
    traverseLinkList(head);
    head = reverseLinkList(head);
    traverseLinkList(head);
}