#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        if (t == NULL)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << t->val << " ";

            q.push(t->left);
            q.push(t->right);
        }
    }
}

unordered_map<int, int> indices; // value : index

Node *buildTree(int preorder[], int inorder[], int prest, int preend, int inst, int inend)
{

    if (inst > inend)
    {
        return NULL;
    }

    Node *root = new Node(preorder[prest]);

    int index = indices[preorder[prest]];
    int sz = index - inst;

    root->left = buildTree(preorder, inorder, prest + 1, prest + sz, inst, index - 1);
    root->right = buildTree(preorder, inorder, prest + sz + 1, preend, index + 1, inend);

    return root;
}

int main()
{
    int n;
    cin >> n;
    int preorder[n];
    int inorder[n];

    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        indices[inorder[i]] = i;
    }

    Node *root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1);

    printTree(root);

    return 0;
}