#include<iostream>
using std::cout;
using std::endl;

void print(int n) {
	cout << n << endl;
}

namespace n {
	void print(int n) {
		cout << "���ӽ����̽�" << n << endl;
	}
}

class Print
{
public:
	static void print(int n)
	{
		cout << "Ŭ����" << n << endl;
	}
};

int main()
{
	void(*pf)(int);
	pf = print;
	pf(20);
	pf = n::print;
	pf(30);
	pf = Print::print;
	pf(40);
}