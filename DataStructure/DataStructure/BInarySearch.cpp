#include<iostream>
using std::cout;
using std::endl;

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;

		if (target == ar[mid])
			return mid;
		else {
			if (ar[mid] > target) {
				last = mid - 1;
			}
			else {
				first = mid + 1;
			}
		}
	}

	return -1;
}

int main()
{
	int arr[] = { 1, 3, 5, 7 ,9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ" << endl;
	else
		cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º : " << idx << endl;
}