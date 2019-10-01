#include<iostream>
using std::cout;
using std::endl;

class AAA
{
private:
	int num;
public:
	AAA() : num(0) {};
	AAA& cReateInitobj(int n) const {
		AAA * ptr = new AAA(n);
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
private:
	AAA(int n) : num(n) {}
};

int main{

}