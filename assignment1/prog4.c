/*Given a singly linked list, write a function to swap elements pairwise
 */
#include <stdio.h>
#include <stdlib.h>

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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairWiseSwap(struct node *head)
{
    if (head != NULL && head->next != NULL)
    {
        swap(&head->data, &head->next->data);
        pairWiseSwap(head->next->next);
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    int n, data, i;

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

    // swaping elements pairwise and print
    printf("The Swapped list: ");
    pairWiseSwap(head);
    traverseLinkList(head);

    return 0;
}
// Time Complexity of the Program is O(n^2)