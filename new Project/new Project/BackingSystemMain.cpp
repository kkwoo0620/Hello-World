#include"BankingCommonDec1.h"
#include"AccountHandler.h"

int main() {

	AccountHandler T;
	int choose_menu = 0;

	while (1) {
		T.ShowMenu();
		cout << "¼±ÅÃ: ";
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
