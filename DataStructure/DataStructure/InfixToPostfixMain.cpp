#include<iostream>
#include"InfixCalculator.h"
using namespace std;

int main()
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	
	cout << exp1 << " = " << EvalInfixExp(exp1) << endl;
	cout << "exp1 실행 후" << endl;
	cout << exp2 << " = " << EvalInfixExp(exp2) << endl;
	cout << "exp2 실행 후" << endl;
	cout << exp3 << " = " << EvalInfixExp(exp3) << endl;
	cout << "exp3 실행 후" << endl;


	return 0;
}