#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

void traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertatfirst(struct node *head, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {

        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
};

struct node *insertatend(struct node *head, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {

        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
};

struct node *insertatindex(struct node *head, int index, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head->next;
    int i = 0;
    while (i != index - 2)
    {

        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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
    fourth->next = head;

    traversal(head);

    printf("After insertion :\n");
    head = insertatfirst(head, 46);
    traversal(head);

    printf("After insertion :\n");
    insertatend(head, 54);
    traversal(head);

    printf("After insertion :\n");
    insertatindex(head, 2, 66);
    traversal(head);
    return 0;
}