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
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertAtFirst(struct node *head, int data)
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
struct node *insertAtEnd(struct node *head, int data)
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
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *deleteAtBegin(struct node *head)
{
    struct node *ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    head = ptr->next;
    free(ptr);
    return head;
};

struct node *deleteAtEnd(struct node *head)
{
    struct node *ptr = head;
    struct node *p = head->next;
    while(p->next != head)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = head;
    free(p);
    return head;
};

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *ptr = head;
    struct node *p = head->next;
    int i = 0;

    while(i != index - 1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    free(p);
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

    head->data = 80;
    head->next = second;

    second->data = 30;
    second->next = third;

    third->data = 20;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = head;

    traversal(head);
    printf("--------\n");
    deleteAtIndex(head,2);
    traversal(head);

    return 0;
}