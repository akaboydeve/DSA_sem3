/*Write a program to create a circular linked list and display the elements of the list.
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverseList(struct node *head)
{
    int i = 1;
    struct node *ptr = head;
    printf("Element %d is %d\n", i, ptr->data);
    i++;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        printf("Element %d is %d\n", i, ptr->data);
        i++;
    }
}

void insertAtEnd(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = data;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = head;
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
    head->next = head;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
    traverseList(head);

    // traverseList(head);

    // insertAtEnd(head, 20);
    // traverseList(head);

    // insertAtIndex(head, 2, 15);
    // traverseList(head);

    // deleteAtEnd(head);
    // traverseList(head);

    return 0;
}