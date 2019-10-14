#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << ", ";
	}

	cout << endl;

	s.insert(50);

	for (iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << ", ";
	}

	pair<set<int>::iterator, bool> pr;

	pr = s.insert(100);

	if (pr.second)
	{
		cout << "성공!" << endl;
	}
	else
	{
		cout << "실패!" << endl;
	}

	pr = s.insert(100);

	if (pr.second)
	{
		cout << "성공!" << endl;
	}
	else
	{
		cout << "실패!" << endl;
	}

	s.insert(pr.first, 110);

	set<int, greater<int>> sG;

	sG.insert(50);
	sG.insert(10);
	sG.insert(90);
	sG.insert(110);
	sG.insert(20);
	sG.insert(70);

	set<int, greater<int>>::iterator iterG;

	for (iterG = sG.begin(); iterG != sG.end(); iterG++)
	{
		cout << *iterG << ", ";
	}


	return 0;
}