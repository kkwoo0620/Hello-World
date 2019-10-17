#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	reverse(v.begin(), v.end());

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << ", ";
	cout << endl;


	srand((unsigned int)time(0));

	random_shuffle(v.begin(), v.end());
	
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << ", ";
	cout << endl;

	return 0;
}