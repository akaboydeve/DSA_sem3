/*WAP to represent a sparce matrix throuch sll
 */
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColumn(struct node *head)
{
    struct node *ptr = head, *cpt;

    while (ptr->next != NULL)
    {
        cpt = ptr->next;
        while (cpt != NULL)
        {
            if (cpt->col < ptr->col)
            {
                swap(&cpt->col, &ptr->col);
                swap(&cpt->row, &ptr->row);
                swap(&cpt->value, &ptr->value);
            }
            cpt = cpt->next;
        }
        ptr = ptr->next;
    }
}

void swapRowCol(struct node *head)
{
    while (head != NULL)
    {
        swap(&head->col, &head->row);
        head = head->next;
    }
}

int main()
{
    int row, col, value, i, j;
    struct node *matrix = (struct node *)malloc(sizeof(struct node));
    matrix = NULL;
    struct node *tuple = (struct node *)malloc(sizeof(struct node));
    tuple = NULL;
    struct node *ptr1;

    printf("Enter the size of the sparse matrix:\n");
    scanf("%d", &row);
    scanf("%d", &col);

    printf("Enter elements of sparse matrix: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &value);
            insertSparce(&matrix, i, j, value);
        }
    }
    value = 0;
    insertSparce(&tuple, row, col, value);

    ptr1 = matrix;

    while (ptr1 != NULL)
    {
        if (ptr1->value != 0)
        {
            insertSparce(&tuple, ptr1->row, ptr1->col, ptr1->value);
            value++;
        }
        ptr1 = ptr1->next;
    }
    ptr1 = tuple;
    ptr1->value = value;

    printf("Sparse matrix in 3-tuple format\n");
    traverseSparceList(tuple);

    printf("TRANSPOSEE of Sparse matrix in 3-tuple format\n");
    sortColumn(tuple);
    swapRowCol(tuple);
    traverseSparceList(tuple);

    return 0;
}
