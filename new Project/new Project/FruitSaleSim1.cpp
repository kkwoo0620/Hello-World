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
		cout << "잘못된 정보가 입력되었습니다." << endl;
		return 0;
	}
	int num = money / APPLE_PRICE;
	numOfApples -= num;
	myMoney += money;
	return num;
}
void FruitSeller::ShowSalesResult() const{
	cout << "남은 사과: " << numOfApples << endl;
	cout << "판매 수익: " << myMoney << endl << endl;
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
		cout << "알맞은 금액을 넣으십시오." << endl;
		return false;
	}
	numOfApples += seller.SaleApples(money);
	myMoney -= money;
	return true;
}
void FruitButer::ShowBuyResult() const{
	cout << "현재 잔액: " << myMoney << endl;
	cout << "사과 개수: " << numOfApples << endl << endl;
}

int main() {
	FruitSeller seller(1000, 20, 0);
	FruitButer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
}