#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
	int temp;
	
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < (n-i)-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SelectionSort(int arr[], int n)
{
	int minIdx;

	for (int i = 0; i < n; i++)
	{
		minIdx = i;

		for (int j = i+1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
				minIdx = j;
		}

		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}

void InsertSort(int arr[], int n)
{
	int insData;
	int j;

	for (int i = 1; i < n; i++)
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insData;
	}
}

int main()
{
	int arr[4] = { 3, 2, 4, 1 };
	int;

//BubbleSort(arr, sizeof(arr)/sizeof(int));
//	SelectionSort(arr, sizeof(arr) / sizeof(int));
	InsertSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		cout << arr[i];
	}

	return 0;
}