/*wap to create 5 nodes in linklist and print
 */
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
        printf("Element %d\n", head->data);
        head = head->next;
    }
}

int main()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    struct node *node4 = (struct node *)malloc(sizeof(struct node));
    struct node *node5 = (struct node *)malloc(sizeof(struct node));

    ptr->data = 50;
    ptr->next = node2;

    node2->data = 60;
    node2->next = node3;

    node3->data = 70;
    node3->next = node4;

    node4->data = 80;
    node4->next = node5;

    node5->data = 90;
    node5->next = NULL;

    printf("content of linklist\n");
    traverseLinkList(ptr);
}