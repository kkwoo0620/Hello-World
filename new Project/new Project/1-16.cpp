#include<iostream>
using std::cout;
using std::endl;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	
	void Print() const { cout << xpos << ',' << ypos << endl; }

	int operator[](int idx) const
	{
		if (idx == 0)
			return xpos;
		else if (idx == 1)
			return ypos;
		else
			throw "이럴 수는 없는거야!";
	}
};

int main()
{
	Point pt(1, 2);
	pt.Print();

	cout << pt[0] << ',' << pt[1] << endl;
}