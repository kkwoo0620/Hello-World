#include<iostream>
using namespace std;

class Equal {
public:
	Equal() {}
	const bool operator()(int x, int y) const{
		return x == y ? true : false;
	}
};

int main()
{
	Equal cmp;
	if (cmp(20, 20))
		cout << "같다" << endl;
	else
		cout << "다르다" << endl;
}