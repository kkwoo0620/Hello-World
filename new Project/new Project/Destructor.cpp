#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
using std::cin;

class Person {
private:
	char * name;
	int age;
public:
	Person(const char * myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person &ps) : age(ps.age){
		name = new char[strlen(ps.name) + 1];
		strcpy(name, ps.name);
	}

	Person() {
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char * myname, int myage)
	{
		name = myname;
	}

	void ShowPersonInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person() {
		delete[]name;
		cout << "오우" << endl;
	}
};

int main() {
	Person man1("Lee dong Woo", 29);
	Person man2(man1);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

}