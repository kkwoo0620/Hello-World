#include<iostream>
using std::cout;
using std::endl;

class Car	// �⺻ ���� �ڵ���
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

class HybridCar : public Car	// ���̺긮�� �ڵ���
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

class HybridWaterCar : public HybridCar	// ���̺긮�� ����ī
{
private:
	int waterGauge;
public:
	HybridWaterCar() : waterGauge(300) {}
	void ShowCurrentGauge() const
	{
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};

int main()
{
	HybridWaterCar HC;
	HC.ShowCurrentGauge();
}