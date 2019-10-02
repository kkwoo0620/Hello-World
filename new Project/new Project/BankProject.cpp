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
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌번호 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: "; cin >> choose_menu;
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

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> ID;
	for (int i = 0; i < CustomerCount; i++)
	{
		if (customer[i]->GetaccID() == ID) {
			cout << "이미 있는 ID 입니다. " << endl;
			return;
		}
	}
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << endl;

	customer[CustomerCount] = new Customer(ID, money, name);
	CustomerCount++;
}

void Deposit() {
	int PutId;
	int PutMoney;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> PutId;

	for (int i = 0; i < CustomerCount; i++)
	{
		if (customer[i]->GetaccID() == PutId) {
			cout << "입금액: "; cin >> PutMoney;
			customer[i]->AddMoney(PutMoney);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "해당 ID의 계좌가 없습니다." << endl;

}

void Withdrawal() {
	int PutId;
	int OutMoney;
	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> PutId;

	for (int i = 0; i < CustomerCount; i++)
	{
		if (customer[i]->GetaccID() == PutId) {
			cout << "현재 잔액: " << customer[i]->GetBalance() << endl;
			cout << "출금액: "; cin >> OutMoney;
			customer[i]->MinMoney(OutMoney);
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "해당 ID의 계좌가 없습니다." << endl;
}

void ShowAllAccount() {
	for (int i = 0; i < CustomerCount; i++)
	{
		cout << "계좌ID: " << customer[i]->GetaccID() << endl;
		cout << "이 름: " << customer[i]->GetName() << endl;
		cout << "잔 액: " << customer[i]->GetBalance() << endl;
		cout << endl;
	}
}

