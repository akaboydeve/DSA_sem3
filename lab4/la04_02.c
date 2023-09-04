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

void deleteAtIndex2(struct node *head, int index)
{
    // struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    struct node *temp2;
    int i = 0;
    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
    // free(temp);
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

int countNodes(struct node *head)
{
    int i = 0;
    while (head->next != NULL)
    {
        head = head->next;
        i++;
    }
    return i;
}

int main()
{
    int flag = 1, n, pos, data;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    while (flag)
    {
        printf("1. Insert node at specific position\n");
        printf("2. Deletion of an element from specific position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the link list\n");
        printf("5. Exit\n");
        printf("Enter Choise\n");

        scanf("%d", &n);
        if (n == 1)
        {
            printf("Enter Position and Data For Insertion\n");
            scanf("%d", &pos);
            scanf("%d", &data);
            insertAtIndex(head, pos, data);
        }
        else if (n == 2)
        {
            printf("Enter Position For Deletion\n");
            scanf("%d", &pos);
            deleteAtIndex(head, pos);
        }
        else if (n == 3)
        {
            printf("No of Nodes in the LinkList %d\n", countNodes(head));
        }
        else if (n == 4)
        {
            printf("Traversing The LinkList\n");
            traverseLinkList(head);
        }
        else if (n == 5)
        {
            printf("Exiting Program");
            flag = 0;
        }
        else
        {
            printf("Wrong Input Try again\n");
        }
    }

    return 0;
}