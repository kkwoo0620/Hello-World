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
};

template <class T>
void SwapData(T& A, T& B)
{
	T temp = A;
	A = B;
	B = temp;
}

int main()
{
	Point A(1, 2);
	Point B(10, 20);

	SwapData(A, B);
	A.ShowPosition();
	B.ShowPosition();
}