/*
Write a menu driven program to implement circular queue operations such as Enqueue,
Dequeue, Traverse, IsEmpty, IsFull using array.
*/
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
};

int IsEmpty(struct Queue *q)
{
    if (q->front == q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct Queue *q)
{
    if (((q->rear) + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void TraverseQueue(struct Queue *q)
{
    int i;
    if (!IsEmpty(q))
    {
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d\t", q->arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Queue Empty\n");
    }
}

void EnQueue(struct Queue *q, int x)
{
    if (IsFull(q))
    {
        printf("Queue Full");
        return;
    }
    if (IsEmpty(q))
    {
        q->front = ((q->front) + 1) % (q->size);
    }
    q->rear = ((q->rear) + 1) % (q->size);
    q->arr[q->rear] = x;
}

void DeQueue(struct Queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue Empty");
        return;
    }
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = ((q->front) + 1) % (q->size);
    }
}

int main()
{
    int ch, n, size;

    printf("Enter the size of Queue:");
    scanf("%d", &size);

    struct Queue *q1 = (struct Queue *)malloc(sizeof(struct Queue));
    q1->arr = (int *)malloc(size * sizeof(int));
    q1->front = q1->rear = -1;
    q1->size = size;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");

    while (1)
    {
        printf("Enter Choie: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element:");
            scanf("%d", &n);
            EnQueue(q1, n);
            break;
        case 2:
            DeQueue(q1);
            break;
        case 3:
            IsEmpty(q1);
            break;
        case 4:
            IsFull(q1);
            break;
        case 5:
            TraverseQueue(q1);
            break;
        case 6:
            printf("Exiting Program \n");
            return 0;
        default:
            break;
        }
    }

    return 0;
}