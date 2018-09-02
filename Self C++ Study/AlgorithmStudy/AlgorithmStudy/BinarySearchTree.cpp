

#include <iostream>
using namespace std;

class treeNode
{
	friend class tree;
private:
	int value;
	treeNode *left, *right;
	treeNode(int val) : value(val), left(NULL), right(NULL) {}	

};


class tree
{
private:
	void recursiveInsert(treeNode *&, int);
	void recursiveRemove(treeNode *&, int);
	void preorderRecursivePrint(treeNode*);
	void postorderRecursivePrint(treeNode*);
	void inorderRecursivePrint(treeNode*);
public:
	treeNode *root;
	tree() : root(NULL) {}
	void insert(int);
	void remove(int);
	void preorderPrint();
	void postorderPrint();
	void inorderPrint();

};



void tree::recursiveInsert(treeNode *&node, int val)
{
	if (node == NULL)
	{	// make new node if searching node is NULL.
		node = new treeNode(val);
	}
	else if (val > node->value)
	{	// value is larger than node...searching right child
		recursiveInsert(node->right, val);
	}
	else if (val < node->value)
	{	
		recursiveInsert(node->left, val);
	}
}

void tree::recursiveRemove(treeNode *&node, int val)
{
	treeNode *removal = new treeNode(0);

	if (node == NULL)
	{ // Case that didn't find node. 
		return;
	}
	else if (val > node->value)
	{ 
		recursiveRemove(node->right, val);
	}
	else if (val < node->value)
	{
		recursiveRemove(node->left, val);
	}
	else 
	{	
		if (node->left == NULL && node->right == NULL)
		{
			delete node;
			node = NULL;
		}
		else if (node->left == NULL)
		{
			removal = node;
			node = node->right;
			delete removal;
		}
		else if (node->right == NULL)
		{
			removal = node;
			node = node->left;
			delete removal;
		}

		// case 3 : NODE CHILD ARE 2 
		else
		{
			removal = node->right;
			while (removal->left != NULL)
			{
				removal = removal->left;

			}
			int minVal = removal->value;
			recursiveRemove(root, minVal);
			node->value = minVal;
		}
	}
}

void tree::preorderRecursivePrint(treeNode *node)
{
	if (node != NULL)
	{
		cout << node->value << endl;
		preorderRecursivePrint(node->left);
		preorderRecursivePrint(node->right);
	}
}

void tree::inorderRecursivePrint(treeNode *node)
{
	if (node != NULL)
	{
		inorderRecursivePrint(node->left);	// 
		cout << node->value << endl;		// Print out
		inorderRecursivePrint(node->right);
	}
}

void tree::postorderRecursivePrint(treeNode *node)
{
	if (node != NULL)
	{
		postorderRecursivePrint(node->left);
		postorderRecursivePrint(node->right);
		cout << node->value << endl;
	}
}



void tree::insert(int val)
{
	recursiveInsert(root, val);
}

void tree::remove(int val)
{
	recursiveRemove(root, val);
}

void tree::preorderPrint()
{
	cout << "PREORDER " << endl;
	preorderRecursivePrint(root);
}

void tree::inorderPrint()
{
	cout << "INORDER " << endl;
	inorderRecursivePrint(root);
}

void tree::postorderPrint()
{
	cout << "POSTORDER " << endl;
	postorderRecursivePrint(root);
}


int main()
{
	tree a;
	a.insert(50);
	a.insert(40);
	a.insert(60);
	a.insert(70);
	a.insert(80);
	a.insert(90);
	a.insert(85);
	a.insert(95);
	a.insert(65);
	a.insert(75);

	a.postorderPrint();

	a.remove(70);
	a.postorderPrint();

}