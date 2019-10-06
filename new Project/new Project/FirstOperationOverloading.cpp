#include<iostream>
using std::cout;
using std::endl;


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	void SetPoint(int xpos, int ypos) {
		this->xpos = xpos;
		this->ypos = ypos;
	}

	Point operator+(const Point &p) const {
		return Point(xpos + p.xpos, ypos + p.ypos);
	}

	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	Point operator++(int)
	{
		Point pr(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return pr;
	}
};

Point pos1;
Point pos2;
Point pos3;

int main()
{
	pos1.SetPoint(3, 4);
	pos2.SetPoint(10, 20);
	pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
}


//void hodu(Point p1,Point p2) {
//	pos3 = p1 + p2;
//}