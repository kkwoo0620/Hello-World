#include<iostream>
#include<set>
using namespace std;

int main()
{
	multiset<int> ms;
	multiset<int>::iterator iter;

	ms.insert(10);
	ms.insert(10);
	ms.insert(50);
	ms.insert(20);
	ms.insert(10);
	iter = ms.insert(10);
	
	cout << *iter << endl;

	for (iter = ms.begin(); iter != ms.end(); iter++)
	{
		cout << *iter << ", ";
	}


	return 0;
}