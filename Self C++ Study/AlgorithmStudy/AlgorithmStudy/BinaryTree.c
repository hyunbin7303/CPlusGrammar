// BinaryTree preOrder, inOrder, and postOrder using C.


// Time Complexity : O(n)
//Complexity Function T(n) -> for all problem where tree traversal is involved.
// T(n) = T(k) + T(n-k-1) + c
// Where k is the number of nodes on one side of root
// and n-k-1 on the other side.

//Case 1: Skewed tree(One of the subtrees is empty and other subtree is not-empty)
// k=0,
// T(n) = T(0) + T(n-1) +c
// T(n) = 2T(0) + T(n-2) +2c
// T(n) = 2T(0) + T(n-3) +3c
// ........
// T(n) = (n-1)T(0) +T(1)+ (n-1)c

// Value of T(0) will be some constant say.


#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

//http://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// newNode Function 
// Return struct node pointer
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void print_PreOrder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%d ", node->data);
	print_PreOrder(node->left);
	print_PreOrder(node->right);
}

void print_InOrder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}
	
	print_InOrder(node->left);
	printf("%d ", node->data);
	print_InOrder(node->right);
}

void print_PostOrder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}
	print_PostOrder(node->left);
	print_PostOrder(node->right);
	printf("%d ", node->data);
}


int main()
{
	struct node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("\nPreOrder Traversal of Binary Tree is \n");
	print_PreOrder(root);

	printf("\nInOrder Traversal of Binary Tree is \n");
	print_InOrder(root);
	
	printf("\nInOrder Traversal of Binary Tree is \n");
	print_PostOrder(root);
	printf("\n");

	return 0;
}