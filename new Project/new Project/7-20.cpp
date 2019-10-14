#include<iostream>
#include<map>
using namespace std;

int main()
{
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	multimap<int, int>::iterator iter;

	for (iter = mm.begin(); iter != mm.end(); iter++)
		cout << iter->first << ", " << iter->second << endl;

	cout << mm.count(3) << endl;
	iter = mm.find(3);
	cout << iter->second << endl;

	multimap<int, int>::iterator lower_iter;
	multimap<int, int>::iterator upper_iter;

	lower_iter = mm.lower_bound(3);
	upper_iter = mm.upper_bound(3);

	for (iter = lower_iter; iter != upper_iter; iter++)
		cout << iter->first << ", " << iter->second << endl;

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> pr;
	pr = mm.equal_range(3);

	for (iter = pr.first; iter != pr.second; iter++)
		cout << iter->first << ", " << iter->second << endl;


	return 0;
}