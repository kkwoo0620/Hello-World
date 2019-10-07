#include<iostream>
using namespace std;

class Adder
{
public:
	Adder() {}
	const int operator()(int x, int y) const{
		return x + y;
	}
};

int main()
{
	Adder add;

	int sum = add(10, 20);
	cout << "sum = " << sum << endl;
}