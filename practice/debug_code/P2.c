#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix element
struct node {
    int row;
    int col;
    int value;
    struct node* next;
};

typedef struct node node;
node *mat1=NULL;
node *mat2=NULL;
node *mat_add=NULL;

// Function to input a sparse matrix
node* input() {
    node *head = NULL, *temp=NULL;
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int i, j, val;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at row %d, column %d: ", i, j);
            scanf("%d", &val);
            if (val != 0) {
                // Create a new node for non-zero elements
                node* newNode = (node*)malloc(sizeof(node));
                newNode->row = i;
                newNode->col = j;
                newNode->value = val;
                if(temp == NULL)
                {
                    temp=newNode;
                    head=newNode;
                    continue;
                }
                temp->next=newNode;
                temp=temp->next;
            }
        }
    }
    return head;
}


node* add(node* mat1, node* mat2)
{
    node *temp1=mat1;
    node *temp2=mat2;
    node *temp3=mat_add;
    while (temp1!=NULL && temp2!=NULL)
    {
        if (temp1->row == temp2->row && temp1->col == temp2->col) {
            // Elements in both matrices at the same position
            int sum = temp1->value + temp2->value;
            if (sum != 0) {
                node* newNode = (node*)malloc(sizeof(node));
                newNode->row = temp1->row;
                newNode->col = temp1->col;
                newNode->value = sum;
                if (temp3==NULL)
                {
                    temp3=newNode;
                    continue;
                }
                temp3->next=newNode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
        else if (temp1->row < temp2->row || (temp1->row == temp2->row && temp1->col < temp2->col)) 
        {
            // Element in mat1 comes before mat2
            node* newNode = (node*)malloc(sizeof(node));
            newNode->row = temp1->row;
            newNode->col = temp1->col;
            newNode->value = temp1->value;
            temp3->next=newNode;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        else 
        {
            // Element in mat2 comes before mat1
            node* newNode = (node*)malloc(sizeof(node));
            newNode->row = temp2->row;
            newNode->col = temp2->col;
            newNode->value = temp2->value;
            temp3->next=newNode;
            temp2 = temp2->next;
            temp3 = temp3->next;
            
        }
    }
    // Copy any remaining elements from mat1 and mat2
    while (temp1 != NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->row = temp1->row;
        newNode->col = temp1->col;
        newNode->value = temp1->value;
        temp3->next=newNode;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }
    while (temp2 != NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->row = temp2->row;
        newNode->col = temp2->col;
        newNode->value = temp2->value;
        temp3->next=newNode;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }

}
void display(node* head) {
    if (head == NULL) {
        printf("Matrix is empty.\n");
        return;
    }

    printf("Sparse Matrix:\n");
    while (head != NULL) {
        printf("(%d | %d | %d\n", head->row, head->col, head->value);
        head = head->next;
    }
}
int main() {
    printf("Enter the first sparse matrix:\n");
    mat1 = input();

    printf("\nEnter the second sparse matrix:\n");
    mat2 = input();

    printf("\nMatrix 1:\n");
    display(mat1);

    printf("\nMatrix 2:\n");
    display(mat2);

    node* mat_add = add(mat1, mat2);
    printf("\nResultant Matrix (Sum of Matrices 1 and 2):\n");
    display(mat_add);

    

    

    return 0;
}
