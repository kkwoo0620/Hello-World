#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v(3, 10);

	v.reserve(10);

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << v.size() << endl;
	cout << v.max_size() << endl;
	cout << v.capacity() << endl;
	
	v.resize(20, 100);
	cout << "resize(20, 10)" << endl;
	

	v.front() = 30000;
	v.assign(10, 200);
	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	
	
	cout << v.size() << endl;
	cout << v.max_size() << endl;
	cout << v.capacity() << endl;

	cout << v.empty() << endl;

	cout << v.front() << ", " << v.back() << endl;

	v.clear();

	if (v.empty())
	{
		cout << "v가 비었습니다." << endl;
	}

	cout << v.capacity() << endl;
	vector<int>().swap(v);
	cout << v.capacity() << endl;

	

	return 0;
}