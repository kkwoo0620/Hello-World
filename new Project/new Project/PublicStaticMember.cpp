#include<iostream>
using std::cout;
using std::endl;

class SoSimple
{
public:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;	// simObjCnt�� �޸� ������ ����� �� 0���� �ʱ�ȭ�϶�.

int main() {
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;
}