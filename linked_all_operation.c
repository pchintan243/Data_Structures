#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Values %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatbegin(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while (p->next != NULL)
    {

        p = p->next;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *insertatindex(struct node *head, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertafterindex(struct node *head, struct node *previous, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    ptr->data = data;
    ptr->next = previous->next;
    previous->next = ptr;
    return head;
}

struct node *deleteatfirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteatend(struct node *head)
{
    struct node *ptr = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

struct node *deleteatindex(struct node *head, int index)
{
    struct node *ptr = head;
    struct node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

struct node *deletebyvalue(struct node *head, int value)
{
    struct node *ptr = head;
    struct node *q = head->next;

    while (q->next != NULL && q->data != value)
    {

        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == value)
    {

        ptr->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 90;
    head->next = second;

    second->data = 35;
    second->next = third;

    third->data = 42;
    third->next = NULL;

    int s;
    printf("Your linked list :\n");
    traverse(head);
    printf("\n");

    while (1)
    {
        printf("1.Insert at begin..!!\n2.Insert at end..!!\n3.Insert at index..!!\n4.Insert after index..!!\n");
        printf("5.delete at begin..!!\n6.delete at end..!!\n7.delete at index..!!\n8.delete by value..!!\n9.see list..!!\n10.Quit..!! \n");
        printf("Enter the choice :\n");
        scanf("%d", &s);
        switch (s)
        {
            int n;
            int ind;
        case 1:
            printf("Enter the number: ");
            scanf("%d", &n);
            head = insertatbegin(head, n);
            break;

        case 2:
            printf("Enter the number: ");
            scanf("%d", &n);
            insertatend(head, n);
            break;

        case 3:
            printf("Enter the number: ");
            scanf("%d", &n);
            printf("Enter the index: ");
            scanf("%d", &ind);
            insertatindex(head, ind, n);
            break;

        case 4:
            printf("Enter the number: ");
            scanf("%d", &n);
            insertafterindex(head, second, n);
            break;

        case 5:
            head = deleteatfirst(head);
            break;

        case 6:
            deleteatend(head);
            break;

        case 7:
            printf("Enter the index: ");
            scanf("%d", &ind);
            deleteatindex(head, ind);
            break;

        case 8:
            deletebyvalue(head, 35);
            break;
        case 9:
            traverse(head);
            break;
        case 10:
            return 0;
        default:
            return 0;
        }
    }

    printf("\nAfter all operation your linked list is :\n");
    traverse(head);
    return 0;
}