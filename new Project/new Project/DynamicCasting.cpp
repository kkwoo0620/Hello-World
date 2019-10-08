#include<iostream>
using std::cout;
using std::endl;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel) {}
	void ShowCarState() const { cout << "잔여 연료량 : " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
	int freightWeight;
public:
	Truck(int fuel, int weight) : Car(fuel), freightWeight(weight) {}
	void ShowTruckState() const {
		ShowCarState();
		cout << "화물이 무게 : " << freightWeight << endl;
	}
};

int main()
{
	//Car * pcar1 = new Truck(80, 200);
	//Truck * ptruck1 = dynamic_cast<Truck *>(pcar1); 오류.

	Car * pcar1 = new Truck(80, 200);
	Truck * ptruck1 = static_cast<Truck *>(pcar1);

	Truck * ptruck2 = new Truck(80, 200);
	Car * pcar2 = dynamic_cast<Car *>(ptruck2);
}