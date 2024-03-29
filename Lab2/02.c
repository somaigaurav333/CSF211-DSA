#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};

typedef struct Node_t Node;
// Creates a new node with given value and returns a pointer to it

Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}
// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}
// Function definition goes here
Node *mergeLists(Node *head1, Node *head2)
{

    Node *head = NULL;
    Node *prev = NULL;
    while ((head1 != NULL) && (head2 != NULL))
    {
        Node *currNode = (Node *)malloc(sizeof(Node));
        if (head == NULL)
        {
            head = currNode;
        }
        int num1 = head1->data;
        int num2 = head2->data;

        if (num1 < num2)
        {
            currNode->data = num1;
            head1 = head1->next;
        }
        else
        {
            currNode->data = num2;
            head2 = head2->next;
        }

        if (prev != NULL)
        {
            prev->next = currNode;
        }

        prev = currNode;
    }

    while (head1 != NULL)
    {
        Node *currNode = (Node *)malloc(sizeof(Node));

        if (head == NULL)
        {
            head = currNode;
        }

        currNode->data = head1->data;

        if (prev != NULL)
        {
            prev->next = currNode;
        }

        prev = currNode;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        Node *currNode = (Node *)malloc(sizeof(Node));

        if (head == NULL)
        {
            head = currNode;
        }

        currNode->data = head2->data;

        if (prev != NULL)
        {
            prev->next = currNode;
        }

        prev = currNode;
        head2 = head2->next;
    }

    return head;
}

int main()
{
    Node *head1 = readList();
    Node *head2 = readList();
    Node *merged = mergeLists(head1, head2);
    printList(merged);
    freeList(head1);
    freeList(head2);
    freeList(merged);
    return 0;
}