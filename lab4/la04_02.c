/*wap to create a single link list of nods and perform the operation menu based using function
i> insert node at specific position
ii> deletion of an element from specific position
iii> count nodes
iv> traverse the link list
v> exit
*/
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

// delete at head
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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int i = 0;
    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    free(temp);
}

struct node *insertAtHead(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
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

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 20;
    head->next = NULL;
    printf("Before Insert\n");
    traverseLinkList(head);

    printf("\nAfter Insert at head\n");
    head = insertAtHead(head, 22);
    traverseLinkList(head);

    printf("\nAfter Insert at end/tail\n");
    insertAtEnd(head, 65);
    traverseLinkList(head);

    printf("\nAfter Insert at Index 2\n");
    insertAtIndex(head, 2, 48);
    traverseLinkList(head);

    printf("\nAfter Delete at Head 2\n");
    head = deleteAtHead(head);
    traverseLinkList(head);

    printf("\nAfter Delete at index 2\n");
    // deleteAtIndex(head, 2);
    traverseLinkList(head);

    return 0;
}