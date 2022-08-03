#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *previous;
    struct node *next;
    int data;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertAtFirst(struct node *head, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    ptr->next = p;
    ptr->previous = NULL;
    if (p != NULL)
    {
        p->previous = ptr;
    }
    head = ptr;
    return head;
};

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    ptr->previous = p;
    return head;
};
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
    ptr->previous = p;
};

struct node *deleteAtBegin(struct node *head)
{
    struct node *ptr = head;
    struct node *p = head->next;
    p->previous = NULL;
    head = p;
    free(ptr);
    return head;
};

struct node *deleteAtEnd(struct node *head)
{
    struct node *ptr = head;
    struct node *p = head->next;

    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *ptr = head;
    struct node *p = head->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->previous = ptr;
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

    head->previous = NULL;
    head->data = 90;
    head->next = second;

    second->previous = head;
    second->data = 35;
    second->next = third;

    third->previous = second;
    third->data = 42;
    third->next = fourth;

    fourth->previous = third;
    fourth->data = 53;
    fourth->next = NULL;

    int choice;
    printf("Enter the choice:\n1.Insert at first\n2.Insert at end\n3.Insert at index position\n4.Delete at begin\n5.Delete at end\n6.Delete at index position\n7.Display the element\n8.Stop..\n");
    
    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int value, index;
        case 1:
            printf("Enter the value which you want to insert:\n");
            scanf("%d", &value);
            head = insertAtFirst(head, value);
            break;

        case 2:
            printf("Enter the value which you want to insert:\n");
            scanf("%d", &value);
            insertAtEnd(head, value);
            break;
        case 3:
            printf("Enter the value which you want to insert:\n");
            scanf("%d", &value);
            printf("Enter the valid index value:\n");
            scanf("%d", &index);
            insertAtIndex(head, value, index);
            break;
        case 4:
            head = deleteAtBegin(head);
            break;
        case 5:
            deleteAtEnd(head);
            break;
        case 6:
            printf("Enter the valid index value:\n");
            scanf("%d", &index);
            deleteAtIndex(head, index);
            break;
        case 7:
            traversal(head);
            break;
        case 8:
            return 0;
        default:
            printf("please enter the valid choice.\n");
            return 0;
        }
    }
    traversal(head);
    return 0;
}