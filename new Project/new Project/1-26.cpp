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
		cout << "A() ȣ��" << endl;
	}
	operator int()
	{
		cout << "int() ȣ��" << endl;
	}
	operator char()
	{
		cout << "char() ȣ��" << endl;
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