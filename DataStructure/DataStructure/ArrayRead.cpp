#include<iostream>
using namespace std;

int main()
{
	int arr[10];
	int readCount = 0;
	int readData;

	while (1)
	{
		cout << "�ڿ��� �Է� : ";
		cin >> readData;
		if (readData < 1)
			break;

		arr[readCount++] = readData;
	}

	for (int i = 0; i < readCount; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}