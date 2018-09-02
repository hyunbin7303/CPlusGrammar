#pragma once
#include <iostream>

using namespace std;

namespace Node {
	enum COLOR { RED, BLACK };

	template <typename T>
	class rbtNode {
	public:
		static rbtNode<T>* makeInstance(T _data, COLOR col);
		T& getData();
		rbtNode<T>* getLeftChild();
		rbtNode<T>* getRightChild();
		rbtNode<T>* getParent();
		rbtNode<T>* getGrandParent();
		rbtNode<T>* getUncle();

		void setLeftChild(rbtNode<T>* newNode);
		void setRightChild(rbtNode<T>* newNode);
		void setParent(rbtNode<T>* newNode);

		COLOR getColor();
		void setColor(COLOR _col);

	private:
		rbtNode<T>(T _data, COLOR col);
		rbtNode<T>() {}

	private:
		T data;
		rbtNode<T>* Parent;
		rbtNode<T>* LeftChild;
		rbtNode<T>* RightChild;
		COLOR nodeColor;
	};


	template <typename T>
	rbtNode<T>* rbtNode<T>::makeInstance(T _data, COLOR col)
	{
		return new rbtNode(_data, col);
	}

	template <typename T>
	rbtNode<T>::rbtNode(T _data, COLOR col) : LeftChild(nullptr), RightChild(nullptr)
	{
		this->data = _data;
		this->nodeColor = col;
	}

	template <typename T>
	T& rbtNode<T>::getData()
	{
		return this->data;
	}

	template <typename T>
	rbtNode<T>* rbtNode<T>::getLeftChild()
	{
		return this->LeftChild;
	}

	template <typename T>
	rbtNode<T>* rbtNode<T>::getRightChild()
	{
		return this->RightChild;
	}

	template <typename T>
	rbtNode<T>* rbtNode<T>::getParent()
	{
		return this->Parent;
	}




	template <typename T>
	rbtNode<T>* rbtNode<T>::getGrandParent()
	{
		rbtNode<T>* parent = this->getParent();
		if (parent == nullptr)
			return nullptr;

		return parent->getParent();
	}

	template <typename T>
	rbtNode<T>* rbtNode<T>::getUncle()
	{
		rbtNode<T>* grandParent = this->getGrandParent();
		if (grandParent == nullptr)
			return nullptr;


		if (grandParent->getLeftChild() == this->getParent())
			return grandParent->getRightChild();

		return grandParent->getLeftChild();
	}

	template <typename T>
	void rbtNode<T>::setLeftChild(rbtNode<T>* newNode)
	{
		this->LeftChild = newNode;
	}

	template <typename T>
	void rbtNode<T>::setRightChild(rbtNode<T>* newNode)
	{
		this->RightChild = newNode;
	}

	template <typename T>
	void rbtNode<T>::setParent(rbtNode<T>* newNode)
	{
		this->Parent = newNode;
	}

	template <typename T>
	COLOR rbtNode<T>::getColor()
	{
		return this->nodeColor;
	}

	template <typename T>
	void rbtNode<T>::setColor(COLOR _col)
	{
		this->nodeColor = _col;
	}


} //End of namespace