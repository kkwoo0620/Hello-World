#include<iostream>
#include<cstdlib>
using namespace std;
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
	friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& pr)
{
	cout << '[' << pr.xpos << ", " << pr.ypos << ']' << endl;
	return os;
}

class BoundCheckPointArray
{
private:
	Point * arr;
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& copy) {};
	BoundCheckPointArray& operator=(const BoundCheckPointArray& copy) {};
public:
	BoundCheckPointArray(int len) :arrlen(len) {
		arr = new Point[len];
	}
	Point operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	Point operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckPointArray()
	{
		delete[]arr;
	}

};

int main()
{
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
	{
		cout << arr[i];
	}
}