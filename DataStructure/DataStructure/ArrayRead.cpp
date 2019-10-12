#include<iostream>
using namespace std;

int main()
{
	int arr[10];
	int readCount = 0;
	int readData;

	while (1)
	{
		cout << "자연수 입력 : ";
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