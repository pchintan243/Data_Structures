#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

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

char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int match(int a, int b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    struct stack *ptr;
    ptr->size = 100;
    ptr->top = -1;
    char popped_ch;

    ptr->arr = (char *)malloc(ptr->size * sizeof(char));
    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(ptr, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(ptr))
            {
                return 0;
            }
            popped_ch = pop(ptr);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(ptr))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "{[(8*9)]+(9*2)}";
    if (parenthesisMatch(exp))
    {
        printf("The paranthesis are balanced..!!\n");
    }
    else
    {
        printf("The paranthesis are not balanced..!!\n");
    }
    return 0;
}