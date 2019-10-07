#include<iostream>
using std::cout;
using std::endl;

void Print()
{
	cout << "전역 함수!" << endl;
}

//struct Functor
//{
//	void operator()()
//	{
//		cout << "함수 객체!" << endl;
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