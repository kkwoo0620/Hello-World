#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(const char * name, int myage) : age(myage)
	{
		strcpy(this->name, name);
	}
	void WhatYourName() const {
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const {
		cout << "I'm " << age << endl;
	}
};

class UnivStudent : public Person
{
private:
	char major[50];
public:
	UnivStudent(const char * name, int myage, const char * major) : Person(name, myage)
	{
		strcpy(this->major, major);
	}
	void WhoAreYou() const {
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl;
	}
};

int main() {
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
	return 0;
}