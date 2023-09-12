#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int col;
    int value;
    struct node *next;
};

void traverseSparceList(struct node *header)
{
    if (header == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", header->row);
        printf("%d\t", header->col);
        printf("%d\n", header->value);
        traverseSparceList(header->next);
    }
}

void insertSparce(struct node **header, int row, int col, int value)
{
    struct node *ptr = *header;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->value = value;
    temp->next = NULL;
    if (*header == NULL)
    {
        *header = temp;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void sumSparce(struct node *header1, struct node *header2, struct node **header3)
{
    struct node *ptr1 = header1->next;
    struct node *ptr2 = header2->next;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->row = header1->row;
    temp->col = header1->col;
    temp->next = NULL;
    *header3 = temp;
    int k = 0;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->row == ptr2->row && ptr1->col == ptr2->col)
        {
            insertSparce(header3, ptr1->row, ptr1->col, ptr1->value + ptr2->value);
            k++;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->row == ptr2->row && ptr1->col != ptr2->col)
        {
            if (ptr1->col < ptr2->col)
            {
                insertSparce(header3, ptr1->row, ptr1->col, ptr1->value);
                k++;
                ptr1 = ptr1->next;
            }
            else if (ptr1->col > ptr2->col)
            {
                insertSparce(header3, ptr2->row, ptr2->col, ptr2->value);
                k++;
                ptr2 = ptr2->next;
            }
        }
        else if (ptr1->row != ptr2->row && ptr1->col == ptr2->col)
        {
            if (ptr1->row < ptr2->row)
            {
                insertSparce(header3, ptr1->row, ptr1->col, ptr1->value);
                k++;
                ptr1 = ptr1->next;
            }
            else if (ptr1->row > ptr2->row)
            {
                insertSparce(header3, ptr2->row, ptr2->col, ptr2->value);
                k++;
                ptr2 = ptr2->next;
            }
        }
    }
    // while (ptr1 != NULL)
    // {
    //     insertSparce(header3, ptr1->row, ptr1->col, ptr1->value);
    //     k++;
    //     ptr1 = ptr1->next;
    // }
    // while (ptr2 != NULL)
    // {
    //     insertSparce(header3, ptr2->row, ptr2->col, ptr2->value);
    //     k++;
    //     ptr2 = ptr2->next;
    // }
    temp->value = k;
    *header3 = temp;
}

int main()
{
    struct node *header1 = (struct node *)malloc(sizeof(struct node));
    header1 = NULL;
    struct node *header2 = (struct node *)malloc(sizeof(struct node));
    header2 = NULL;
    struct node *header3 = (struct node *)malloc(sizeof(struct node));
    header3 = NULL;
    int row, col, value, value2, i;

    printf("Enter The 1st sparce matrix in 3-Tuple Format:\n");
    scanf("%d", &row);
    scanf("%d", &col);
    scanf("%d", &value);
    insertSparce(&header1, row, col, value);
    for (i = 0; i < value; i++)
    {
        scanf("%d", &row);
        scanf("%d", &col);
        scanf("%d", &value2);
        insertSparce(&header1, row, col, value2);
    }

    printf("Enter The 2nd sparce matrix in 3-Tuple Format:\n");
    scanf("%d", &row);
    scanf("%d", &col);
    scanf("%d", &value);
    insertSparce(&header2, row, col, value);
    for (i = 0; i < value; i++)
    {
        scanf("%d", &row);
        scanf("%d", &col);
        scanf("%d", &value2);
        insertSparce(&header2, row, col, value2);
    }

    printf("Sum of 2 Sparce matrix :\n");
    sumSparce(header1, header1, &header3);
    traverseSparceList(header3);

    return 0;
}