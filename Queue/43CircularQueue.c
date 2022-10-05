#include <stdio.h>
#include <stdlib.h>
struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct CircularQueue *q)
{
    if ((q->r + 1) % (q->size) == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct CircularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct CircularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is overflow..!!\n");
    }

    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", q->arr[q->r]);
    }
}

int dequeue(struct CircularQueue *q)
{
    int a = -1;

    if (isEmpty(q))
    {
        printf("Queue is underflow..!!\n");
    }
    else
    {
        q->f = (q->f + 1) % (q->size);
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct CircularQueue *q;
    q->size = 100;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 1);
    enqueue(q, 14);
    printf("Dequeing element: %d\n", dequeue(q));
    printf("Dequeing element: %d\n", dequeue(q));
    printf("Dequeing element: %d\n", dequeue(q));
    enqueue(q, 11);
    enqueue(q, 10);
    if (isFull(q))
    {
        printf("Queue is overflow..!!\n");
    }
    if (isEmpty(q))
    {
        printf("Queue is underflow..!!\n");
    }

    return 0;
}