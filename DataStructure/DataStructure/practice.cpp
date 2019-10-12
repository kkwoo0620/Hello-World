#include<iostream>
using namespace std;

int Factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int BSearchRecur(int ar[], int first, int last, int target)
{
	if (first > last)
		return -1;

	int mid = (first + last) / 2;

	if (ar[mid] == target)
		return mid;
	else
	{
		if (ar[mid] < target)
			return BSearchRecur(ar, mid + 1, last, target);
		else
			return BSearchRecur(ar, first, mid - 1, target);
	}
}

void HanoiTower(int num, char from, char by, char to)
{
	if (num == 1)
		cout << "원반 1을 " << from << "에서 " << to << "로 이동" << endl;
	else
	{
		HanoiTower(num - 1, from, to, by);
		cout << "원반 " << num << "을 " << from << "에서 " << to << "로 이동" << endl;
		HanoiTower(num - 1, by, from, to);
	}
}

int main()
{
	int result = Fibonacci(10);
	cout << result << endl;
	cout << Factorial(5)<<endl;
	HanoiTower(3, 'a', 'b', 'c');
}