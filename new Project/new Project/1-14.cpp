#include<iostream>
using std::cout;
using std::endl;

struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "정수 : " << arg << endl;
	}
};

void Print1(int arg) {
	cout << "정수 : " << arg << endl;
}

int main()
{
	void(*print2)(int) = Print1;
	Print1(40);
	print2(4);
	FuncObject A;
	A(3);
}