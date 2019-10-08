#include<iostream>
using std::cout;
using std::endl;

class A
{

};

class B
{
public:
	operator A()
	{
		cout << "A() 호출" << endl;
	}
	operator int()
	{
		cout << "int() 호출" << endl;
	}
	operator char()
	{
		cout << "char() 호출" << endl;
		return 'c';
	}
};

int main()
{
	B b;
	char c;
	c = b;
	cout << c;
}