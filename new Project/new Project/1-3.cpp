#include<iostream>
using std::cout;
using std::endl;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void Print() const { cout << xpos << ',' << ypos << endl; }
	const Point operator+(const Point& arg) {
		Point pt;
		pt.xpos = xpos + arg.xpos;
		pt.ypos = ypos + arg.ypos;

		return pt;
	}
	const Point& operator++(){
		xpos++;
		ypos++;
		return *this;
	}
	const Point operator++(int) {
		Point pt(xpos, ypos);
		++xpos;
		++ypos;
		return pt;
	}
	const bool operator!=(const Point& arg) const {
		return !(*this == arg);
	}
	const bool operator==(const Point& arg) const{
		return xpos == arg.xpos && ypos == arg.ypos ? true : false;
	}

};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;
	p3 = p1 + p2;
	p3.Print();
	(++p3);
	p3.Print();
	if (p1 != p2) {
		cout << "гоюл" << endl;
	}
}