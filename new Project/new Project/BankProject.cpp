#define _CRT_SECURE_NO_WARNINGS
#define NAME_LAN 20
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account{
private:
	int accID;
	int balance;
	char * name;

public:
	Account(int accID, int balance, char * name) : accID(accID), balance(balance)
	{
		this->name = new char[(strlen(name) + 1)];
		strcpy(this->name, name);
	}
	Account(const Account& copy) : accID(copy.accID), balance(copy.balance)
	{
		name = new char[(strlen(copy.name)) + 1];
		strcpy(name, copy.name);
	}
	int GetaccID() const { return accID; }

	void Deposit(int money) {
		balance += money;
	}
	int Withdraw(int money) {
		if (balance < money)
			return 0;
		
		balance -= money;
		return money;
	}

	void ShowAccInfo() const
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << name << endl;
		cout << "잔  액: " << balance << endl;
	}

	~Account() {
		delete[]name;
	}
};

class AccountHandler {
private:
	Account *account[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu();
	void MakeAccount();
	void Deposit();
	void Withdrawal();
	void ShowAllAccount();
	~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0) {};
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
	{
		delete account[i];
	}
}
void AccountHandler::ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌번호 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount() {
	int ID;
	char name[20];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> ID;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	account[accNum++] = new Account(ID, balance, name);
}

void AccountHandler::Deposit() {
	int money;
	int ID;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> ID;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (account[i]->GetaccID() == ID)
		{
			account[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "해당 ID의 계좌가 없습니다." << endl;
}

void AccountHandler::Withdrawal() {
	int ID;
	int money;
	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> ID;
	cout << "출금액: "; cin >> money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (account[i]->GetaccID() == ID)
		{
			if (account[i]->Withdraw(money) == 0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "해당 ID의 계좌가 없습니다." << endl;
}

void AccountHandler::ShowAllAccount() {
	for (int i = 0; i < accNum; i++)
	{
		account[i]->ShowAccInfo();
		cout << endl;
	}
}

int main() {

	AccountHandler T;
	int choose_menu = 0;

	while (1) {
		T.ShowMenu();
		cout << "선택: ";
		cin >> choose_menu;
		cout << endl;

		switch (choose_menu) {
		case MAKE:
			T.MakeAccount();
			break;
		case DEPOSIT:
			T.Deposit();
			break;
		case WITHDRAW:
			T.Withdrawal();
			break;
		case INQUIRE:
			T.ShowAllAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "input another number please." << endl;
			break;
		}
	}
}
