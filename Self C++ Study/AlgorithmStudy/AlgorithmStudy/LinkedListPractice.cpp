#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;

};


void initNode(struct Node *head, int n)
{
	head->data = n;
	head->next = NULL;
}

void addNode(struct Node *head, int n)
{
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while (cur)
	{
		if (cur->next == NULL)
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertFront(struct Node **head, int n)
{
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}


struct Node *searchNode(struct Node *head, int n)
{
	Node *cur = head;
	while (cur)
	{
		if (cur->data == n)
		{
			return cur;
		}
		cur = cur->next;

	}
	cout << "No Node " << n << "in List. \n";
}

bool deleteNode(struct Node **head, Node *ptrDel)
{
	Node *cur = *head;
	if (ptrDel == *head)
	{
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	while (cur)
	{
		if (cur->next == ptrDel)
		{
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}


struct Node* reverse(struct Node** head)
{
	Node* parent = *head;
	Node *me = parent->next;
	Node *child = me->next;

	parent->next = NULL;
	while (child)
	{
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}

void copyLinkedList(struct Node *node, struct Node **pNew)
{
	if (node != NULL)
	{
		*pNew = new Node;
		(*pNew)->data = node->data;
		(*pNew)->next = NULL;
		copyLinkedList(node->next, &((*pNew)->next));
	}
}


// Return value : same(1),
//                different(0)
int compareLinkedList(struct Node *node1, struct Node *node2)
{
	static int flag;
	if (node1 == NULL && node2 == NULL)
	{
		flag = 1;
	}
	else
	{
		if (node1 == NULL || node2 == NULL)
		{
			flag = 0;
		}
		else if (node1->data != node2->data)
		{
			flag = 0;
		}
		else
		{
			compareLinkedList(node1->next, node2->next);
		}
	}
	return flag;
}

void deleteLinkedList(struct Node **node)
{
	struct Node *tmp;
	while (*node)
	{
		tmp = *node;
		*node = tmp->next;
		delete tmp;
	}
}
void display(struct Node *head)
{
	Node *list = head;
	while (list)
	{
		cout << list->data << endl;
		list = list->next;
	}
	cout << endl;
}


int main()
{
	struct Node *newHead;
	struct Node *head = new Node;
	initNode(head, 10);
	addNode(head, 20);
	addNode(head, 30);
	addNode(head, 40);
	addNode(head, 50);
	display(head);


	insertFront(&head, 70);
	display(head);

	int numWantDelete = 70;
	Node* ptrDelete = searchNode(head, numWantDelete);
	if (deleteNode(&head, ptrDelete))
	{
		cout << "NODE " << numWantDelete << " deleted !\n";
	}
	display(head);

	cout << "This list is reversed.\n";
	reverse(&head);
	display(head);
	
	
	cout << "The list is copied \n";
	copyLinkedList(head, &newHead);
	display(newHead);
	
	
	cout << "Comparing the two lists... \n";
	cout << "Are the two lists same ? \n";
	if (compareLinkedList(head, newHead))
	{
		cout << "Yes, they are same ! \n";
	}
	else
	{
		cout << "No, they are different ! \n";
	}
	cout << endl;

	numWantDelete = 50;
	ptrDelete = searchNode(newHead, numWantDelete);
	if (deleteNode(&newHead, ptrDelete))
	{
		cout << "Node " << numWantDelete << " deleted! \n";
		cout << "New list after deleted... " << endl;
		display(newHead);
	}


	if (compareLinkedList(head, newHead))
	{
		cout << "Yes, thery are same \n";
	}
	else
	{
		cout << "No, they are different . \n";
	}

	cout << endl;
	deleteLinkedList(&newHead);
	display(newHead);
	
	return 0;
}