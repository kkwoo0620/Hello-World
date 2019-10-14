#include<iostream>
#include<map>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	map<int, int> m;

	m[0] = 10;
	m[1] = 20;
	m[100] = 20;

	m[1] = 111;

	map<int, int>::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->first << ',' << iter->second << endl;
	}

	map<int, string, greater<int>> ma;

	ma[0] = "zero";
	ma[6] = "six";
	ma[2] = "two";
	ma[10] = "ten";

	map<int, string, greater<int>>::iterator iter2;

	for (iter2 = ma.begin(); iter2 != ma.end(); iter2++)
	{
		cout << iter2->first << ", " << iter2->second << endl;
	}

	return 0;
}