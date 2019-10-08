#include<iostream>
using std::cout;
using std::endl;

class A
{
};

class B
{
public:
	B() { cout << "±âº»" << endl; }
	B(A& _a) { cout << "A&" << endl; }
	B(int n) { cout << "int" << endl; }
	B(double d) { cout << "double" << endl; }
};

int main()
{
	A a;
	int n = 10;
	double d = 5.5;
	B b;
	b = a; // b = B(a);
	b = n; // b = B(n);
	b = d; // b = B(d);

	return 0;
}