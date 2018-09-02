

#include <iostream>
using namespace std;


class Node
{
private:
	int data;
	Node* left;
	Node* right;

public:
	Node() {}
	//Constructor 
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	void SetData(int data)
	{
		this->data = data;
	}

	void SetLeft(Node* left)
	{
		this->left = left;
	}
	void SetRight(Node* right)
	{
		this->right = right;
	}
	int GetData()
	{
		return data;
	}
	Node* GetLeft()
	{
		return left;
	}
	Node* GetRight()
	{
		return right;
	}

};
class BST
{
private:
	Node* root;
public:
	~BST()
	{
		delete root;
	}
	bool Insert(int data)
	{
		if (root == NULL)
		{
			root = new Node(data);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool bSearchInsert(Node* p, int data)
	{
		if (p->GetData() > data)
		{
			if (p->GetLeft() == NULL)
			{
				p->SetLeft(new Node(data));
				return true;
			}
			else
			{
				return bSearchInsert(p->GetRight(), data);
			}
		}
		else
		{
			if (p->GetRight() == NULL)
			{
				p->SetRight(new Node(data));
				return true;
			}
			else
			{
				return bSearchInsert(p->GetLeft(), data);
			}
		}
	}


	Node* Search(int data)
	{
		return bSearch(this->root, data);
	}


	Node* bSearch(Node* p, int data)
	{
		if (p == NULL)return NULL;
		if (p->GetData() == data) return p;
		if (p->GetData() > data) return bSearch(p->GetLeft(), data);
		else
		{
			return bSearch(p->GetRight(), data);
		}
	}

	Node* min()
	{
		return MinNode(root);
	}



	Node* MinNode(Node* p)
	{
		if (p == NULL)return NULL;
		if (p->GetLeft() == NULL) return p;
		return MinNode(p->GetLeft());
	}

	Node* max()
	{
		return MaxNode(root);
	}
	Node* MaxNode(Node* p)
	{
		if (p == NULL) return NULL;
		if (p->GetRight() == NULL) return p;
		return MaxNode(p->GetRight());
	}

	Node* ParentNode(Node* p, Node* dest)
	{
		Node* left, *right;
		if (p == NULL) return NULL;
	}

	//bool Delete(int data)
	//{
	//	Node *max, *p_max, *tmp;
	//	if (root == NULL) return false;
	//	if (root->GetData() == data)
	//	{
	//		if (root->GetLeft() != NULL)
	//		{
	//			tmp = root;
	//			max = MaxNode(root->GetLeft());
	//			p_max = ParentNode(root, max);
	//			if()
	//		}
	//	}
	//}
	bool Change(int data, int dest)
	{
		if (Search(data) == NULL)return false;
		Insert(dest);
		return true;
	}



};




int main()
{
	BST a;
	Node* Kevin;
	a.Insert(5);
	a.bSearchInsert(Kevin, 10);
	a.bSearchInsert(Kevin, 6);
	a.bSearchInsert(Kevin, 1);
	a.bSearchInsert(Kevin, 4);
	a.bSearchInsert(Kevin, 25);
	a.bSearchInsert(Kevin, 2);
	
	return 0;
}