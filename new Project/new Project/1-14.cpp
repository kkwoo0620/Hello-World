#include<iostream>
using std::cout;
using std::endl;

struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "���� : " << arg << endl;
	}
};

void Print1(int arg) {
	cout << "���� : " << arg << endl;
}

int main()
{
	void(*print2)(int) = Print1;
	Print1(40);
	print2(4);
	FuncObject A;
	A(3);
}