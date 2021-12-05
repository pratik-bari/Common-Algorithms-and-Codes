#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;

	struct Node * left;
	struct Node * right;

};

struct Node * addNewNode(int val)
{
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));

	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

// Left - Right - Root
void printPostOrder(struct Node * node)
{
	if(node == NULL)
		return;

	printPostOrder(node->left);

	printPostOrder(node->right);
	
	printf("Data->%d\n", node->data);
}

// Root - Left - Right
void printPreOrder(struct Node * node)
{
	if(node == NULL)
		return;

	printf("Data->%d\n", node->data);
	
	printPreOrder(node->left);

	printPreOrder(node->right);
}

// Left - Root - Right
void printInOrder(struct Node * node)
{
	if(node == NULL)
		return;

	printInOrder(node->left);

	printf("Data->%d\n", node->data);

	printInOrder(node->right);
}



int main()
{
	struct Node * root = addNewNode(1);
	root->left = addNewNode(2);
	root->right = addNewNode(3);

	root->left->left = addNewNode(4);
	root->left->right = addNewNode(5);

	printf("In Order Traversal : \n");
	printInOrder(root);
	printf("\nPre Order Traversal : \n");
	printPreOrder(root);
	printf("\nPost Order Traversal : \n");
	printPostOrder(root);

	return 0;
}
