// C++ Program to change a BST to Binary Tree such that key of a node becomes original
// key plus sum of all greater keys in BST
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node* left;
	struct node* right;
};

struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void addGreaterUtil(struct node *root, int *sum_ptr)
{
	if (root == NULL)
		return;

	addGreaterUtil(root->right, sum_ptr);

	*sum_ptr = *sum_ptr + root->key;

	root->key = *sum_ptr;

	addGreaterUtil(root->left, sum_ptr);
}


void addGreater(struct node *root)
{
	int sum = 0;
	addGreaterUtil(root, &sum);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->key << " " ;
	printInorder(node->right);
}

int main()
{
	node *root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(13);

	cout << "Inorder traversal of the given tree" << endl;
	printInorder(root);

	addGreater(root);
	cout << endl;
	cout << "Inorder traversal of the modified tree" << endl;
	printInorder(root);

	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

Node *newNode(int item)
{
    Node *temp = new Node();
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void Greater_BST(Node *root)
{
    int sum = 0;
    stack<Node *> st;
    Node *node = root;

    while (!st.empty() || node != NULL)
    {
        while (node != NULL)
        {
            st.push(node);
            node = node->right;
        }

        node = st.top();
        st.pop();
        sum += node->data;
        node->data = sum;

        node = node->left;
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return newNode(data);
    if (data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 8);
    insert(root, 5);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 9);
    insert(root, 15);

    Greater_BST(root);

    inorder(root);

    return 0;
}

*/