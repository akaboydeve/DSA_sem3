/*Given a linked list, find the length of the longest palindrome list that exists in that
linked list.
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

int countCommon(struct node *head1, struct node *head2)
{
    int count = 0;
    struct node *ptr = head2;
    while (head1 != NULL && head1 != ptr && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            count++;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return count;
}

int maxPalindrome(struct node *head)
{
    struct node *prev = NULL, *cur = head, *next = NULL;
    int result = 0;
    while (cur != NULL)
    {
        // The sublist from head to current
        // reversed
        // to reverse 1 step and count same elements
        next = cur->next;
        cur->next = prev;

        // check for odd length palindrome
        // by finding longest common list elements
        // beginning from prev and from next (We
        // exclude cur)
        result = (result > (2 * countCommon(prev, next) + 1)) ? result : (2 * countCommon(prev, next) + 1);

        // check for even length palindrome
        // by finding longest common list elements
        // beginning from cur and from next
        result = (result > (2 * countCommon(cur, next))) ? result : (2 * countCommon(cur, next));

        prev = cur;
        cur = next;
    }
    return result;
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

    printf("Max length of paliindrome is %d\n", maxPalindrome(head));

    return 0;
}