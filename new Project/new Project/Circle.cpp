#include<iostream>
using std::cout;
using std::endl;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y) {}
	void ShowPointInfo() const;
};

void Point::ShowPointInfo() const {
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}

class Circle {
private:
	int radius;
	Point center;
public:
	Circle(int r, int x, int y) :radius(r), center(x, y) {}
	void ShowCircleInfo() const;
};

void Circle::ShowCircleInfo() const {
	cout << "radius: " << radius << endl;
	center.ShowPointInfo();
}

class Ring {
private:
	Circle InCircle;
	Circle OutCircle;
public:
	Ring(int inxpos, int inypos, int inr, int outxpos, int outypos, int outr) : InCircle(inr, inxpos, inypos), OutCircle(outr, outxpos, outypos) {}
	void ShowRingInfo() const;
};

void Ring::ShowRingInfo() const {
	cout << "Inner Circle Info..." << endl;
	InCircle.ShowCircleInfo();
	cout << "Outter Circle Info..." << endl;
	OutCircle.ShowCircleInfo();
}

int main() {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}