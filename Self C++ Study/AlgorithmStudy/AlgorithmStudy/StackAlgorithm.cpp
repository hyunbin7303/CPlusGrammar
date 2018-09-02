
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
	struct Node
	{
		T data;
		Node* prev;
		Node(T data, Node* prev)
		{
			this->data = data;
			this->prev = prev;
		}
	};

	Node* m_cursor;
	int m_count;

public:
	Stack()
	{
		m_cursor = NULL;
		m_count = 0;
	}

	void Push(T data)
	{
		m_count++;

		Node* newNode = new Node(data, m_cursor);
		m_cursor = newNode;
	}

	void Pop()
	{
		if (m_count <= 0)
		{
			return NULL;
		}
		m_count--;

		Node* node = m_cursor;
		T data = m_cursor->data;
		m_cursor = m_cursor->prev;

		delete node;
		return data;
	}

	T Peek()
	{
		if (m_count <= 0)
		{
			return NULL;
		}
		return m_cursor->data;
	}
	int Count() { return m_count; }

};



void TestStack()
{
	Stack<string> stack;
	stack.Push("AA");
	stack.Push("BB");
	stack.Push("CC");
	stack.Push("DD");
	stack.Push("EE");
	stack.Push("FF");
	stack.Push("GG");

	cout << "PEEK " << stack.Peek() << endl;
	
	cout << "POP " << stack.Pop() << endl;
	cout << "PEEK " << stack.Peek() << endl;

	cout << "POP " << stack.Pop() << endl;
	cout << "PEEK " << stack.Peek() << endl;
	cout << "POP " << stack.Pop() << endl;

	
}

int main()
{
	TestStack();

	return 0;
}