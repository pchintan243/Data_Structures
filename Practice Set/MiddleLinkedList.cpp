#include <iostream>
using namespace std;

struct node
{
    struct node *next;
    int data;
};

void traverse(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

struct node *find(struct node *head)
{
    int i = 0;
    struct node *ptr = head;

    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    i = i / 2;
    while (i--)
    {
        ptr = ptr->next;
    }
    cout << ptr->data;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *third1;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    third1 = (struct node *)malloc(sizeof(struct node));

    head->data = 90;
    head->next = second;

    second->data = 35;
    second->next = third;

    third->data = 42;
    third->next = third1;

    third1->data = 422;
    third1->next = NULL;
    find(head);
    return 0;
}