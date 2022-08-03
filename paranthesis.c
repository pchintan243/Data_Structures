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

int parenthesisMatch(char *exp)
{
    struct stack *ptr;
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));
    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(ptr, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(ptr))
            {
                return 0;
            }
            pop(ptr);
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
    char *exp = "((8*9)+(9*2))";
    if (parenthesisMatch(exp))
    {
        printf("The paranthesis is matching..!!\n");
    }
    else
    {
        printf("The paranthesis is not matching..!!\n");
    }
    return 0;
}