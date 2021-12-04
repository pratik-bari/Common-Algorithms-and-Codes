#include <iostream>

using namespace std;

struct Node
{
	int val;
	struct Node* next;
};

void printList(struct Node ** node)
{
	struct Node * curr = *node;

	while(curr != NULL)
	{
		cout<<"Val--->"<<curr->val<<endl;
		curr = curr->next;
	}
}

void addStart(struct Node **node, int val)
{
	struct Node * newNode = new Node();
	newNode->val = val;

	newNode->next = (*node);

	(*node) = newNode;
}

int detectLoop(struct Node ** node)
{
	struct Node * sNode = *node;
	struct Node * fNode = *node;

	while(sNode && fNode && fNode->next)
	{
		sNode = sNode->next;
		fNode = fNode->next->next;

		if(sNode == fNode)
			return 1;
	}

	return 0;
}

int detectLoop2(struct Node ** node)
{
	Node * curr = *node;
	Node * temp = new Node();

	while(curr != NULL)
	{
		if(curr == temp)
			return 1;

		Node * nex = curr->next;
		curr->next = temp;
		curr = nex;
	}

	return 0;
}

int main()
{
	struct Node * head = NULL;

	addStart(&head, 40);
	addStart(&head, 30);
	addStart(&head, 20);
	addStart(&head, 10);

	//head->next->next->next = head->next;

	if(detectLoop2(&head))
		cout<<"Loop Detected"<<endl;

	else
		cout<<"Loop not Detected"<<endl;

	//printList(&head);

	return 0;
}
