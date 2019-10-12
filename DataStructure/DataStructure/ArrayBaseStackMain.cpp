#include<iostream>
#include"ArrayBaseStack.h"
using namespace std;

int main()
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SIsEmpty(&stack))
		cout << SPop(&stack) << endl;

	return 0;
}