#include<iostream>
using std::cout;
using std::endl;

class SoSimple {
private:
	int num1;
	mutable int num2;	// const 함수에 대해 예외를 둔다.
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{

	}

	void ShowSimpleDate() const
	{
		cout << num1 << ", " << num2 << endl;
	}
	void CopyToNum2() const
	{
		num2 = num1;
	}
};

int main()
{
	SoSimple sm(1, 2);
	sm.ShowSimpleDate();
	sm.CopyToNum2();
	sm.ShowSimpleDate();
	return 0;
}