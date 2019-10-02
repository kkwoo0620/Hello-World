#include<iostream>
using std::cout;
using std::endl;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n) {}
	SoSimple(const SoSimple &copy) : num(copy.num) {
		cout << "Called SoSimple(const SoSimple &copy" << endl;
	}
	void ShowData() {
		cout << "num " << num << endl;
	}
};

void SimpleFuncobj(SoSimple ob) {
	ob.ShowData();
}

int main() {
	SoSimple obj(7);
	cout << "함수호출 전" << endl;
	SimpleFuncobj(obj);
	cout << "함수호출 후" << endl;
	return 0;
}