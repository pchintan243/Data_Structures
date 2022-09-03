#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
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

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is overflow..!!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", q->arr[q->r]);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;

    if (isEmpty(q))
    {
        printf("Queue is underflow..!!\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}
int main()
{
    struct queue *q;
    q->size = 100;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 1);
    printf("Dequeing element: %d\n", dequeue(q));
    printf("Dequeing element: %d\n", dequeue(q));
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