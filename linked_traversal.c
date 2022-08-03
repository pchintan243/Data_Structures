#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

void linkedtraverse(struct node* ptr)
{

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 64;
    head->next = second;

    second->data = 24;
    second->next = third;

    third->data = 43;
    third->next = NULL;

    linkedtraverse(head);
    return 0;
}