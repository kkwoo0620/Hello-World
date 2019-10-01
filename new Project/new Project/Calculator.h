#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

class Calculator {
private:
	int add;
	int min;
	int mult;
	int div;
public:
	void Init();
	double Add(double A, double B);
	double Min(double A, double B);
	double Mult(double A, double B);
	double Div(double A, double B);
	void ShowOpCount();
};

#endif