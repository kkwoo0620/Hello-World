#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> s_less;
	set<int, greater<int>> s_greater;

	s_less.insert(50);
	s_less.insert(80);
	s_less.insert(40);

	s_greater.insert(50);
	s_greater.insert(80);
	s_greater.insert(40);

	set<int>::key_compare l_cmp = s_less.key_comp();
	cout << l_cmp(10, 20) << endl;

	set<int, greater<int>>::key_compare g_cmp = s_greater.key_comp();
	cout << g_cmp(10, 20) << endl;

	cout << s_less.count(50);

	set<int>::iterator iter;
	set<int>::iterator iter2;

	pair<set<int>::iterator, set<int>::iterator> twoPair;

	iter = s_less.find(50);

	if (iter != s_less.end())
		cout << *iter << "를 찾음" << endl;
	else
		cout << "없음" << endl;

	iter = s_less.lower_bound(50);
	iter2 = s_less.upper_bound(50);

	twoPair = s_less.equal_range(50);
	cout << *twoPair.first << *twoPair.second << endl;

	cout << *iter << endl;
	cout << *iter2 << endl;

	
	return 0;
}