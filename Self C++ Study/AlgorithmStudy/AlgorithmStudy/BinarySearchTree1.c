#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};


struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->left = temp->right = NULL;
	temp->key = item;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);
	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	return node;
}

struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}


struct node* delete(struct node* node, int key)
{
	if (node == NULL) return node;
	if (key < node->key)
	{
		node->left = delete(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = delete(node->right, key);
	}
	else
	{
		if (node->left == NULL)
		{
			struct node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			struct node *temp = node->left;
			free(node);
			return temp;
		}

		struct node* temp = minValueNode(node->right);

		node->key = temp->key;
		node->right = delete(node->right, temp->key);
	}
	return node;
}


void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}



int main()
{
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 42);
	insert(root, 56);
	insert(root, 33);
	insert(root, 31);
	insert(root, 2);
	insert(root, 32);

	//delete(root, 2);
	//delete(root, 42);
	//delete(root, 32);

	inorder(root);
	return 0;
}