#include<iostream>
using std::cout;
using std::endl;


template <class T>
T SumArray(T arr[], int len)
{
	T sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	double A[] = { 1.1, 2.2, 3.3 };
	cout << SumArray<double>(A, 3) << endl;

	int B[] = { 5,6,7 };
	cout << SumArray<int>(B, 3) << endl;
}