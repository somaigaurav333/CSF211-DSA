#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
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

Node *createNode(int val)
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

Node *addNode(DLL *dll, int val)
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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        addNode(dll, val);
    }

    return dll;
}

int main()
{
    DLL *dll1 = readDLL();
    return 0;
}