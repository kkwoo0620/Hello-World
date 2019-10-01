#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Car.h"

int main() {
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}