#include<iostream>
#include<algorithm>
using std::endl;
using std::cout;
using std::for_each;

/////////////����////////////
//void For_each(int *begin, int *end, void(*pf)(int))
//{
//	while (begin != end)
//	{
//		pf(*begin++);
//	}
//}

/////////////Ŭ���̾�Ʈ////////////
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
	cout << "���� : " << n << endl;
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