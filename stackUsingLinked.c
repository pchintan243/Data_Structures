#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    int data;
};


void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("You cannot push the %d value ", data);
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
};

// This method is use for returning an integer value.
// In this function you can pass pointer of pointer and address pass in the main function
// If you don't need to pass a pointer of pointer so you can define global structure instead of structure of main function.
// Jo pointer nu pointer na banavu hoy to main function ma j structure 6 tena badle global ma structure banavu.
int popsecond(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack is Underflow..!!\n");
    }
    else
    {
        struct Node *ptr = *top;
        *top = (*top)->next;
        int x = ptr->data;
        free(ptr);
        return x;
    }
}
struct Node *pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Underflow..!!\n");
    }
    else
    {
        struct Node *ptr = top;
        top = top->next;
        int x = ptr->data;
        free(ptr);
        return top;
    }
}

int peek(struct Node * top, int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{

    struct Node *top = NULL;
    top = push(top, 78);
    top = push(top, 178);
    top = push(top, 28);
    top = push(top, 288);
    // int element = popsecond(&top);
    // printf("%d popped from stack..!!\n", element);
    // top = pop(top);
    // traversal(top);

    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is: %d\n", i, peek(top, i));
    }

    return 0;
}