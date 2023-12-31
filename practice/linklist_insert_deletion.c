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
        printf("%d", head->data);
        head = head->next;
        if (head != NULL)
        {
            printf(" -> ");
        }
    }
    printf("\n");
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

void insertAtEndII(struct node **head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    ptr->data = data;
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

struct node *deleteAtHead(struct node *head)
{
    struct node *temp = head;
    if (head->next != NULL)
    {
        head = head->next;
    }
    free(temp);
    return head;
}

// delete at specific index
void deleteAtIndex(struct node *head, int index)
{
    // struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    struct node *temp_prev;
    int i = 0;
    while (i < index - 1 && temp != NULL)
    {
        temp_prev = temp;
        temp = temp->next;
        i++;
    }
    temp_prev->next = temp->next;
    free(temp);
}

void deleteAtEnd(struct node *head)
{
    // struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    struct node *temp_prev;
    int i = 0;
    while (temp != NULL)
    {
        temp_prev = temp;
        temp = temp->next;
        i++;
    }
    temp_prev->next = temp->next;
    free(temp);
}

void deleteAtElement(struct node *head, int data)
{
    struct node *temp1 = head;
    struct node *temp_prev;
    while (temp1 != NULL && temp1->data != data)
    {
        temp_prev = temp1;
        temp1 = temp1->next;
    }
    temp_prev->next = temp1->next;
    free(temp1);
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    // head->data = 20;
    // head->next = NULL;
    printf("LinkList\n");

    insertAtEndII(&head, 65);
    traverseLinkList(head);
    insertAtEndII(&head, 66);
    insertAtEndII(&head, 67);

    traverseLinkList(head);

    // printf("Before Insert\n");
    // traverseLinkList(head);

    // printf("\nAfter Insert at head\n");
    // head = insertAtHead(head, 22);
    // insertAtHeadRef(&head, 45);
    // traverseLinkList(head);

    // printf("\nAfter Insert at end/tail\n");
    // insertAtEnd(head, 65);
    // insertAtEndRef(&head, 70);
    // traverseLinkList(head);

    // printf("\nAfter Insert at Index 2\n");
    // insertAtIndex(head, 2, 40);
    // insertAtIndexRef(&head, 2, 62);
    // traverseLinkList(head);

    // printf("\nAfter Delete at Head 2\n");
    // head = deleteAtHead(head);
    // traverseLinkList(head);

    // printf("\nAfter Delete at element 40 \n");
    // deleteAtElement(head, 40);
    // traverseLinkList(head);

    return 0;
}