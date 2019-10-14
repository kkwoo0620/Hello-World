#include<iostream>
#include<cstdlib>
#include<time.h>
#include"CircularQueue.h"
using namespace std;

#define CUS_COME_TERM	15

enum
{
	CHE_BUR, BUL_BUR, DUB_BUR
};

enum
{
	CHE_TERM = 12,
	BUL_TERM = 15,
	DUB_TERM = 24
};

int main()
{
	int makeProc = 0;	// �ܹ��� ���� �����Ȳ
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand((unsigned int)time(0));

	// �Ʒ� for���� 1ȸ ȸ���� 1���� �ð� �帧�� �ǹ���
	for (sec = 0; sec < 3600; sec++)
	{
		if (sec%CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);
				cheOrder += 1;
				break;

			case BUL_BUR:
				Enqueue(&que, BUL_TERM);
				bulOrder += 1;
				break;

			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				dubOrder += 1;
				break;
			}
		}

		if (makeProc == 0 && !QIsEmpty(&que))
			makeProc == Dequeue(&que);

		makeProc--;
	}

	cout << "Simulation Reprot!" << endl;
	cout << "- Cheese burger : " << cheOrder << endl;
	cout << "- Bulgogi burger : " << bulOrder << endl;
	cout << "- Double burger : " << dubOrder << endl;
	cout << "- Waiting room size: " << QUE_LEN << endl;

	return 0;
}