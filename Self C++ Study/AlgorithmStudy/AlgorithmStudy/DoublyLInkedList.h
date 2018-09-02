#pragma once


template <typename T>
class List
{
public:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node() {}
		Node(T data, Node* prev, Node* next)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};


private:
	Node* m_head;
	Node* m_tail;
	Node* m_cursor;
	int m_count;

	T DeleteNode(Node* node)
	{
		--m_count;

		T data = node->data;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		return data;
	}

	void NewNode(T data, Node* prevNode)
	{
		++m_count;

		Node* newNode = new Node(data, prevNode, prevNode->next);
		prevNode->next->prev = newNode;
		prevNode->next = newNode;
	}

public:
	List()
	{
		m_head = new Node();
		m_tail = new Node();

		m_head->prev = NULL;
		m_head->next = m_tail;
		m_tail->prev = m_head;
		m_tail->next = NULL;
		m_cursor = m_tail;
		m_count = 0;

	}
	~List()
	{
		delete m_head;
		delete m_tail;
	}

	void PushFront(T data)	{ NewNode(data, m_head);		   }
	void PushBack (T data)	{ NewNode(data, m_tail->prev);	   }
	
	T PopFront()			{ return DeleteNode(m_head->next); }
	T PopBack()				{ return DeleteNode(m_tail->prev); }
	
	void Remove(T data)
	{
		for (Node* p = Begin(); p != End(); p = Next())
		{
			if (p->data == data)
			{
				DeleteNode(p);
				break;
			}
		}
	}
	Node* Begin()
	{
		m_cursor = m_head->next;
		return m_cursor;
	}
	Node* Next()
	{
		m_cursor = m_cursor->next;
		return m_cursor;
	}
	Node* prev()
	{
		m_cursor = m_cursor->prev;
		return m_cursor;
	}
	Node* End()
	{
		return m_tail;
	}
	int Count()
	{
		return m_count;
	}
};


