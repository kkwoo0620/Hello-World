#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(10);
	
	vector<int>::iterator iter;
	iter = copy(v1.begin(), v1.end(), v2.begin());

	for (iter = v2.begin(); iter != v2.end(); iter++)
		cout << *iter << ", ";

	cout << endl;

	iter = copy_backward(v1.begin(), v1.end(), v2.end());

	for (iter = v2.begin(); iter != v2.end(); iter++)
		cout << *iter << ", ";

	cout << endl;

	fill(v1.begin(), v1.end(), 10);

	for (iter = v1.begin(); iter != v1.end(); iter++)
		cout << *iter << ", ";

	cout << endl;

	fill_n(v1.begin(), 3, 50);
	
	for (iter = v1.begin(); iter != v1.end(); iter++)
		cout << *iter << ", ";

	cout << endl;

	iter = remove(v1.begin(), v1.end(), 50);

	for (iter; iter != v1.end(); iter++)
		cout << *iter << ", ";

	cout << endl;



	return 0;
}