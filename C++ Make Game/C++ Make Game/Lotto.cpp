#include<iostream>
#include<ctime>
using std::cout;
using std::endl;

int main() {
	cout << "�ζ� ��÷�� �����մϴ�!!" << endl;
	
	int Lotto[45];
	
	// 1���� 45���� �迭�� �ֱ�.
	for (int i = 0; i < 45; i++)
	{
		Lotto[i] = i + 1;
	}

	srand((unsigned int)time(0));
	
	// 100�� ���� �����ֱ�. shuffle
	for (int i = 0; i < 100; i++)
	{
		int idx1 = rand() % 45;
		int idx2 = rand() % 45;

		int temp = Lotto[idx1];
		Lotto[idx1] = Lotto[idx2];
		Lotto[idx2] = temp;
	}
	
	for (int i = 0; i < 6; i++)
	{
		cout << Lotto[i] << ' ';
	}

	cout << endl;

	cout << "���ʽ� ��ȣ: " << Lotto[6];
}
