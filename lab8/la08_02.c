/*Write a menu driven program to implement linear queue operations such as Enqueue,
Dequeue, IsEmpty, Traverse using single linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverseQueue(struct node *front)
{
    if (front == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%d \t", front->data);
        if (front->next != NULL)
        {
            printf("->\t");
        }
        traverseQueue(front->next);
    }
}

void enQueue(struct node **rear, int data)
{
    if (*rear == NULL)
    {
        (*rear)->data = data;
    }
    else
    {
        struct node *temp;
        temp->data = data;
        temp->next == NULL;
        (*rear)->next = temp;
    }
}

int isEmpty(struct node *front, struct node *rear)
{
    if (rear == NULL && front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void deQueue(struct node **front, struct node **rear)
{
    if (isEmpty(*front, *rear))
    {
        printf("Queue Empty\n");
    }

    struct node *ptr;
    ptr = *front;
    printf("%d\n", ptr->data);
    if (*front == *rear)
    {
        *front = *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
    }
    free(ptr);
}

int main()
{
    struct node *queue = (struct node *)malloc(sizeof(struct node));
    queue = NULL;
    struct node *front = queue;
    struct node *rear = NULL;

    int ch, n;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("Enter Choie: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element:");
            scanf("%d", &n);
            enQueue(&rear, n);
            break;
        case 2:
            deQueue(&front, &rear);
            break;
        case 3:
            isEmpty(front, rear);
            break;
        case 4:
            traverseQueue(front);
            break;
        case 5:
            printf("Exiting Program \n");
            return 0;
        default:
            break;
        }
    }

    return 0;
}