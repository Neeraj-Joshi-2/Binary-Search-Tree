// A C++ prgroam to contrcut all unique BSTs for keys from 1 to n
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

void preorder(struct node *root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

vector<node *> constructTrees(int start, int end)
{
	vector<node *> list;

	if (start > end)
	{
		list.push_back(NULL);
		return list;
	}

	for (int i = start; i <= end; i++)
	{
		vector<node *> leftSubtree = constructTrees(start , i - 1);

		vector<node *> rightSubtree = constructTrees(i + 1, end);

		for (int j = 0; j < leftSubtree.size(); j++)
		{
			node* left = leftSubtree[j];

			for (int k = 0; k < rightSubtree.size(); k++)
			{
				node * right = rightSubtree[k];
				node * node = newNode(i);
				node->left = left;			
				node->right = right;		 
				list.push_back(node);	
			}
		}
	}
	return list;
}

int main()
{
	vector<node *> totalTreesFrom1toN = constructTrees(1, 3);

	cout << "Preorder traversals of all constructed BSTs are \n";

	for (int i = 0; i < totalTreesFrom1toN.size(); i++)
	{
		preorder(totalTreesFrom1toN[i]);
		cout << endl;
	}
	return 0;
}
