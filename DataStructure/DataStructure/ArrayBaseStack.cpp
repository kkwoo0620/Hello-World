#include"ArrayBaseStack.h"
#include<cstdlib>
#include<iostream>
using namespace std;

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->topIndex == -1)
		return 1;
	else
		return 0;


}

void SPush(Stack * pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
	if (pstack->topIndex == -1)
	{
		cout << "memory error!" << endl;
		exit(1);
	}

	int temp;
	temp = pstack->stackArr[pstack->topIndex];
	pstack->topIndex -= 1;
	return temp;
}

Data SPeek(Stack * pstack)
{
	if (pstack->topIndex == -1)
	{
		cout << "memory error!" << endl;
		exit(1);
	}

	return pstack->stackArr[pstack->topIndex];
}