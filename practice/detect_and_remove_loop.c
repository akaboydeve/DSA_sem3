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

// traversing the linklist recursively and printing "Time Complexity O(n)"
void traverseLiinkList(struct node *head)
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
            traverseLiinkList(head->next);
        }
    }
}

// taversing the list and using flyod cycle detection to find and brreak loop "Time Complexity O(n)"
int detectAndRemoveLoop(struct node *head)
{
    struct node *fast_ptr = head, *slow_ptr = head, *prev_ptr;
    int isLoopPresent = 0;
    int k = 1, i;
    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            isLoopPresent = 1;
            slow_ptr = head;
            while (slow_ptr != fast_ptr)
            {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            slow_ptr = fast_ptr->next;

            while (slow_ptr->next != fast_ptr)
            {
                slow_ptr = slow_ptr->next;
            }
            slow_ptr->next = NULL;
        }
    }
    return isLoopPresent;
}

int main()
{
    // creating the nodes "Time Complexity O(1)"
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    struct node *node4 = (struct node *)malloc(sizeof(struct node));
    struct node *node5 = (struct node *)malloc(sizeof(struct node));
    struct node *node6 = (struct node *)malloc(sizeof(struct node));

    // initialing the values in list and creating the loop "Time Complexity O(1)"
    head->data = 50;
    head->next = node2;

    node2->data = 60;
    node2->next = node3;

    node3->data = 70;
    node3->next = node4;

    node4->data = 80;
    node4->next = node5;

    node5->data = 90;
    node5->next = node6;

    node6->data = 100;
    node6->next = node3;

    // taversing the list and using flyod cycle detection to find and brreak loop "Time Complexity O(n)"
    if (detectAndRemoveLoop(head))
    {
        printf("Loop present \n");
        traverseLiinkList(head);
    }
    else
    {
        printf("Loop not present \n");
    }

    return 0;
}
// Time Complexity of the Program is O(n)