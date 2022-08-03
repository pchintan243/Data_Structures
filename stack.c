#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
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

void push(struct stack *ptr, int data)
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
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow..!!\n");
        return -1;
    }
    else
    {
        int data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}

int peek(struct stack *ptr, int i)
{
    if(ptr->top - i + 1 < 0)
    {
        printf("Not a valid position..!!\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // s->arr[0] = 56;
    // s->top = s->top++;
    push(s, 56);
    push(s, 12);
    push(s, 120);
    push(s, 121);
    push(s, 122);
    
    for(int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }

    pop(s);
    return 0;
}