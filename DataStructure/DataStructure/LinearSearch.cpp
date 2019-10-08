#include<iostream>
using std::cout;
using std::endl;

int LSearch(int ar[], int len, int target)	// ���� Ž�� �˰���
{
	int i;
	for ( i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;	// ã�� ����� �ε��� �� ��ȯ
	}
	return -1;	// ã�� ������ �� -1 ��ȯ
}

int main(void)
{
	int arr[] = { 3,5,2,4,9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		cout << "Ž�� ����" << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		cout << "Ž�� ����" << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl;

	return 0;
}