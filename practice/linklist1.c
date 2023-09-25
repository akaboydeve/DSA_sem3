/*wap to insert node at beginning on linklist
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtEndII(struct node **head, int coe, int pow)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
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

int main()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 50;
    temp->next = NULL;
}