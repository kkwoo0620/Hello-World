#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include"String.h"

class Account {
private:
	int accID;
	int balance;
	String name;

public:
	Account(int accID, int balance, String name);
	int GetaccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};





#endif