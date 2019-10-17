#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool Pred(int n)
{
	return n > 25;
}

bool PredLR(int left, int right)
{
	return left > right;
}

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int> v2;

	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(10);

	vector<int>::iterator iter;

	iter = find(v.begin(), v.end(), 20);
	if (iter != v.end())
		cout << "찾음! " << *iter << endl;

	iter = find_if(v.begin(), v.end(), Pred);	// 25이상인 첫번째 수

	cout << *iter << endl;

	iter = find_end(v.begin(), v.end(), v2.begin(), v2.end());
	if (iter != v.end())
		cout << "find end 값 : " << *iter << endl;

	iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
	cout << "find first of 값 : " << *iter << endl;

	iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), PredLR);
	cout << "find first of PredLR 값 : " << *iter << endl;


	return 0;
}