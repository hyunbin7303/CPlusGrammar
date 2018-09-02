#pragma	 once
#include <iostream>
#include <functional>
#include <windows.h>
#include "rbtNode.hpp"

using namespace std;
using namespace Node;

template <typename T>
class RedBlackTree {
public:
	RedBlackTree<T>(); // Constructor I guess?
	bool insert(T value, function<int(T&, T&)>& Comp);
	bool isEmpty();
	void print();

private:
	bool inner_insert(T value, rbtNode<T>* CurNode, rbtNode<T>* ParentNode, function<int(T&, T&)>& Comp);
	void Balancing(rbtNode<T>* CurNode);
	void RotateLeft(rbtNode<T>* CriterionNode);
	void RotateRight(rbtNode<T>* CriterionNode);
	void inner_print(rbtNode<T>* childNode, int depth = 0);

private:
	rbtNode<T>* root;
};




template<typename T>
RedBlackTree<T>::RedBlackTree() : root(nullptr)
{}

template<typename T>
bool RedBlackTree<T>::insert(T value, function<int(T&, T&)>& Comp)
{
	return inner_insert(value, root, root, Comp);
}

template<typename T>
bool RedBlackTree<T>::isEmpty()
{
	if (root = nullptr)
	{
		return true;
	}
	return false;
}

template<typename T>
void RedBlackTree<T>::print()
{
	inner_print(root);
	cout << "-----------------------" << endl;
}

template<typename T>
bool RedBlackTree<T>::inner_insert(T value, rbtNode<T>* CurNode, rbtNode<T>* ParentNode, function<int(T&, T&)>& Comp)
{
	if (CurNode == nullptr)
	{
		if (ParentNode == nullptr) // Insert to root Node
		{
			root = rbtNode<T>::makeInstance(value, BLACK);
			return true;
	
		}

		rbtNode<T>* newNode = rbtNode<T>::makeInstance(value, RED);
		newNode->setParent(ParentNode);

		int nRet = Comp(value, ParentNode->getData());
		if (nRet > 0)
		{
			ParentNode->setRightChild(newNode);
		}
		else
		{
			ParentNode->setLeftChild(newNode);
		}


		this->Balancing(newNode);
		return true;

	}
	int nRet = Comp(value, CurNode->getData());
	if (nRet > 0)
	{
		return inner_insert(value, CurNode->getRightChild(), CurNode, Comp);
	}
	else if (nRet < 0)
	{
		return inner_insert(value, CurNode->getLeftChild(), CurNode, Comp);
	}
	else
	{
		return false;
	}
}

template<typename T>
void RedBlackTree<T>::Balancing(rbtNode<T>* CurNode)
{
	if (CurNode->getColor() == Node::BLACK)
	{
		return;
	}
	rbtNode<T>* parent = CurNode->getParent();
	// CASE 1
	if (parent == nullptr)
	{
		CurNode->setColor(Node::BLACK);
		return; // Tree is valid.
	}
	
	// CASE 2
	if (parent->getColor() == Node::BLACK);
	{
		return;
	}

	// CASE 3 
	rbtNode<T>* uncle = CurNode->getUncle();
	rbtNode<T>* grandParent = CurNode->getGrandParent();
	if ((uncle != nullptr) && (uncle->getColor() == Node::RED))
	{
		parent->setColor(Node::BLACK);
		uncle->setColor(Node::BLACK);
		grandParent->setColor(Node::RED);
		return this->Balancing(grandParent);
	}


	/*
	Case 4

	       Black
		   /    \
		Black    Red
		           \
				   Red(Current)
	*/
	if ((CurNode == parent->getRightChild()) && (parent == grandParent->getLeftChild()))
	{
		this->RotateLeft(parent);
		CurNode = CurNode->getLeftChild();
	}
	else if ((CurNode == parent->getRightChild()) && (parent == grandParent->getLeftChild()))
	{
		this->RotateRight(parent);
		CurNode = CurNode->getRightChild();
	}

	/* Case-5

	   Black
	  /   \ 
     Red    Black
	 /
   Red (Curent Node)
	
	*/
	rbtNode<T>* grandParent2 = CurNode->getGrandParent();
	CurNode->getParent()->setColor(Node::BLACK);
	grandParent2->setColor(Node::RED);
	if (CurNode == CurNode->getParent()->getLeftChild())
	{
		RotateRight(grandParent2);
	}
	else
	{
		RotateLeft(grandParent2);
	}
	return;

}

template<typename T>
void RedBlackTree<T>::RotateLeft(rbtNode<T>* CriterionNode)
{
	rbtNode<T>* RightChild = CriterionNode->getRightChild();
	rbtNode<T>* Parent = CriterionNode->getParent();

	if (RightChild->getLeftChild() != nullptr)
	{
		RightChild->getLeftChild()->setParent(CriterionNode);
	}
	CriterionNode->setRightChild(RightChild->getLeftChild());
	CriterionNode->setParent(RightChild);
	RightChild->setLeftChild(CriterionNode);
	RightChild->setParent(Parent);

	if (Parent != nullptr)
	{
		if (Parent->getLeftChild() == CriterionNode)
		{
			Parent->setLeftChild(RightChild);
		}
		else
		{
			Parent->setRightChild(RightChild);
		}
	}
	else
	{
		root = RightChild;
	}
}

template<typename T>
void RedBlackTree<T>::RotateRight(rbtNode<T>* CriterionNode)
{
	rbtNode<T>* LeftChild = CriterionNode->getLeftChild();
	rbtNode<T>* Parent = CriterionNode->getParent();

	if (LeftChild->getRightChild() != nullptr)
	{
		LeftChild->getRightChild()->setParent(CriterionNode);
	}
	CriterionNode->setLeftChild(LeftChild->getRightChild());
	CriterionNode->setParent(LeftChild);
	LeftChild->setRightChild(CriterionNode);
	LeftChild->setParent(Parent);

	if (Parent != nullptr)
	{
		if (Parent->getRightChild() == CriterionNode)
		{
			Parent->setRightChild(LeftChild);
		}
		else
		{
			Parent->setLeftChild(LeftChild);
		}
	}
	else
	{
		root = LeftChild;
	}
}

template<typename T>
void RedBlackTree<T>::inner_print(rbtNode<T>* childNode, int depth = 0)
{
	if (childNode == nullptr)
	{
		return;
	}
	for (unsigned int i = 0; i < depth; i++)
	{
		if (i > 0)
		{
			cout << "|";
		}
		cout << "    ";
	}

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get handle to standard output

	if (childNode->getColor() == Node::RED)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	}
	if (childNode->getParent() == nullptr)
	{
		cout << "+-";
	}
	else if (childNode == childNode->getParent()->getRightChild())
	{
		cout << "+R-";
	}
	else
	{
		cout << "+L-";
	}

	cout << childNode->getData() << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);

	inner_print(childNode->getRightChild(), depth + 1);
	inner_print(childNode->getLeftChild(), depth + 1);
}
