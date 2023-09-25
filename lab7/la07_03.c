/* Write a program to convert infix expression to postfix operation using stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    else
    {
        return '$';
    }
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char *infix, char *postfix)
{
    struct Stack *stack = createStack(strlen(infix));
    int i, j;
    for (i = 0, j = -1; infix[i]; ++i)
    {
        if (isOperand(infix[i]))
        {
            postfix[++j] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[++j] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
            {
                return;
            }
            else
            {
                pop(stack);
            }
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
            {
                postfix[++j] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack))
    {
        postfix[++j] = pop(stack);
    }
    postfix[++j] = '\0';
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}