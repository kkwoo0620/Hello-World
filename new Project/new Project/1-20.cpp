#include<iostream>
using std::cout;
using std::endl;

class Point
{
private:
	int x;
	int y;
public:
	explicit Point(int x_ = 0, int y_  = 0) : x(x_), y(y_) {}
	void Print() const { cout << x << ',' << y << endl; }
	operator int()
	{
		return y;
	}
};

class PointPtr
{
private:
	Point *ptr;
public:
	PointPtr(Point *p) :ptr(p) {}
	~PointPtr()
	{
		delete ptr;
	}

	Point* operator->() const
	{
		return ptr;
	}
	Point& operator*() const
	{
		return *ptr;
	}
};

struct Func
{
public:
	int operator()(int a, int b, int c)
	{
		return a + b + c;
	}
};

int main()
{
	PointPtr p1 = new Point(2, 3);
	PointPtr p2 = new Point(5, 5);

	// p1->Print()  아직 사용 불가!
	Point a(10, 20);
	a.Print();
	//a = 30;
	a.Print();
	int n = 10;
	n = a;
	cout << n;
	Func c;
	n = c(1, 2, 3);
}
