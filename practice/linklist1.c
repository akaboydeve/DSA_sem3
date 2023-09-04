/*wap to insert node at beginning on linklist
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 50;
    temp->next = NULL;
}