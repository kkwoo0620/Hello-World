#include"BankingCommonDec1.h"
#include"AccountHandler.h"
#include"Account.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"


AccountHandler::AccountHandler() : accNum(0) {};
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}
void AccountHandler::ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. ���¹�ȣ ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount() {
	int ID;
	int ChooseAccount;
	int balance;
	int InterestRate;
	int Rank;

	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> ChooseAccount;

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

	cout << "����ID: "; cin >> ID;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> InterestRate;
	cout << endl;
	accArr[accNum++] = new NormalAccount(ID, balance, name, InterestRate);
}

void AccountHandler::MakeCreditAccount() {
	int ID;
	int ChooseAccount;
	char name[NAME_LEN];
	int balance;
	int InterestRate;
	int Rank;

	cout << "����ID: "; cin >> ID;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> InterestRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> Rank;
	switch (Rank)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(ID, balance, name, InterestRate, RANK_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(ID, balance, name, InterestRate, RANK_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(ID, balance, name, InterestRate, RANK_C);
	}

	cout << endl;
	
}

void AccountHandler::Deposit() {
	int money;
	int ID;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetaccID() == ID)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "�ش� ID�� ���°� �����ϴ�." << endl;
}

void AccountHandler::Withdrawal() {
	int ID;
	int money;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetaccID() == ID)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "�ش� ID�� ���°� �����ϴ�." << endl;
}

void AccountHandler::ShowAllAccount() {
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}
