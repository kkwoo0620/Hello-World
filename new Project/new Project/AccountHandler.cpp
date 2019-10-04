#include"BankingCommonDec1.h"
#include"AccountHandler.h"
#include"Account.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"


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
	int ChooseAccount;
	char name[20];
	int balance;
	int InterestRate;
	int Rank;

	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: "; cin >> ChooseAccount;

	if (ChooseAccount == Normal) {
		MakeNormalAccount();
	}
	else if (ChooseAccount == HighCredit) {
		MakeCreditAccount();
	}
	else {
		cout << "wrong number!" << endl;
	}
}

void AccountHandler::MakeNormalAccount() {
	int ID;
	int ChooseAccount;
	char name[NAME_LEN];
	int balance;
	int InterestRate;

	cout << "계좌ID: "; cin >> ID;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> InterestRate;
	cout << endl;
	account[accNum++] = new NormalAccount(ID, balance, name, InterestRate);
}

void AccountHandler::MakeCreditAccount() {
	int ID;
	int ChooseAccount;
	char name[NAME_LEN];
	int balance;
	int InterestRate;
	int Rank;

	cout << "계좌ID: "; cin >> ID;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> InterestRate;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> Rank;
	switch (Rank)
	{
	case 1:
		account[accNum++] = new HighCreditAccount(ID, balance, name, InterestRate, RANK_A);
		break;
	case 2:
		account[accNum++] = new HighCreditAccount(ID, balance, name, InterestRate, RANK_B);
		break;
	case 3:
		account[accNum++] = new HighCreditAccount(ID, balance, name, InterestRate, RANK_C);
	}

	cout << endl;
	
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
