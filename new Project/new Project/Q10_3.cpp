#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend istream& operator>>(istream &os, Point &p);
	friend ostream& operator<<(ostream &os, Point &p);
};

ostream& operator<<(ostream &os, Point &p) {
	cout << '[' << p.xpos << ", " << p.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream &os, Point &p) {
	cin >> p.xpos;
	cin >> p.ypos;
	return os;
}

int main()
{
	Point pos1;
	cout << "x,y ��ǥ ������ �Է�: ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x,y ��ǥ ������ �Է�: ";
	cin >> pos2;
	cout << pos2;
	return 0;
		
}