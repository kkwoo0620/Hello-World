#ifndef __ARRAY_TEMPLATE_H__
#define __ARRAY_TEMPLATE_H__

#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;

template <class T>
class BoundCheckArray
{
private:
	T * arr;
	int arrlen;
	BoundCheckArray(BoundCheckArray& copy) {};
	BoundCheckArray& operator=(BoundCheckArray& copy) {};
public:
	BoundCheckArray(int len) :arrlen(len) {
		arr = new T[len];
	}
	T& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	T operator[](int idx) const
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
	~BoundCheckArray()
	{
		delete[]arr;
	}

};


#endif