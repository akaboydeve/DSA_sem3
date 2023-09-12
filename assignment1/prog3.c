/*Write a removeDuplicates() function that takes a list and deletes any duplicate
nodes from the list. The list is not sorted
*/
#include <stdio.h>
#include <stdlib.h>

// node defination
struct node
{
    int data;
    struct node *next;
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

// Removing the nodes with duplicate data from the list "Time Complexity O(n^2)"
void removeDuplicates(struct node *head)
{
    struct node *ptr1 = head, *ptr2, *dup;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
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

    // removing dupliacate and printing "Time Complexity O(n^2)"
    printf("Removed Duplicate list: ");
    removeDuplicates(head);
    traverseLinkList(head);

    return 0;
}
// Time Complexity of the Program is O(n^2)