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
	Person() {
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char * myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const {
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person() {
		delete[]name;
		cout << "����" << endl;
	}
};

int main() {
	Person * parr[3];
	char namestr[100];
	char * strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�: ";
		cin >> namestr;
		cout << "����: ";
		cin >> age;
		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();


}