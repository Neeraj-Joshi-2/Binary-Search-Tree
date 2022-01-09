// reserve path in BST using queue
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void reversePath(node **node, int &key, queue<int> &q1)
{
    if (node == NULL)
        return;

    if ((*node)->key == key)
    {
        q1.push((*node)->key);

        (*node)->key = q1.front();

        q1.pop();

        return;
    }

    else if (key < (*node)->key)
    {
        q1.push((*node)->key);

        reversePath(&(*node)->left, key, q1);

        (*node)->key = q1.front();
        
        q1.pop();
    }

    else if (key > (*node)->key)
    {
        q1.push((*node)->key);
        
        reversePath(&(*node)->right, key, q1);

        (*node)->key = q1.front();

        q1.pop();
    }

    return;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int main()
{
    node *root = NULL;
    queue<int> q1;

    int k = 80;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Before Reverse :" << endl;
    inorder(root);

    cout << "\n";
    reversePath(&root, k, q1);

    cout << "After Reverse :" << endl;
    inorder(root);

    return 0;
}
