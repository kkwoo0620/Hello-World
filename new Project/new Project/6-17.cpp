#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	vector<int> v2;

	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);



	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{	
		cout << *iter << endl;
	}

	vector<int>::iterator iter = v.begin();
	v.insert(iter, v2.begin(), v2.end());

	vector<int>::iterator testiter = v.begin();
	cout << *testiter++ << endl;
	cout << *testiter++ << endl;
	cout << *testiter++ << endl;
	cout << *testiter++ << endl;

	testiter += 2;

	cout << *testiter << endl;

	vector<int>::const_iterator constiter = v.begin();
	// *constiter = 10;  const반복자이기때문에 불가.

	for (vector<int>::reverse_iterator riter = v.rbegin(); riter != v.rend(); riter++)
	{
		cout << *riter << endl;
	}

	return 0;
}