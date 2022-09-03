#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    struct Node *next;
    int data;
};

struct Node *f = NULL;
struct Node *r = NULL;

void traverse(struct Node *ptr)
{
    cout << "Printing the element of the linked list:" << endl;
    while (ptr != NULL)
    {
        cout << "Values: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        cout << "Queue is Full..!!" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = n;
            r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        cout << "Queue is Empty..!!" << endl;
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    enqueue(21);
    enqueue(1);
    enqueue(34);
    traverse(f);
    cout << "After dequeing an element from the queue:" << endl;
    dequeue();
    dequeue();
    dequeue();
    traverse(f);
    return 0;
}