#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("Stack is overflow..!!\n");
        printf("So you cannot push %d to the stack..!!\n", data);
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        // printf("%d ", ptr->arr[ptr->top]);
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow..!!\n");
        return -1;
    }
    else
    {
        char data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}

int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Not a valid position..!!\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-') {
        return 2;
    }
    else {
        return 0;
    }
}


int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    else {
        return 0;
    }
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix traversal

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "x-y/z-k*d";
    printf("Postfix is %s", infixToPostfix(infix));
    return 0;
}