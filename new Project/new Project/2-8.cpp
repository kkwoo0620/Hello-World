#include<iostream>
#include<algorithm>
using std::endl;
using std::cout;
using std::for_each;

/////////////서버////////////
//void For_each(int *begin, int *end, void(*pf)(int))
//{
//	while (begin != end)
//	{
//		pf(*begin++);
//	}
//}

/////////////클라이언트////////////
void print1(int n)
{
	cout << n << ' ';
}

void print2(int n)
{
	cout << n * n << " ";
}

void print3(int n)
{
	cout << "정수 : " << n << endl;
}

int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	
	for_each(arr, arr + 5, print1);
}


// void (*pr)(int);

// void (MyClass::*ptr)(int);

// pf(data);

// (obj.*pf)(data);