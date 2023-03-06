#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 505

struct Queue
{
    int front;
    int back;
    int size;
    int arr[SIZE];
};

typedef struct Queue Queue;

Queue *makeQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->back = -1;
    q->size = 0;
    return q;
}

void push(Queue *q, int val)
{
    if (q->back == -1)
    {
        q->front = 0;
        q->back = 0;
    }
    else
    {
        q->back = (q->back + 1) % SIZE;
    }

    q->size++;
    q->arr[q->back] = val;
}

void pop(Queue *q)
{
    if (q->front == -1)
    {
        return;
    }

    q->front = (q->front + 1) % SIZE;
    q->size--;
}

int top(Queue *q)
{

    if (q->front == -1)
    {
        return -1;
    }

    return q->arr[q->front];
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);
    Queue *q = makeQueue();
    for (int i = 1; i <= n; i++)
    {
        push(q, i);
    }

    int currele = 0;
    while (q->size > 1)
    {
        currele++;
        int t = top(q);
        pop(q);
        if (currele % k == 0)
        {
            currele = 0;
        }
        else
        {
            push(q, t);
        }
    }

    printf("%d\n", top(q));

    return 0;
}