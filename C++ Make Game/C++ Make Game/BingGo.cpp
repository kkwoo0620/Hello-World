#include<iostream>
#include<time.h>
using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	// 1 ~ 25 ���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}

	// ���ڸ� �����ش�.
	int idx1, idx2, temp;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = temp;

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = temp;
	}

	int iBingo = 0;
	int iAiBingo = 0;
	int iAIMode = 0;

	// AI ���̵��� �����Ѵ�.
	while (true) {
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��带 �����ϼ��� : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}
	/*
	AI Easy ���� ���� AI�� ���ڸ���� *�� �ٲ��� ���� ���� ����� ����
	�� ����� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�)
	*/
	// ���þȵ� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};
	// ���þȵ� ���� ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");

		// ���ڸ� 5 x 5�� ����Ѵ�
		cout << "--------------Player--------------" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int  j = 0;  j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << endl;
		cout << "Bingo Line : " << iBingo << endl;
		cout << endl;

		// (Ai)���ڸ� 5 x 5�� ����Ѵ�
		cout << "-------------Computer-------------" << endl;
		switch (iAIMode) {
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << endl;
		cout << "Bingo Line : " << iAiBingo << endl;
		cout << endl;

		// �� ���� 5 �̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5) {
			cout << "Player �¸�" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "Computer �¸�" << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 0 || iInput > 25)
			continue;

		// �ߺ��Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٶ��
		// �ϱ����� true�� ����־���.
		bool bAcc = true;

		for (int i = 0; i < 25; i++)
		{
			// ���� ���ڰ� ���� ���
			if (iInput == iNumber[i])
			{
				// ���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				// bAcc ������ false�� ������ش�.
				bAcc = false;

				iNumber[i] = INT_MAX;
				break;
			}


		}

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�.
		if (bAcc)
			continue;

		// �ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iAINumber[i])
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}
		// AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI��忡 ���� �޶�����.
		switch (iAIMode)
		{
			/*
			AI Easy ���� ���� AI�� ���ڸ���� *�� �ٲ��� ���� ���� ����� ����
			�� ����� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�)
			*/
		case AM_EASY:
			// ���þȵ� ���ڸ���� ������ش�.
			// ���þȵ� ���� ������ ����� ���� �� ī�������ش�.
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; i++)
			{
				// ���� ���ڰ� *�� �ƴ� ���
				if (iAINumber[i] != INT_MAX)
				{
					// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ��
					// �Ѵ�. ���� �ȵ� ��Ͽ� �߰��� ������ ������ 1�� ����
					// ���Ѽ� �� ���þȵ� ������ �����ش�.
					// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1��
					// �߰��Ǿ��� ��� ���ش�.
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}

			}

			// for���� ���������� �Ǹ� ���þȵ� ����� ���������
			// ���þȵ� ����� ������ ��������� �ȴ�.
			// ���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ����
			// �ε����� �����ϰ� �����ش�.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			// �ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ����
			// ã�Ƽ� �� �ٿ� �ִ� ������ �ϳ��� *�� ������ش�.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���� ���� ���� �� ���� *�� ���� ���� ã�Ƴ���.
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}

				// ���� 5�� �̸��̾�� ���� ���� �ƴϰ� ������ ���� ����
				// ������ ������ Ŀ�� ���� ���� ���� �����̹Ƿ� ������
				// ��ü���ְ� ����� �� ���� ��ü�Ѵ�.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// ����� ���� ������ ���� ���� ���� ������ üũ�ϴ�
					// ���̴�. ���ζ����� 0~4 �� �ǹ̸� �ο��ߴ�.
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� ������ ���� ���� ���� ������ �̹� ���ߴ�.
			// �� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[j * 5 + 1] == INT_MAX)
						++iStarCount;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// ���ζ����� 5~9 �� �ǹ̸� �ο��ߴ�.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// ���� -> ������ �밢�� üũ
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
				{ 
					++iStarCount;
					iSaveCount = 0;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = LN_LT;
					iSaveCount = iStarCount;
				}
				
			}

			// ������ -> ���� �밢�� üũ
			iStarCount = 0;
			for (int i = 4; i < 20; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
				{
					++iStarCount;
					iSaveCount = 0;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = LN_RT;
					iSaveCount = iStarCount;
				}

			}

			// ��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ��
			// ����Ǿ���.
			// �� �ٿ� �ִ� *�� �ƴ� ������ �ϳ��� �����ϰ� �Ѵ�.
			
			// �������� ���
			if (iLine <= LN_H5)
			{
				// �������� ��� iLine�� 0~4 ������ ���̴�.
				for (int i = 0; i < 5; i++)
				{
					// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5)
			{
				// �������� ��� iLine�� 5~9 ������ ���̴�.
				for (int i = 0; i < 5; i++)
				{
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT)
			{
				for (int i = 4; i < 20; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		}
		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		// AI ���ڸ� �ٲ��ش�.
		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// ���� �� ���� üũ�ϴ°��� �Ź� ���ڸ� �Է��� ������ ó������
		// ���� ī��Ʈ�� �Ұ��̴�. �׷��Ƿ� iBingo ������ 0���� �Ź�
		// �ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;
		iAiBingo = 0;

		// ����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		int iAiStar1 = 0, iAiStar2 = 0;


		for (int i = 0; i < 5; i++)
		{
			iStar1 = iStar2 = 0;
			iAiStar1 = iAiStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAiStar1;
				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAiStar2;
			}

			// j for ���� ���������� ���� ���� ���� ���� �� ������ �����
			// iStar1 ������ ���� �ȴ�. iStar1 ���� 5�̸� �� ����
			// ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iAiStar1 == 5)
				++iAiBingo;

			if (iAiStar2 == 5)
				++iAiBingo;
		}

		// ���� ��� -> ������ �ϴ� üũ
		iStar1 = 0;
		iAiStar1 = 0;
		for (int i = 0; i < 25; i+= 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAiStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		if (iAiStar1 == 5)
			++iAiBingo;

		iStar1 = 0;
		iAiStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAiStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		if (iAiStar1 == 5)
			++iAiBingo;

	}

	return 0;
}