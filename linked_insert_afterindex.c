#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

void traversal(struct node *ptr)
{

    while (ptr != NULL)
    {

        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertafterindex(struct node *head, struct node *previous, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = data;

    ptr->next = previous->next;
    previous->next = ptr;
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 90;
    head->next = second;

    second->data = 35;
    second->next = third;

    third->data = 42;
    third->next = fourth;

    fourth->data = 53;
    fourth->next = NULL;

    traversal(head);
    head = insertafterindex(head,third,43);
    printf("After insertion:\n");
    traversal(head);
    return 0;
}