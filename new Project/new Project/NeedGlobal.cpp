#include<iostream>
using std::cout;
using std::endl;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;	// simObjCnt가 메모리 공간에 저장될 때 0으로 초기화하라.
class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(const SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	~SoComplex()
	{
		cout<<"너무 소멸됐고" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();