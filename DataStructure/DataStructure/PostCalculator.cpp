#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<ctype.h>
#include<iostream>
#include"ListBaseStack.h"
using namespace std;

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			SPush(&stack, tok - '0');
		}
		else
		{
			op2 = SPop(&stack);
			cout << "Spop" << endl;
			op1 = SPop(&stack);

			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	cout << "last sPop" << endl;
	cout << stack.head->data << endl;
	return SPop(&stack);
}