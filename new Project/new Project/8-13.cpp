#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Print(int n)
{
	cout << n << ", ";
}

class PrintFunctor
{
private:
	char fmt;
public:
	explicit PrintFunctor(char c = ' ') : fmt(c) { }
	void operator()(int n) const
	{
		cout << n << fmt;
	}
};

int main()
{
	vector<int> v;

	v.push_back(20);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int> v2;

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);

	for_each(v.begin(), v.begin() + 2, Print);
	cout << endl;
	for_each(v.begin(), v.begin() + 4, Print);
	cout << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
	cout << endl;

	for_each(v.begin(), v.end(), PrintFunctor());
	cout << endl;
	for_each(v.begin(), v.end(), PrintFunctor(','));
	cout << endl;
	for_each(v.begin(), v.end(), PrintFunctor('O'));
	cout << endl;

	cout << lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end());

	return 0;
}