#include<iostream>
using std::cout;
using std::endl;

//template <class T, class T2>
//void Print(const T A, const T2 B) 
//{
//	cout << A << B << endl;
//}

template<class T>
void Swap(T& A, T& B)
{
	T temp = A;
	A = B;
	B = temp;
}

template<class T, int size>
void PrintArray(T* arr)
{
	for (int i = 0; i < size; i++)
	{
		cout << '[' << i << "] : " << arr[i] << endl;
	}
}

class Point
{
private:
	int xpos;
	int ypos;
public:
	explicit Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void Print() const { cout << xpos << ',' << ypos << endl; }
};

template<class T>
void Print(T a)
{
	cout << a << endl;
}

template<>
void Print(Point a)
{
	a.Print();
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	Print(pt);

	int a = 1;
	int b = 2;

	Swap(a, b);
	
	int arr1[5] = { 1, 2, 3, 4, 5};
	PrintArray<int, 5>(arr1);
}