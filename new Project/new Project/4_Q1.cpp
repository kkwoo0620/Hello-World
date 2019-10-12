#include <iostream>
using namespace std;

template <class T1, class T2>
void Copy(T1 t[], T1 s[], T2 n)
{
	for (int i = 0; i < n; i++)
	{
		t[i] = s[i];
	}
}

class MyType
{
private:
	int arr;
public:
	MyType(int x = 0) : arr(x) {}
};

int main()
{
	int arr1[5] = { 10, 20, 30, 40, 50 };
	int arr2[5];
	// Copy(t, s, n)
	Copy(arr2, arr1, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i];
	}

	MyType myarr1[5] = { 10, 20, 30, 40, 50 };
	MyType myarr2[5];
	Copy(myarr2, myarr1, 5);
}

