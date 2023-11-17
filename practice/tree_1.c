#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value <= root->value + 5)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void printInOrder(struct Node *root, int parent, char direction)
{
    if (root != NULL)
    {
        printInOrder(root->left, root->value, "L");
        printf("%d (%d,%c)\n", root->value, parent, direction);
        printInOrder(root->right, root->value, "L");
    }
}

int main()
{
    // Generate 20 random numbers
    int randomNumbers[20];
    for (int i = 0; i < 20; ++i)
    {
        randomNumbers[i] = rand() % 99 + 1;
    }

    // Initialize the root of the tree
    struct Node *rootNode = NULL;

    // Insert numbers into the tree
    for (int i = 0; i < 20; ++i)
    {
        rootNode = insertNode(rootNode, randomNumbers[i]);
    }

    // Print the tree in in-order with directions
    printf("In-Order Traversal with Directions:\n");
    printInOrder(rootNode, 0, "");

    return 0;
}
