#include"BankingCommonDec1.h"
#include"Account.h"

Account::Account(int accID, int balance, char * name) : accID(accID), balance(balance)
{
	this->name = new char[(strlen(name) + 1)];
	strcpy(this->name, name);
}
Account::Account(const Account& copy) : accID(copy.accID), balance(copy.balance)
{
	name = new char[(strlen(copy.name)) + 1];
	strcpy(name, copy.name);
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
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ  ¸§: " << name << endl;
	cout << "ÀÜ  ¾×: " << balance << endl;
}

Account::~Account() {
	delete[]name;
}