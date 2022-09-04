#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int r;
    int f;
    int *arr;
};

int isFull(struct Queue *q)
{
    if ((q->f == 0 && q->r == q->size - 1) || (q->f == q->r + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueueFront(struct Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue is Overflow..!!" << endl;
    }
    else if ((q->f == -1) && (q->r == -1))
    {
        q->f = 0;
        q->r = 0;
    }
    else if (q->f == 0)
    {
        q->f = q->size - 1;
    }
    else
    {
        q->f = q->f - 1;
    }
    q->arr[q->f] = val;
    cout << "Enqueued element by front: " << q->arr[q->f] << endl;
}

void enqueueRear(struct Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue is Overflow..!!" << endl;
    }
    else if ((q->f == -1) && (q->r == -1))
    {
        q->r = 0;
    }
    else if (q->r == q->size - 1)
    {
        q->r = 0;
    }
    else
    {
        q->r = q->r + 1;
    }
    q->arr[q->r] = val;
    cout << "Enqueued element by rear: " << q->arr[q->r] << endl;
}

void dequeueF(struct Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is Underflow..!!" << endl;
    }
    else if (q->f == q->r)
    {
        q->f = -1;
        q->r = -1;
    }
    else if (q->f == q->size - 1)
    {
        q->f = 0;
    }
    else
    {
        q->f = q->f + 1;
    }
    cout << "Dequeued element by front: " << q->arr[q->f] << endl;
}

void dequeueR(struct Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is Underflow..!!" << endl;
    }
    else if (q->f == q->r)
    {
        q->f = -1;
        q->r = -1;
    }
    else if (q->r == 0)
    {
        q->r = q->size - 1;
    }
    else
    {
        q->r = q->r - 1;
    }
    cout << "Dequeued element by front: " << q->arr[q->r] << endl;
}

void display(struct Queue *q)
{
    int i = q->f;
    while (i != q->r)
    {
        cout << "Element: " << q->arr[i] << endl;
        i = (i + 1) % q->size;
    }
    cout << "Element: " << q->arr[q->r] << endl;
}

int main()
{
    struct Queue *q;
    q->f = -1;
    q->r = -1;
    q->size = 6;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueFront(q, 9);
    enqueueFront(q, 19);
    enqueueRear(q, 29);
    enqueueFront(q, 39);
    enqueueRear(q, 49);
    enqueueRear(q, 59);
    display(q);
    return 0;
}