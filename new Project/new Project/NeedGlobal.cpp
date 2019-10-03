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
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;	// simObjCnt�� �޸� ������ ����� �� 0���� �ʱ�ȭ�϶�.
class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(const SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	~SoComplex()
	{
		cout<<"�ʹ� �Ҹ�ư�" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();