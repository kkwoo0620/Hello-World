#include<iostream>
#include<set>
using namespace std;

int main()
{
	multiset<int> ms;
	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80);
	ms.insert(30);
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); iter++)
	{
		cout << *iter << ", ";
	}
	cout << endl;

	cout << "¿ø¼Ò 30ÀÇ °¹¼ö " << ms.count(30) << endl;

	iter = ms.find(80);
	cout << *iter << endl;

	multiset<int>::iterator lower_iter;
	multiset<int>::iterator upper_iter;
	
	lower_iter = ms.lower_bound(30);
	upper_iter = ms.upper_bound(30);

	cout << "lower bound : " << *lower_iter << endl;
	cout << "upper bound : " << *upper_iter << endl;

	for (iter = lower_iter; iter != upper_iter; iter++)
	{
		cout << *iter << endl;
	}

	pair<multiset<int>::iterator, multiset<int>::iterator> ps;

	ps = ms.equal_range(80);

	for (iter = ps.first; iter != ps.second; iter++)
	{
		cout << *iter << ", ";
	}

	return 0;
}