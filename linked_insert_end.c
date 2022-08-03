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
struct node *insertatend(struct node *head, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;   
    }
    p->next = ptr;
    ptr->next = NULL;

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
    head = insertatend(head, 87);
    printf("After insertion:\n");
    traversal(head);
    return 0;
}