
// bit bug...

#include<iostream>
#include<conio.h>
#define MAX 5

class node;
typedef struct pair
{
	int key;
	node *next;
}pair;
class node
{
public:
	node *father;
	int noofkeys;
	pair data[MAX];
	node *first;
	node();
	void insert_in_node(pair x);
	pair splitnode(pair x);
	int leaf_node();
	node *nextindex(int x);
	void display();
};
void node::display()
{
	int i;
	std::cout << "(";
	for (i = 0; i<noofkeys; i++)
		std::cout << data[i].key << " ";
	std::cout << ")";
}
node* node::nextindex(int x)
{
	int i = 0;
	if (x<data[0].key)
		return first;
	for (i=0; i<noofkeys; i++)
	{
		if (x <= data[i].key)
			return (data[i - 1].next);
	}
	return (data[i - 1].next);
}
int node::leaf_node()
{
	if (data[0].next == NULL)
		return 1;
	return 0;
}
void node::insert_in_node(pair mypair)
{
	int i;
	for (i = noofkeys - 1; i >= 0 && data[i].key>mypair.key; i--)
		data[i + 1] = data[i];
	data[i + 1] = mypair;
	noofkeys++;
}
pair node::splitnode(pair x)
{
	node *T;
	pair mypair;
	int i, j, centre;
	centre = (noofkeys - 1) / 2;
	T = new node;
	if (x.key>data[centre].key) //Divide the node in two parts(original and T)
	{
		for (i = centre + 1, j = 0; i <= noofkeys; i++, j++)
			T->data[j] = data[i];
		T->noofkeys = noofkeys - centre - 1;
		noofkeys = noofkeys - T->noofkeys;
		T->insert_in_node(x);
		T->first = T->data[0].next;
		T->father = father;
		mypair.key = T->data[0].key;
		mypair.next = T;
		//Delete the first key from node T
		for (i = 1; i<T->noofkeys; i++)
			T->data[i - 1] = T->data[i];
		T->noofkeys;
	}
	else
	{
		for (i = centre, j = 0; i<noofkeys; i++, j++)
			T->data[j] = data[i];
		T->noofkeys = noofkeys - centre;
		noofkeys = noofkeys - T->noofkeys;
		insert_in_node(x);
		T->father = father;
		mypair.key = T->data[0].key;
		mypair.next = T;
		//Delete the first key from node T
		for (i = 1; i<T->noofkeys; i++)
			T->data[i - 1] = T->data[i];
		T->noofkeys;
	}
	return(mypair);
}
node::node()
{
	for (int i = 0; i <= MAX; i++)
		data[i].next = NULL;
	noofkeys = 0;
	father = NULL;
	first = NULL;
}

class btree
{
	int mkeys;
	node *root;
public:
	btree(int n)
	{
		mkeys = n;
		root = NULL;
	}
	void insert(int x);
	void displaytree();
};



void btree::insert(int x)
{
	int index;
	pair mypair;
	node *p, *q;
	mypair.key = x;
	mypair.next = NULL;
	if (root == NULL)
	{
		root = new node;
		root->insert_in_node(mypair);
	}
	else
	{
		p = root;
		while (!(p->leaf_node()))
			p = p->nextindex(x);
		if (p->noofkeys < mkeys - 1)
			p->insert_in_node(mypair);

		else
		{
			mypair = p->splitnode(mypair);
			while (1)
			{
				if (p == root)
				{
					q = new node;
					q->data[0] = mypair;
					q->first = root;
					q->father = NULL;
					q->noofkeys = 1;
					root = q;
					q->first->father = q;
					q->data[0].next->father = q;
					return;

				}
				else
				{
					p = p->father;
					if (p->noofkeys < mkeys)
					{
						p->insert_in_node(mypair);
						return;
					}
					else
						mypair = p->splitnode(mypair);
				}

			}
		}

	}
}

class Q
{
	node *data[60];
	int R, F;
public:
	Q()
	{
		R = F = 0;
	}
	int empty()
	{
		if (R == F)
			return 1;
		else
			return 0;
	}
	node *deque()
	{
		return data[F++];
	}
	void enque(node *x)
	{
		data[R++] = x;
	}
	void makeempty()
	{
		R = F = 0;
	}
};
void btree::displaytree()
{
	Q q1, q2;
	node *p;
	q1.enque(root);
	while (!q1.empty())
	{
		q2.makeempty();
		std::cout << "\n";
		while (!q1.empty())
		{
			p = q1.deque();
			p->display(); std::cout << " ";
			if (!p->leaf_node())
			{
				q2.enque(p->first);
				for (int i = 0; i<p->noofkeys; i++)
					q2.enque(p->data[i].next);

			}
		}
		q1 = q2;
	}
}

void main()
{
	int n, i, x, op;
	node *p;
	std::cout << "\nmaximum number of keys in a node ? : ";
	std::cin >> n;
	btree b(n);
	do
	{
		std::cout << "\n\n1)Insert\n2)Print\n3)Quit";
		std::cout << "\nEnter your choice : ";
		std::cin >> op;
		switch (op)
		{
		case 1: std::cout << "\nEnter a data : ";
			std::cin >> x;
			b.insert(x);
			break;

		case 2:
			b.displaytree();
			break;
		}
	} while (op != 3);
}