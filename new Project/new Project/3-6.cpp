#include<iostream>
#include<functional>
using namespace std;

int main()
{
	less<int> l;
	plus<int> a;
	cout << l(10, 20) << endl;
	cout << l(20, 10) << endl;
	cout << l.operator()(10, 20) << endl;
	cout << endl;
	cout << less<int>()(10, 20) << endl;
	cout << less<int>().operator()(10, 20) << endl;
	cout << greater<int>()(10, 20) << endl;
	cout << plus<int>()(10, 20) << endl;
	cout << a(30, 40) << endl;
	cout << minus<int>()(10, 20) << endl;
}
