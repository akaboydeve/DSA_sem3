/*Given singly linked list with every node having an additional “arbitrary” pointer
that currently points to NULL. Need to make the “arbitrary” pointer point to the
next higher value node
*/

#include <stdio.h>
#include <stdlib.h>

// node defination
struct node
{
    int data;
    struct node *next;
    struct node *arbit;
};

// traversing the linklist recursively and printing "Time Complexity O(n)"
void traverseLinkList(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%d", head->data);
        if (head->arbit == NULL)
        {
            printf(" Arbit=NULL");
        }
        else
        {
            printf(" Arbit=%d", head->arbit->data);
        }
        if (head->next != NULL)
        {
            printf(" -> ");
        }
        traverseLinkList(head->next);
    }
}

// insering new node with data at the end of node "Time Complexity O(n)"
void insertAtEnd(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = *head;
    temp->data = data;
    temp->next = NULL;
    temp->arbit = NULL;
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

void arbit(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data < ptr->next->data)
        {
            ptr->arbit = ptr->next;
        }
        ptr = ptr->next;
    }
    if (ptr->data < head->data)
    {
        ptr->arbit = head;
    }
}

int main()
{
    // creating head node "Time Complexity O(1)"
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    int n, i, data;

    // taking the input in the nodes "Time Complexity O(n)"
    printf("Enter No of Nodes: ");
    scanf("%d", &n);
    printf("Enter The elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // printing orgial list "Time Complexity O(n)"
    printf("The Orginal list: ");
    traverseLinkList(head);

    printf("after changing arbit : ");
    arbit(head);
    traverseLinkList(head);

    return 0;
}