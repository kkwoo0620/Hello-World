#include<iostream>
#include"ArrayTemplate.h"
#include"TemplatePoint.h"
using std::cout;
using std::endl;

int main() {
	/* 정수형 저장*/
	BoundCheckArray<int> iarr(5);
	for (int i = 0; i < 5; i++)
	{
		iarr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << iarr[i] << endl;
	}

	/* point형 저장 */
	BoundCheckArray<Point> oarr(3);
	oarr[0] = Point(3, 4);
	oarr[1] = Point(5, 6);
	oarr[2] = Point(7, 8);
	for (int i = 0; i < oarr.GetArrLen(); i++)
	{
		cout << oarr[i];
	}

	/* Point 객체의 주소 값 */
	typedef Point * Point_PTR;

	BoundCheckArray<Point_PTR> parr(3);
	parr[0] = new Point(3, 4);
	parr[1] = new Point(5, 6);
	parr[2] = new Point(7, 8);
	for (int i = 0; i < parr.GetArrLen(); i++)
	{
		cout << *parr[i];
	}

	delete parr[0];
	delete parr[1];
	delete parr[2];
}