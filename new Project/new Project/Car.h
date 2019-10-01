#ifndef __CAR_H__
#define __CAR_H__

using std::cout;
using std::endl;

namespace CAR_CONST {
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int carSpeed;

public:
	void InitMembers(const char *ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();

};

inline void Car::ShowCarState() {
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << endl;
	cout << "현재속도: " << carSpeed << endl;
}

inline void Car::Break() {
	if (carSpeed < CAR_CONST::BRK_STEP) {
		carSpeed = 0;
		return;
	}

	carSpeed -= CAR_CONST::BRK_STEP;
}

#endif