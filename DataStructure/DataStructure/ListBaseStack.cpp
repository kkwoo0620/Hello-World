#include"ListBaseStack.h"
#include<iostream>
using namespace std;

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->head == NULL)
		return true;
	else
		return false;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		cout << "memory error!" << endl;
		exit(1);
	}
	
	
	Data temp;
	Node * rnode;
	temp = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
	return temp;
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		cout << "memory error!" << endl;
		exit(1);
	}

	return pstack->head->data;
}