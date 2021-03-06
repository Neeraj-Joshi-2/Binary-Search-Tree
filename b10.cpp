// Program to convert a BST into a Min-Heap in O(n) time and in-place
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
  
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

void BSTToSortedLL(Node *root, Node **head_ref)
{
    if (root == NULL)
        return;

    BSTToSortedLL(root->right, head_ref);

    root->right = *head_ref;

    if (*head_ref != NULL)
        (*head_ref)->left = NULL;

    *head_ref = root;

    BSTToSortedLL(root->left, head_ref);
}

void SortedLLToMinHeap(Node *&root, Node *head)
{
    if (head == NULL)
        return;

    queue<Node *> q;

    root = head;

    head = head->right;

    root->right = NULL;

    q.push(root);

    while (head)
    {
        Node *parent = q.front();
        q.pop();

        Node *leftChild = head;
        head = head->right;    
        leftChild->right = NULL; 
        q.push(leftChild);

        parent->left = leftChild;

        if (head)
        {
            Node *rightChild = head;
            head = head->right;       
            rightChild->right = NULL;
            q.push(rightChild);
            
            parent->right = rightChild;
        }
    }
}

Node *BSTToMinHeap(Node *&root)
{
    Node *head = NULL;

    BSTToSortedLL(root, &head);

    root = NULL;

    SortedLLToMinHeap(root, head);
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    root->left->left = newNode(2);
    root->left->right = newNode(6);

    BSTToMinHeap(root);

    printLevelOrder(root);

    return 0;
}
