#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    long val;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

struct DLL
{
    Node *head;
    Node *tail;
};

typedef struct DLL DLL;

Node *createNode(long val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

DLL *createDLL()
{
    DLL *dll = (DLL *)malloc(sizeof(DLL));
    dll->head = NULL;
    dll->tail = NULL;
    return dll;
}

Node *addNode(DLL *dll, long val)
{
    Node *newNode = createNode(val);
    if (dll->head == NULL)
    {
        dll->head = newNode;
        dll->tail = newNode;
    }
    else
    {
        dll->tail->next = newNode;
        newNode->prev = dll->tail;
        dll->tail = newNode;
    }

    return newNode;
}

DLL *readDLL()
{

    DLL *dll = createDLL();
    long n;
    scanf("%ld", &n);
    for (long i = 0; i < n; i++)
    {
        long val;
        scanf("%ld", &val);
        addNode(dll, val);
    }

    return dll;
}

void maxTeamStrength(DLL *dll)
{

    Node *l = dll->head;
    Node *r = dll->tail;
    long lstrength = 0, rstrength = 0;
    long lcount = 0, rcount = 0;
    long currlcount = 0, currrcount = 0;

    while (l != (r->next))
    {
        if (lstrength <= rstrength)
        {
            lstrength += l->val;
            currlcount++;
            l = l->next;
        }
        else
        {
            rstrength += r->val;
            currrcount++;
            r = r->prev;
        }

        if (lstrength == rstrength)
        {
            lcount = currlcount;
            rcount = currrcount;
        }
    }

    printf("%ld %ld\n", lcount, rcount);
}

int main()
{
    DLL *dll1 = readDLL();
    maxTeamStrength(dll1);
    return 0;
}