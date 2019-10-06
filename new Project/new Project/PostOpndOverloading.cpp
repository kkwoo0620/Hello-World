#include<iostream>
using std::cout;
using std::endl;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++() // 전위 증가
	{
		xpos++;
		ypos++;
		return *this;
	}
	const Point operator++(int) {
		const Point ref(*this);
		xpos += 1;
		ypos += 1;
		return ref;
	}
};