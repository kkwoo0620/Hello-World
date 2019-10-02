#include<iostream>

using std::cout;
using std::endl;

class SoSimple
{
private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2) {};
	explicit SoSimple(SoSimple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "called SoSimple(SoSimple &copy)" << endl;
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main() {
	SoSimple sim1(15, 30);
	cout << "초기화 직전" << endl;
	SoSimple sim2(sim1);           // SoSimple sim2 = sim1; // simp2(sim1)로 변환인데 explicit 키워드로 묵시적 변환 불가능.
	cout << "초기화 후" << endl;
	sim2.ShowSimpleData();

}