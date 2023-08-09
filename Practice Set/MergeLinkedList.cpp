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

struct node *find(struct node *head, struct node *third)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = third;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *third1 = (struct node *)malloc(sizeof(struct node));

    head->data = 90;
    head->next = second;

    second->data = 35;
    second->next = NULL;

    third->data = 42;
    third->next = third1;

    third1->data = 422;
    third1->next = NULL;
    find(head, third);
    traverse(head);
    return 0;
}