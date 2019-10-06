#include<iostream>
using std::cout;
using std::endl;

template <class T1>
T1 SumArray(T1 arr[], int len)
{
	T1 sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	cout << SumArray(arr, 5) << endl;
	double arrd[5] = { 1.1, 2.2, 3.3, 4.4,5.5 };
	cout << SumArray(arrd, 5) << endl;

}