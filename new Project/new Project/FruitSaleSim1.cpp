#include<iostream>
using std::cout;
using std::endl;

class FruitSeller {
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult() const;
};

FruitSeller::FruitSeller(int price, int num, int money)
	:APPLE_PRICE(price), numOfApples(num), myMoney(money)
{
}
int FruitSeller::SaleApples(int money) {
	if (money < 0) {
		cout << "�߸��� ������ �ԷµǾ����ϴ�." << endl;
		return 0;
	}
	int num = money / APPLE_PRICE;
	numOfApples -= num;
	myMoney += money;
	return num;
}
void FruitSeller::ShowSalesResult() const{
	cout << "���� ���: " << numOfApples << endl;
	cout << "�Ǹ� ����: " << myMoney << endl << endl;
}

class FruitButer {
private:
	int myMoney;
	int numOfApples;

public:
	FruitButer(int money);
	bool BuyApples(FruitSeller &seller, int money);
	void ShowBuyResult() const;
};

FruitButer::FruitButer(int money)
	:myMoney(money), numOfApples(0)
{
}
bool FruitButer::BuyApples(FruitSeller &seller, int money) {
	if (money < 0) {
		cout << "�˸��� �ݾ��� �����ʽÿ�." << endl;
		return false;
	}
	numOfApples += seller.SaleApples(money);
	myMoney -= money;
	return true;
}
void FruitButer::ShowBuyResult() const{
	cout << "���� �ܾ�: " << myMoney << endl;
	cout << "��� ����: " << numOfApples << endl << endl;
}

int main() {
	FruitSeller seller(1000, 20, 0);
	FruitButer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
}