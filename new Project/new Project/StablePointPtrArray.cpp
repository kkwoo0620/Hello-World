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
	friend ostream& operator<<(ostream&, const Point&);
	friend ostream& operator<<(ostream&, const Point*);
};

ostream& operator<<(ostream& os, const Point& pr)
{
	cout << '[' << pr.xpos << ", " << pr.ypos << ']' << endl;
	return os;
}

ostream& operator<<(ostream& os, const Point *pr)
{
	cout << '[' << pr->xpos << ", " << pr->ypos << ']' << endl;
	return os;
}



int main()
{
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
	{
		cout << arr[i];
	}
	delete arr[0];
	delete arr[1];
	delete arr[2];
}