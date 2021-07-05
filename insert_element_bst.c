#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;

	struct Node * left;
	struct Node * right;
};

void printInOrder(struct Node * node)			// Inorder Traversal of the Binary Tree
{
	if(node == NULL)
		return;

	printInOrder(node->left);

	printf("Data-->%d\n", node->data);

	printInOrder(node->right);
}

void printPreOrder(struct Node * node)			// Preorder Traversal of the Binary Tree
{
	if(node == NULL)
		return;

	printf("Data-->%d\n", node->data);

	printPreOrder(node->left);

	printPreOrder(node->right);
}

struct Node * add_element(int data, struct Node * node)
{
	struct Node * newNode = (struct Node * )malloc(sizeof(struct Node));		// Create and Initialize the new node
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	struct Node * prevNode = NULL;

	while(node != NULL)						// Traverse until an empty leaf node is not found
	{
		prevNode = node;

		if(data < node->data)					// If data is less than root data check the left leaf
			node = node->left;

		else							// Else check the right leaf
			node = node->right;
	}

	if(prevNode == NULL)
		prevNode = newNode;					// Put the new node as the root

	else if(data < prevNode->data)
		prevNode->left = newNode;				// Put new node as the left leaf

	else
		prevNode->right = newNode;				// Put new node as the right leaf

	return newNode;
}

int main()
{
	struct Node * root = add_element(50, NULL);

	add_element(40, root);
	add_element(20, root);
	add_element(30, root);
	add_element(60, root);

	printf("\nIn order:\n");
	printInOrder(root);

	printf("\nPre order:\n");
	printPreOrder(root);

	return 0;
}
