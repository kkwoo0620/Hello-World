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
	cout << "�Լ�ȣ�� ��" << endl;
	SimpleFuncobj(obj);
	cout << "�Լ�ȣ�� ��" << endl;
	return 0;
}