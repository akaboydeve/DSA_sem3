/*4.1 Write a program to create a single linked list of n nodes and perform the following menu
based operations on it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void createnode(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	head=temp;
}
void insert_begining(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
}
void insert_at_end(int x)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    struct node *temp1=head;
    while (temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
void insert_at_middle(int ele1, int pos)
{
	struct node *temp3=(struct node*)malloc(sizeof(struct node));
	temp3->data=ele1;
	temp3->next=NULL;
	if(pos==1)
	{
	 temp3->next=head;
	 head=temp3;
	 return;
	}
	else
	{
	struct node *temp1=head;
	int i;
	for(i=0;i<pos-2;i++)
	{
		temp1=temp1->next;
	}
    temp3->next = temp1->next;
    temp1->next = temp3;
	return;
   }
}
 void deletenode(int ele2)
 {
   struct node * temp1=head;
    struct node * temp1prev;
   int i;
   for(i=0;i<ele2-1;i++)
   {
   while (temp1!=NULL)
   {
   	   temp1prev=temp1;
	   temp1=temp1->next;
   }
   temp1prev->next=temp1->next;
  free(temp1);
}
}
void main()
{
	 int n;
            printf("Enter the number of elements: ");
            scanf("%d",&n);
            int ele;
            printf("Enter the 1st Element: ");
            scanf("%d",&ele);
            createnode(ele);
            n--;
            int i;
            if (n!=0)
            {
                for ( i=0; i<n; i++)
                {
                    printf("Enter the next Element: ");
                    scanf("%d",&ele);
                    insert_at_end(ele);
                }
            }
              printf("The elements in the LL: \n\t");
    struct node *temp1=head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n\n");
    printf("\n");
    int pos,ele1;
    printf("enter the position at which the new node is inserted ");
    scanf("%d",&pos);
    printf("enter the element to be inserted ");
    scanf("%d",&ele1);
    insert_at_middle(ele1 , pos);
    printf("The elements in the LL: \n\t");
    struct node *temp2=head;
    while(temp2!=NULL)
    {
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
    printf("\n\n");
    int ele2;
    printf("enter the element to be deleted : ");
    scanf("%d",&ele2);
    deletenode(ele2);
    printf("the elements after deletion is : ");
    struct node *temp4=head;
    while(temp4!= NULL)
    {
    	printf("%d ",temp4->data);
    	temp4=temp4->next;
	}
	printf("\n");
return ;


	
}
