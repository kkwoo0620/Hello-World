#include<iostream>
using namespace std;

void Recursive(int num)
{
	if (num <= 0)
		return;
	cout << "Recursive call!" << endl;
	Recursive(num - 1);
}

int Factorial(int num)
{
	if (num == 0)
		return 1;
	else
		return num * Factorial(num - 1);
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

void HanoiTowerMove(int num, char from, char by, char to)	// from 에 꽂혀있는 num개의 원반을 by를 거쳐 to로 이동
{
	if (num == 1)
		cout << "원반 1을 " << from << "에서 " << to << "로 이동"<<endl;
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		cout << "원반 " << num << "을 " << from << "에서 " << to << "로 이동"<<endl;
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;
	
	mid = (first + last) / 2;
	if (ar[mid] == target)
		return mid;

	if (ar[mid] > target)
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);
}

int main()
{
	Recursive(10);
	int result = Fibonacci(10);
	cout << result << endl;

	HanoiTowerMove(3, 'a', 'b', 'c');
	return 0;
}