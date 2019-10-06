#include"BankingCommonDec1.h"
#include"Account.h"

Account::Account(int accID, int balance, String name) : accID(accID), balance(balance)
{
	this->name = name;
}
int Account::GetaccID() const { return accID; }
void Account::Deposit(int money) {
	balance += money;
}
int Account::Withdraw(int money) {
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}
void Account::ShowAccInfo() const
{
	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << name << endl;
	cout << "��  ��: " << balance << endl;
}

Account::~Account() {
	delete name;
}