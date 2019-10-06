#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;

class BoundCheckIntArray
{
private:
	int * arr;
	int arrlen;
	BoundCheckIntArray(BoundCheckIntArray& copy) {};
	BoundCheckIntArray& operator=(BoundCheckIntArray& copy) {};
public:
	BoundCheckIntArray(int len) :arrlen(len) {
		arr = new int[len];
	}
	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[](int idx) const
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
	~BoundCheckIntArray()
	{
		delete[]arr;
	}

};

void ShowAllData(const BoundCheckIntArray& ref) {
	int len = ref.GetArrLen();
	for (int i = 0; i < len; i++)
	{
		cout << ref[i] << endl;
	}
}

int main() {
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}
}