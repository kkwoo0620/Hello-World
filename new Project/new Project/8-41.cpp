#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	vector<int>::iterator end_iter;
	end_iter = remove(v.begin(), v.end(), 30);

	for (vector<int>::iterator iter = v.begin(); iter != end_iter; iter++)
		cout << *iter << ", ";

	v.erase(end_iter, v.end());

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << ", ";


	return 0;
}