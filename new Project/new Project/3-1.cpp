#include<iostream>
using std::cout;
using std::endl;

void Print()
{
	cout << "���� �Լ�!" << endl;
}

//struct Functor
//{
//	void operator()()
//	{
//		cout << "�Լ� ��ü!" << endl;
//	}
//};

struct Functor
{
	void operator()(int a, int b) {
		cout << a << b << endl;
	}
};

int main()
{
	Functor functor;
	Print();
	functor(1, 2);

	return 0;
}