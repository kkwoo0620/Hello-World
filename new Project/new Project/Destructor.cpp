#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

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
	Person man1("hihodu", 30);
	Person man2("hohohodu", 20);
	man1.ShowPersonInfo

}