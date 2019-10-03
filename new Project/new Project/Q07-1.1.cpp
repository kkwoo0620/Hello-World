#include<iostream>
using std::cout;
using std::endl;

class Car	// 기본 연료 자동차
{
private:
	int gasolineGauge;
public:
	Car() : gasolineGauge(100) {}
	int GetGasGauge() const
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car	// 하이브리드 자동차
{
private:
	int electricGauge;
public:
	HybridCar() : electricGauge(200) {}
	int GetElecGauge() const
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar	// 하이브리드 워터카
{
private:
	int waterGauge;
public:
	HybridWaterCar() : waterGauge(300) {}
	void ShowCurrentGauge() const
	{
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량 " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main()
{
	HybridWaterCar HC;
	HC.ShowCurrentGauge();
}