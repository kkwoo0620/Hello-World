#include<iostream>
#include<time.h>
#include<conio.h>

using std::cout;
using std::endl;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	iNumber[24] = INT_MAX;
	int iStarIndex = 24;

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (1) {
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		bool bWin = true;

		for (int i = 0; i < 24; i++)
		{
			if (iNumber[i] != i+1) {
				bWin = false;
			}
		}

		if (bWin)
		{
			cout << "�¸��Ͽ����ϴ�!" << endl;
			break;
		}

		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ���� : ";
		char cInput = _getch(); // ���� 1���� �Է¹޴� �Լ�. Enter ���ĵ� ���� ������ ���� �ٷ� �� ���� ��ȯ.

		if (cInput == 'q' || cInput == 'Q')
		{
			break;
		}

		switch (cInput) {
		case 'W':
		case 'w':
			if (iStarIndex > 4) {
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				iNumber[iStarIndex - 5] = INT_MAX;
				iStarIndex -= 5;
			}
			break;
		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0) {
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				iStarIndex -= 1;
			}
			break;
		case 'S':
		case 's':
			if (iStarIndex < 20) {
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;
		case 'D':
		case 'd':
			if (iStarIndex % 5 != 4) {
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				iStarIndex += 1;
			}
			break;
		}
	}

	cout << "������ �����մϴ�." << endl;

}