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
	Point operator+=(const Point &ref) {
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point operator-=(const Point &ref) {
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	bool operator==(const Point &ref) {
		if (xpos == ref.xpos && ypos == ref.ypos) {
			return true;
		}
		return false;
	}
	bool operator!=(const Point &ref) {
		return !(*this == ref);
	}

	friend Point operator+(const Point &pos1, const Point &pos2);
	friend Point operator-(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos - pos2.ypos, pos1.ypos - pos2.ypos);
	return pos;
}

int main()
{
	Point pos1(10, 20);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	(pos1 += pos2).ShowPosition();

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	if (pos1 != pos2) {
		cout << "맞음" << endl;
	}
	else {
		cout << "다름" << endl;
	}
}