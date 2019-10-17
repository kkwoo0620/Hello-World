#include<iostream>
using namespace std;

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (ar[first] > target || ar[last] < target);
		return -1;

	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;


	if (ar[mid] == target) {
		return mid;
	}
	else if (ar[mid] > target)
	{
		BSearchRecur(ar, first, mid - 1, target);
	}
	else
	{
		BSearchRecur(ar, mid + 1, last, target);
	}

}

int main()
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆÐ" << endl;
	else
		cout << "ÀÎµ¦½º : " << idx;

	return 0;
}