#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include"Account.h"
#include"AccountArray.h"

class AccountHandler {
private:
	BoundCheckPointPtrArray accArr;
	int accNum;
public:
	AccountHandler();
	void ShowMenu();
	void MakeAccount();
	void MakeNormalAccount();
	void MakeCreditAccount();
	void Deposit();
	void Withdrawal();
	void ShowAllAccount();
	~AccountHandler();
};

#endif