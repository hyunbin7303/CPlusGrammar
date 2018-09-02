//https://kukuruku.co/post/avl-trees/

#include <stdio.h>

struct node
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};


unsigned char height(node* p)
{
	return p ? p->height : 0;
}

int bfactor(node* p)
{
	return height(p->right) - height(p->left);
}


// This function retrieves the correct value of height field of the given node
// (provided that this field value in the left andf the right child nodes are correct)
void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}


node* rotateright(node *p)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q)
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p)
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
		{
			p->right = rotateright(p->right);
		}
		return rotateleft(p);
	}
	if (bfactor(p) == 2)
	{
		if (bfactor(p->left) > 0)
		{
			p->left = rotateleft(p->left);
		}
		return rotateright(p);
	}
	return p;
}




// k key insertion in the tree with p root 
/*
To check the correspondence of the implemented insertion algorithm
to theoretical estimates for AVL trees height,
a simple calc

*/
node* insert(node* p, int k)
{
	if (!p)
	{
		return new node(k);
	}

	if (k < p->key)
	{
		p->left = insert(p->left, k);
	}
	else
	{
		p->right = insert(p->right, k);
	}
	return balance(p);
}


// find a node with minimal key in a p tree. 
node* findmin(node* p)
{
	return p->left ? findmin(p->left) : p;
}

// detecting a node with minimal key from a p tree
node* removemin(node* p)
{
	if (p->left == 0)
	{
		return p->right;
	}
	p->left = removemin(p->left);
	return balance(p);
}


// deleting k key from p tree
/*
node* remove(node* p, int k)
{
	if (!p) return 0;
	if (k < p->key)
	{
		p->left = remove(p->left, k);
	}
	else if (k > p->key)
	{
		p->right = remove(p->right, k);
	}
	else
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin;

	}
}*/


int main()
{
	struct node *root = NULL;
	root = insert(root, 20);
	root = insert(root, 17);
	root = insert(root, 12);



	return 0;
}