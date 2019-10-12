#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<cstdlib>
#include<iostream>
#include"InfixToPostfix.h"
#include"PostCalculator.h"
using namespace std;

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	cout << "eEval ½ÇÇàÁß" << endl;

	ConvToRPNExp(expcpy);
	ret = EvalRPNExp(expcpy);

	free(expcpy);
	return ret;
}