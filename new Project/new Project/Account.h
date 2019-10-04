#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int accID;
	int balance;
	char * name;

public:
	Account(int accID, int balance, char * name);
	Account(const Account& copy);
	int GetaccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};





#endif