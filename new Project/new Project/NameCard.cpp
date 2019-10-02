#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NameCard.h"
using std::cout;
using std::endl;
using namespace COMP_POS;

NameCard::NameCard(const char *name, const char *company, const char *phone, int pos)
	: position(pos)
{
	this->name = new char[strlen(name) + 1];
	this->company = new char[strlen(company) + 1];
	this->phone = new char[strlen(phone) + 1];
	strcpy(this->name, name);
	strcpy(this->company, company);
	strcpy(this->phone, phone);
}
NameCard::NameCard(const NameCard &copy) : position(copy.position)
{
	name = new char[strlen(copy.name + 1)];
	company = new char[strlen(copy.company + 1)];
	phone = new char[strlen(copy.phone + 1)];
	strcpy(name, copy.name);
	strcpy(company, copy.company);
	strcpy(phone, copy.phone);
}
void NameCard::ShowNameCardInfo() {
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << phone << endl;
	cout << "직급: ";
	switch (position) {
	case CLERK:
		cout << "사원" << endl;
		break;
	case SENIOR:
		cout << "주임" << endl;
		break;
	case ASSIST:
		cout << "대리" << endl;
		break;
	case MANAGER:
		cout << "과장" << endl;
		break;
	}
	cout << endl;
}
