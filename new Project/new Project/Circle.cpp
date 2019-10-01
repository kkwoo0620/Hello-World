#include<iostream>
using std::cout;
using std::endl;

class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y);
	void ShowPointInfo() const;
};

void Point::Init(int x, int y) {
	xpos = x;
	ypos = y;
}

void Point::ShowPointInfo() const {
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}

class Circle {
private:
	int radius;
	Point center;
public:
	void Init(int r, int x, int y);
	void ShowCircleInfo() const;
};

void Circle::Init(int r, int x, int y) {
	radius = r;
	center.Init(x, y);
}

void Circle::ShowCircleInfo() const {
	cout << "radius: " << radius << endl;
	center.ShowPointInfo();
}

class Ring {
private:
	Circle InCircle;
	Circle OutCircle;
public:
	void Init(int inxpos, int inypos, int inr, int outxpos, int outypos, int outr);
	void ShowRingInfo() const;
};

void Ring::Init(int inxpos, int inypos, int inr, int outxpos, int outypos, int outr) {
	InCircle.Init(inr, inxpos, inypos);
	OutCircle.Init(outr, outxpos, outypos);
}

void Ring::ShowRingInfo() const {
	cout << "Inner Circle Info..." << endl;
	InCircle.ShowCircleInfo();
	cout << "Outter Circle Info..." << endl;
	OutCircle.ShowCircleInfo();
}

int main() {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}