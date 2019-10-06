#include<iostream>
using namespace std;

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
	friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& pr)
{
	cout << '[' << pr.xpos << ", " << pr.ypos << ']' << endl;
	return os;
}

int main()
{
	Point pos1(1, 3);
	cout << pos1<<1<<endl;

}
