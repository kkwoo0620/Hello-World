#include<iostream>
using std::cout;
using std::endl;

int LSearch(int ar[], int len, int target)	// 순차 탐색 알고리즘
{
	int i;
	for ( i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;	// 찾은 대상의 인덱스 값 반환
	}
	return -1;	// 찾지 못했을 때 -1 반환
}

int main(void)
{
	int arr[] = { 3,5,2,4,9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		cout << "탐색 실패" << endl;
	else
		cout << "타겟 저장 인덱스: " << idx << endl;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		cout << "탐색 실패" << endl;
	else
		cout << "타겟 저장 인덱스: " << idx << endl;

	return 0;
}