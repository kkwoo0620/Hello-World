#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool Pred(int n)
{
	return n > 200;
}

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	while (next_permutation(v.begin(), v.end()))
	{
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
			cout << *iter << ", ";
		cout << endl;
	}

	vector<int> v2;
	v2.push_back(100);
	v2.push_back(3100);
	v2.push_back(400);
	v2.push_back(200);
	v2.push_back(3200);

	vector<int>::iterator iter2;
	iter2 = partition(v2.begin(), v2.end(), Pred);

	for (vector<int>::iterator iter = v2.begin(); iter != iter2; iter++)
		cout << *iter << ", ";
	cout << endl;

	for (vector<int>::iterator iter = iter2; iter != v2.end(); iter++)
		cout << *iter << ", ";
	cout << endl;


	return 0;
}