#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool Pred(int a, int b)
{
	return abs(b - a) > 10;
}

bool Pred25(int a)
{
	return a > 25;
}

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
	v.push_back(50);
	v.push_back(70);

	vector<int> v2;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter;

	iter = adjacent_find(v.begin(), v.end()); // ���� begin~end ���� ���� ���ҿ� ���� ���Ұ� �������� ù ���� �ݺ��ڸ� ��ȯ
	
	for ( iter; iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	vector<int>::iterator iter2 = v.begin()+2;

	iter = adjacent_find(v.begin(), iter2);

	if (iter != iter2)
		cout << *iter << endl;

	iter = adjacent_find(v.begin(), v.end(), Pred);

	cout << *iter << endl;

	cout << " ���� v�� 30�� ���� : " << count(v.begin(), v.end(), 30) << endl;
	cout << " ���� v�� 25�̻� ���� ���� : " << count_if(v.begin(), v.end(), Pred25) << endl;

	if (equal(v2.begin(), v2.end(), v.begin()))
		cout << "v �� v2 �� v.begin~ v.begin+2 ���� ����" << endl;

	if (equal(v2.begin(), v2.end(), v.begin(), Pred))
		cout << "v �� v2 �� v.begin~ v.begin+2 ���� ����" << endl;

	return 0;
}