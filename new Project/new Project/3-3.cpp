#include <iostream>
using std::cout;
using std::endl;

class Adder
{
private:
	int total;
public:
	explicit Adder(int n = 0) : total(n) {}
	int operator()(int n)
	{
		return total += n;
	}
};

int main()
{
	Adder add(0);
	add(10);
	add(20);
	cout << add(30) << endl;
}