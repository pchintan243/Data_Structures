#include <iostream>
#include <stdlib.h>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
};

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node *root)
{
    /*
             4
           /   \
          2      6
        /  \    /  \
       1   3   5    7

    */
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *search(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

int main()
{
    struct Node *p = createNode(20);
    struct Node *p1 = createNode(10);
    struct Node *p2 = createNode(30);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(15);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct Node *n = search(p, 15);
    if (n != NULL)
    {
        cout << "Element found: " << n->data << endl;
    }
    else
    {
        cout << "Element not found..!!" << endl;
    }
    return 0;
}