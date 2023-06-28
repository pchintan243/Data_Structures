#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "data " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *insertBegin(struct Node *ptr, int data)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));

    q->next = ptr;
    ptr = q;
    q->data = data;

    return ptr;
}

struct Node *insertEnd(struct Node *ptr, int data)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = data;

    struct Node *p = ptr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->next = NULL;
    return ptr;
}

struct Node *insertBetween(struct Node *ptr, int data, int index)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = data;

    int i = 1;
    struct Node *p = ptr;

    while (index != i)
    {
        p = p->next;
        i++;
    }
    q->next = p->next;
    p->next = q;
    return ptr;
}

struct Node *insertAfterNode(struct Node *ptr, struct Node *prev, int data)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = data;

    q->next = prev->next;
    prev->next = q;

    return ptr;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 45;
    head->next = second;
    second->data = 15;
    second->next = third;
    third->data = 25;
    third->next = NULL;

    display(head);

    cout << "---" << endl;
    insertAfterNode(head, third, 200);
    display(head);

    cout << "---" << endl;
    head = insertBegin(head, 34);
    display(head);

    cout << "---" << endl;
    insertEnd(head, 89);
    display(head);

    cout << "---" << endl;
    insertBetween(head, 100, 2);
    display(head);

    return 0;
}