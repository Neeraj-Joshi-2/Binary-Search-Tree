// C++ program to Check given array
// can represent BST or not
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *right, *left;
};

Node *newNode(int num)
{
    Node *temp = new Node;
    temp->key = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *createNLevelTree(int arr[], int n)
{
    Node *root = newNode(arr[0]);

    Node *temp = root;

    for (int i = 1; i < n; i++)
    {
        if (temp->key > arr[i])
        {
            temp->left = newNode(arr[i]);
            temp = temp->left;
        }
        else
        {
            temp->right = newNode(arr[i]);
            temp = temp->right;
        }
    }
    return root;
}

bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->key < min || root->key > max)
        return false;

    return (isBST(root->left , min , (root->key) - 1) && isBST(root->right , (root->key) + 1 , max));
}

bool canRepresentNLevelBST(int arr[], int n)
{
    Node *root = createNLevelTree(arr, n);
    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{
    int arr[] = {512, 330, 78, 11, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canRepresentNLevelBST(arr, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
/*
// C++ program to Check given array
// can represent BST or not
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5123, 3300, 783, 1111, 890};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MAX;
    int min = INT_MIN;
    bool flag = true;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > min && arr[i] < max)
        {
            min = arr[i - 1];
        }

        else if (arr[i] < arr[i - 1] && arr[i] > min && arr[i] < max)
        {
            max = arr[i - 1];
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}

*/