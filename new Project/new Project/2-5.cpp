#include<iostream>
using std::cout;
using std::endl;

class Point
{
	int xpos;
	int ypos;
public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void Print() const { cout << xpos << ',' << ypos << endl; }
	void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }
};

int main()
{
	Point pt(2, 3);
	Point *p = &pt;

	void(Point::*ptr)()const;
	void(Point::*ptr2)(int);

	ptr = &Point::Print;
	ptr2 = &Point::PrintInt;

	(pt.*ptr)();
	(pt.*ptr2)(2);
	(p->*ptr)();
}