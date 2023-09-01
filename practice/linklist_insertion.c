#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// traversing the link list and printing the nodes
void traverseLinkList(struct node *head)
{
    while (head != NULL)
    {
        printf("Element %d\n", head->data);
        head = head->next;
    }
}
// insert data at start
struct node *insertAtHead(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// insert data at start using head referance
void insertAtHeadRef(struct node **head_ref, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = *head_ref;
    *head_ref = ptr;
}

// insert at end
void insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->data = data;
    ptr->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

// insert at end using head referance
void insertAtEndRef(struct node **head_ref, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head_ref;
    ptr->data = data;
    ptr->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

// insert at index
void insertAtIndex(struct node *head, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->data = data;
    int i = 0;
    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

// insert at index using head referance
void insertAtIndexRef(struct node **head_ref, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head_ref;
    ptr->data = data;
    int i = 0;
    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 20;
    head->next = NULL;
    printf("Before Insert\n");
    traverseLinkList(head);

    printf("\nAfter Insert at head\n");
    head = insertAtHead(head, 22);
    insertAtHeadRef(&head, 45);
    traverseLinkList(head);

    printf("\nAfter Insert at end/tail\n");
    insertAtEnd(head, 65);
    insertAtEndRef(&head, 70);
    traverseLinkList(head);

    printf("\nAfter Insert at Index 2\n");
    insertAtIndex(head, 2, 48);
    insertAtIndexRef(&head, 2, 62);
    traverseLinkList(head);

    return 0;
}