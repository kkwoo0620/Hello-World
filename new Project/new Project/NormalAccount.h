#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include"Account.h"

class NormalAccount : public Account
{
private:
	double PerInterest;
public:
	NormalAccount(int accID, int balance, char * name, double PerInterest) : Account(accID, balance, name), PerInterest(PerInterest) {}
	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money*(PerInterest / 100));
	}
};

#endif