#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000005

struct Deque
{
    int front;
    int back;
    int size;
    int arr[SIZE];
};

typedef struct Deque Deque;

Deque *makeDeque()
{
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->front = -1;
    d->back = -1;
    d->size = 0;
    return d;
}

void printDeque(Deque *d)
{
    for (int i = 0; i < d->size; i++)
    {
        printf("%d ", d->arr[(d->front + i) % SIZE]);
    }
}

void pushFront(Deque *d, int val)
{
    if (d->front == -1)
    {
        d->front = 0;
        d->back = 0;
    }
    else
    {
        d->front = (d->front - 1 + SIZE) % SIZE;
    }

    d->size++;
    d->arr[d->front] = val;
}

void pushBack(Deque *d, int val)
{
    if (d->back == -1)
    {
        d->front = 0;
        d->back = 0;
    }
    else
    {
        d->back = (d->back + 1) % SIZE;
    }

    d->size++;
    d->arr[d->back] = val;
}

int getFront(Deque *d)
{

    return d->arr[d->front];
}

// popFront, popBack & getBack functions not req for this q

int main()
{
    Deque *d = makeDeque();
    int n;
    scanf("%d", &n);
    int element;
    scanf("%d", &element);
    pushFront(d, element);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &element);
        if (element <= getFront(d))
        {
            pushFront(d, element);
        }
        else
        {
            pushBack(d, element);
        }
    }

    printDeque(d);
    printf("\n");

    return 0;
}