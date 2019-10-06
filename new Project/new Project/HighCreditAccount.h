#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include"NormalAccount.h"
#include"String.h"

class HighCreditAccount : public NormalAccount
{
private:
	double SpeicalInterest;
public:
	HighCreditAccount(int accID, int balance, String name, int PerInterest, int rank) : NormalAccount(accID, balance, name, PerInterest), SpeicalInterest(rank) {	}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money*(SpeicalInterest / 100));
	}
};

#endif