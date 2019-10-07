#include<iostream>
using std::cout;
using std::endl;

void print(int n) {
	cout << n << endl;
}

namespace n {
	void print(int n) {
		cout << "네임스페이스" << n << endl;
	}
}

class Print
{
public:
	static void print(int n)
	{
		cout << "클래스" << n << endl;
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