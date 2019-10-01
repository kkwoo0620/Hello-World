#include"Calculator.h"
#include<iostream>

using std::cout;
using std::endl;

void Calculator::Init() {
	add = 0;
	min = 0;
	mult = 0;
	div = 0;
}

double Calculator::Add(double A, double B) {
	add++;
	return A + B;
}

double Calculator::Min(double A, double B) {
	min++;
	return A - B;
}

double Calculator::Mult(double A, double B) {
	mult++;
	return A * B;
}

double Calculator::Div(double A, double B) {
	div++;
	return A / B;
}

void Calculator::ShowOpCount() {
	cout << "µ¡¼À: " << add << " »¬¼À: " << min << " °ö¼À: " << mult << " ³ª´°¼À: " << div << endl;

}
