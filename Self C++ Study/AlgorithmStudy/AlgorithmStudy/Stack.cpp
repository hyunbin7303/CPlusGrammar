

/*
FILE		: Stack algorithm


*/

#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
	string data;
	struct node* nextNode;
}Node;


class Stack
{
private:
	int count;
	Node* top;
	Node* list;
public:

	// Default constructor 
	Stack()
	{
		count = 0;
		top = NULL;		// Node in the top
		list = NULL;	// Node in the bottom
	}
	void push(string data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->nextNode = NULL;

		if (list == NULL) list = newNode;
		else
		{
			Node* tmpNode = list; 
			while (tmpNode->nextNode != NULL)
			{
				tmpNode = tmpNode->nextNode;
			}
			tmpNode->nextNode = newNode;
		}
		top = newNode;
		count++;
	}

	Node* pop()
	{
		Node* topNode = top; 
		if (list == NULL) cout << "STACK IS EMPTY	" << endl;
		else if (list == top)
		{
			list = NULL;
			top = NULL;
			count--;
		}
		else
		{
			Node* currentNode = list;
			while (currentNode != NULL && currentNode->nextNode != top)
			{
				currentNode = currentNode->nextNode;

			}
			top = currentNode;
			currentNode->nextNode = NULL;
			count--;
		}
		return topNode;
	}
	int getSize()
	{
		return count;
	}
	bool isEmpty()
	{
		return (list == NULL);
	}

	// Return address of node on the top
	Node* getTop()
	{
		return top;
	}


};



int main()
{
	Stack stack; // Based on Stack class object
	int getSize;

	stack.push("Internet Explorer");
	stack.push("Google Chrome");
	stack.push("Opera");
	stack.push("Netscape");
	stack.push("Mozilla Firefox");
	stack.push("Safari");


	getSize = stack.getSize();
	for (int i = 0; i < getSize; i++)
	{
		if (stack.isEmpty())
		{
			break;
		}
		cout << "Data will be deleted :" << stack.pop()->data << ", ";

		if (!stack.isEmpty())
		{
			cout << "Current top data : " << stack.getTop()->data << endl;

		}
		else
		{
			cout << "Top data is not exist. " << endl;
		}
	}

	return 0;

}