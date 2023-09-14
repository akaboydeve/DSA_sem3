/*Write a function detectAndRemoveLoop() that checks whether a given Linked List
contains a loop and if the loop is present then removes the loop and returns true. If
the list doesn’t contain a loop then it returns false.The below diagram shows a
linked list with a loop. detectAndRemoveLoop() must change the below list to 1-
>2->3->4->5->NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverseLiinkList(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return 0;
    }
    else
    {
        printf("%d", head->data);
        if (head->next != NULL)
        {
            printf(" -> ");
            traverseLiinkList(head->next);
        }
    }
}

void insert(struct node **head, int data)
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

void detectAndRemoveLoop()
{
}
int main()
{
    return 0;
}