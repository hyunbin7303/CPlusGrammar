#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#define SIZE 2

struct Node
{
	int key[SIZE];
	struct Node* ptr[SIZE + 1];
	struct Node* parent;
	int capa;
};

typedef struct Node NODE;
typedef NODE *TREE;


//checking overflow 
bool chk_overflow(TREE node)
{
	if (node->capa >= SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// checking whether it is leaf node or not.
bool chk_leafnode(TREE root)
{
	for (int i = 0; i < SIZE + 1; i++)
	{
		if (root->ptr[i] != NULL)
		{
			return false;
		}

	}
	return true;
}


int find_index(TREE node)
{
	if (node->parent != NULL)
	{
		int i;
		for (i = 0; i < node->parent->capa + 1; i++)
		{
			if (node->parent->ptr[i] == node)
			{
				return i;
			}
		}
	}
	return -1;
}


int chk_bro(TREE node)
{
	if (node->parent == NULL)
	{
		return -1;
	}
	else
	{
		int tmp = find_index(node);
		//
		if (tmp - 1 >= 0)
		{
			if (node->parent->ptr[tmp - 1]->capa < SIZE)
			{
				return tmp - 1;
			}
		}
		else if (tmp + 1 < SIZE + 1)
		{
			if (node->parent->ptr[tmp + 1]->capa < SIZE)
			{
				return tmp + 1;
			}
		}
		return -1;
	}
}

void set_parent(TREE node)
{
	for (int i = 0; i < node->capa + 1; i++)
	{
		if (node->ptr[i] != NULL)
		{
			node->ptr[i]->parent = node;
		}
	}
}



TREE make_node(void)
{
	TREE tmp;
	tmp = (TREE)malloc(sizeof(NODE));
	tmp->capa = 0;
	tmp->parent = NULL;
	for (int i = 0; i < SIZE + 1; i++)
	{
		tmp->ptr[i] = NULL;
	}
	return tmp;
}

void print_node(TREE node)
{
	int i;
	printf("{");
	for (i = 0; i < node->capa; i++)
	{
		printf("%x, (%d), ", node->ptr[i], node->key[i]);

	}
	printf("%x} capa:%d \n", node->ptr[i], node->capa);
}


void input_node(TREE node, int item, TREE left, TREE right)
{
	int i;
	for (i = node->capa; i > 0; i--)
	{
		if (item > node->key[i - 1])
		{
			node->key[i] = item;
			node->ptr[i] = left;
			node->ptr[i + 1] = right;
			node->capa += 1;
			return;
		}
		else
		{
			node->key[i] = node->key[i - 1];
			node->ptr[i + 1] = node->ptr[i];
		}
	}
	node->key[i] = item;
	node->ptr[i] = left;
	node->ptr[i + 1] = right;
	node->capa += 1;
	return;
}

TREE sep_node(TREE node)
{
	TREE tmp = NULL;
	if (node->capa >= 2)
	{
		int i, j = 0;
		int tmp_capa = node->capa;
		tmp = make_node();
		for (i = (node->capa) / 2; i < node->capa; i++, j++)
		{
			tmp->key[j] = node->key[i];
			tmp->ptr[j] = node->ptr[i];
			tmp_capa--;
			tmp->capa += 1;
		}
		tmp->ptr[j] = node->ptr[i];
		node->capa = tmp_capa;
	}
	return tmp;
}


void insert_redistribute(TREE node, int item, TREE left, TREE right)
{
	int bro_index = chk_bro(node);
	int node_index = find_index(node);
	TREE bro = node->parent->ptr[bro_index];
	
	if (bro_index < node_index)
	{
		if (item < node->key[0])
		{
			input_node(bro, node->parent->key[node_index - 1],
				bro->ptr[bro->capa], left);
			node->parent->key[node_index - 1] = item;
			node->ptr[0] = right;
			set_parent(node);
			set_parent(bro);
		}
		else
		{
			int i;
			input_node(bro, node->parent->key[node_index - 1],
				bro->ptr[bro->capa], node->ptr[0]);
			node->parent->key[node_index - 1] = node->key[0];
			for (i = 0; i < node->capa - 1; i++)
			{
				node->key[i] = node->key[i + 1];
				node->ptr[i] = node->ptr[i + 1];

			}
			node->ptr[i] = node->ptr[i + 1];
			node->capa -= 1;
			input_node(node, item, left, right);
			set_parent(node);
			set_parent(bro);
			
		}
	}


	// bro node right??
	else
	{
		if (item > node->key[node->capa - 1])
		{
			input_node(bro, node->parent->key[node_index],
				right, bro->ptr[0]);
			node->parent->key[node_index] = item;
			node->ptr[node->capa] = left;
			set_parent(node);
			set_parent(bro);
		}
		else
		{
			input_node(bro, node->parent->key[node_index],
				node->ptr[node->capa], bro->ptr[0]);
			node->parent->key[node_index] = node->key[node->capa - 1];
			node->capa -= 1;
			input_node(node, item, left, right);
			set_parent(node);
			set_parent(bro);
		}
	}
}




TREE insert_item(TREE root, TREE node, int item, TREE left, TREE right)
{

	if (!chk_overflow(node))
	{
		input_node(node, item, left, right);
		return root;
	}
	else if (chk_bro(node) != -1)
	{
		insert_redistribute(node, item, left, right);
		return root;
	}
	else
	{
		int middle;
		// making brother node 
		TREE bro = sep_node(node);

		if (item < node->key[node->capa - 1])
		{
			middle = node->key[node->capa - 1];
			node->capa -= 1;
			input_node(node, item, left, right);
		}
		else if (item > bro->key[0])
		{
			int i;
			middle = bro->key[0];
			for (i = 0; i < bro->capa - 1; i++)
			{
				bro->key[i] = bro->key[i + 1];
				bro->ptr[i] = bro->ptr[i + 1];
			}
			bro->ptr[i] = bro->ptr[i + 1];
			bro->capa -= 1;
			input_node(bro, item, left, right);
		}
		else
		{

			middle = item;
			node->ptr[node->capa] = left;
			bro->ptr[0] = right;
		}


		set_parent(node);
		set_parent(bro);


		if (node->parent == NULL)
		{
			TREE paren = make_node();
			input_node(paren, middle, node, bro);
			set_parent(paren);
			return paren;
		}
		else
		{
			bro->parent = node->parent;
			return insert_item(root, node->parent, middle, node, bro);
		}
	}

}



TREE find_node(TREE root, int item)
{
	if (chk_leafnode(root))
	{
		return root;
	}
	else
	{
		int i;
		for (i = 0; i < root->capa; i++)
		{
			if (item < root->key[i])
			{
				return find_node(root->ptr[i], item);
			}

		}
		return find_node(root->ptr[i], item);
	}
}


void print_tree(TREE root, int level)
{
	if (root != NULL)
	{
		int i;
		for (i = 0; i < root->capa; i++)
		{
			print_tree(root->ptr[i], level + 1);
			for (int j = 0; j < level; j++)
			{
				printf("|  ");
			}
			printf("+[%d] \n", root->key[i]);
		}
		print_tree(root->ptr[i], level + 1);
	}
}


int main(void)
{
	TREE tmp = make_node();
	int arr[20] = { 14,7,9,13,1,8,18,19,2,5,3,11,20,4,6,10,12,16,15,17 };
	for (int i = 0; i < 20; i++)
	{
		printf("input : %d \n", i);
		tmp = insert_item(tmp, find_node(tmp, i), i, NULL, NULL);
		print_tree(tmp, 0);
		Sleep(150);
		system("cls");

	}
	print_tree(tmp, 0);
	return 0;
}