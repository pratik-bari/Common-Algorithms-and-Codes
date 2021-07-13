#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

void printList(struct Node ** start)
{
	struct Node * currNode = *start;

	while(currNode != NULL)							// Start with the first node and traverse till the end of the list. Print data if the current node is not NULL
	{
		printf("Data--->%d\n", currNode->data);
		currNode = currNode->next;
	}
}

void addElementLast(int data, struct Node ** start)
{
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));	// Malloc the newNode and initialize it with the data
	newNode->data = data;
	newNode->next = NULL;							// As the element is added at last the next node of the new node is always NULL

	struct Node * currNode = *start;

	if(currNode != NULL)							// Start with the first node and traverse till the end of the list. Place the newNode at the end of the list.
	{
		while(currNode->next != NULL)
			currNode = currNode->next;

		currNode->next = newNode;	
	}

	else									// If the list is empty, place the new node at the start.
		*start = newNode;
}

void addElementFirst(int data, struct Node ** start)
{
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));	// Malloc the newNode and initialize it with the data
	newNode->data = data;

	if(*start == NULL)							// If list is empty, place the newNode at the start and give the next pointer of the newNode as NULL
		newNode->next = NULL;

	else									// If the list is not empty, the newNode is the new start and next pointer of the newNode points to the previous start 
		newNode->next = *start;

	*start = newNode;
}

int deleteNodeByIndex(int pos, struct Node ** start)			// Delete Node as specified by the index. If list size is less than index delete the last node
{
	int retVal;
	struct Node * currNode = *start;
	struct Node * prevNode = NULL;
	int posId = 0;

	if(currNode == NULL)
		return -1;

	if(pos == 0)							
	{
		retVal = currNode->data;
		*start = currNode->next;
		free(currNode);
		return retVal;
	}

	while(currNode != NULL && posId <= (pos - 1))
	{
		prevNode = currNode;
		currNode = currNode->next;
		posId++;
	}

	if(currNode != NULL)
	{
		retVal = currNode->data;
		prevNode->next = currNode->next;
		free(currNode);
	}

	else
		retVal = -1;

	return retVal;
}

void addElementByIndex(int data, int pos, struct Node ** start)		// Adds element at the index specified. If the list size is less than the index, add the node at the end of the list
{
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;

	struct Node * currNode = *start;
	int posId = 0;

	if(currNode != NULL && pos != 0)
	{
		while(currNode->next != NULL && posId < (pos - 1))
		{
			currNode = currNode->next;
			posId++;
		}

		newNode->next = currNode->next;
		currNode->next = newNode;
	}

	else
	{
		newNode->next = *start;
		*start = newNode;
	}
}

void reverseList(struct Node ** start)
{
	struct Node * curr = *start;			//Initialize three pointers pointing to previous node, current node and the next node  
	struct Node * prev = NULL;
	struct Node * next = NULL;

	curr = * start;

	while(curr != NULL)				// Traverse the whole list.
	{
		next = curr->next;			// Store the next node 
		curr->next = prev;			// The previous node is the new next node to the current node
		prev = curr;				// Store the current node as the previous node
		curr = next;				// Go to the next node stored earlier and repeat the steps for all the nodes
	}

	*start = prev;					// The prev node after the traversal is the new start node
}

int main()
{
	struct Node * start = NULL;

//	addElementLast(200, &start);
	addElementFirst(100, &start);
	addElementFirst(50, &start);
	addElementFirst(40, &start);
	addElementFirst(30, &start);

	addElementLast(500, &start);
	addElementLast(700, &start);

	addElementByIndex(1000, 14, &start);
	addElementByIndex(2, 4, &start);
	printList(&start);

	printf("Deleted Node with Value --->%d\n", deleteNodeByIndex(0, &start));

	reverseList(&start);

	printf("\n\nAfter Reversal:\n");
	printList(&start);

	return 0;
}
