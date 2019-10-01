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
void NameCard::ShowNameCardInfo() {
	cout << "�̸�: " << name << endl;
	cout << "ȸ��: " << company << endl;
	cout << "��ȭ��ȣ: " << phone << endl;
	cout << "����: ";
	switch (position) {
	case CLERK:
		cout << "���" << endl;
		break;
	case SENIOR:
		cout << "����" << endl;
		break;
	case ASSIST:
		cout << "�븮" << endl;
		break;
	case MANAGER:
		cout << "����" << endl;
		break;
	}
	cout << endl;
}
