#include<iostream>
#include<algorithm>
using namespace std;

struct Function1 {
	void operator()(int n) {
		cout << n << endl;
	}
};

struct Function2 {
	void operator()(int n) {
		cout << n * n << endl;
	}
};

int main()
{
	int a[5] = { 10, 20, 30, 40, 50 };

	for_each(a, a + 5, Function1());

}