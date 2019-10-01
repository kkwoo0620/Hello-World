#include<iostream>
using std::cout;
using std::endl;

class AAA {
public:
	AAA() {
		cout << "empty object" << endl;
	}
	void ShowYourName() {
		cout << "I'm class AAA" << endl;
	}
};

class BBB {
private:
	AAA &ref;
	const int &num;

public:
	BBB(AAA &r, const int &n) :ref(r), num(n)
	{
	}
	void ShowYourName() {
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
};

int main() {
	AAA obj;
	BBB obj2(obj, 3);
	obj2.ShowYourName();

}