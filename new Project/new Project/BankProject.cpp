#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

static int CustomerCount = 0;

void MakeAccount();
void Deposit();
void Withdrawal();
void ShowAllAccount();

class Customer{
private:
	int accID;
	int balance;
	char * name;

public:
	Customer() :accID(0), balance(0), name(NULL) {};
	Customer(const Customer& copy) : accID(copy.accID), balance(copy.balance)
	{
		name = new char[(strlen(copy.name)) + 1];
		strcpy(name, copy.name);
	}
	Customer(int accID, int balance, char * name) : accID(accID), balance(balance)
	{
		this->name = new char[(strlen(name) + 1)];
		strcpy(this->name, name);
	}
	int GetaccID() { return accID; }
	int GetBalance() { return balance; }
	char *GetName() { return name; }
	

	void AddMoney(int money) {
		balance += money;
	}
	void MinMoney(int money) {
		balance -= money;
	}
	~Customer() {
		delete[]name;
	}
};

Customer *customer[100];

int main() {


	int choose_menu = 0;

	while (1) {
		cout << "-----Menu-----" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. ���¹�ȣ ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: "; cin >> choose_menu;
		cout << endl;

		switch (choose_menu) {
		case 1:
			MakeAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdrawal();
			break;
		case 4:
			ShowAllAccount();
			break;
		case 5:
			return 0;
		default:
			cout << "input another number please." << endl;
			break;
		}
	}
}

void MakeAccount() {
	int ID;
	char name[20];
	int money;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> ID;
	for (int i = 0; i < CustomerCount; i++)
	{
		if (customer[i]->GetaccID() == ID) {
			cout << "�̹� �ִ� ID �Դϴ�. " << endl;
			return;
		}
	}
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << endl;

	customer[CustomerCount] = new Customer(ID, money, name);
	CustomerCount++;
}

void Deposit() {
	int PutId;
	int PutMoney;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> PutId;

	for (int i = 0; i < CustomerCount; i++)
	{
		if (customer[i]->GetaccID() == PutId) {
			cout << "�Աݾ�: "; cin >> PutMoney;
			customer[i]->AddMoney(PutMoney);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "�ش� ID�� ���°� �����ϴ�." << endl;

}

void Withdrawal() {
	int PutId;
	int OutMoney;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> PutId;

	for (int i = 0; i < CustomerCount; i++)
	{
		if (customer[i]->GetaccID() == PutId) {
			cout << "���� �ܾ�: " << customer[i]->GetBalance() << endl;
			cout << "��ݾ�: "; cin >> OutMoney;
			customer[i]->MinMoney(OutMoney);
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "�ش� ID�� ���°� �����ϴ�." << endl;
}

void ShowAllAccount() {
	for (int i = 0; i < CustomerCount; i++)
	{
		cout << "����ID: " << customer[i]->GetaccID() << endl;
		cout << "�� ��: " << customer[i]->GetName() << endl;
		cout << "�� ��: " << customer[i]->GetBalance() << endl;
		cout << endl;
	}
}

