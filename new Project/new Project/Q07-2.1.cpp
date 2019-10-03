#include<iostream>
using std::cout;
using std::endl;

class Rectangle
{
private:
	int width;	//����
	int length;	//����
public:
	Rectangle(int wid, int leng) : width(wid), length(leng) {}
	void ShowAreaInfo() const
	{
		cout << "����: " << width * length << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int length): Rectangle(length, length){}
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}