#include<iostream>
#include<list>
using namespace std;

bool Predicate(int n)
{
	return 10 <= n && 30 >= n;
}


int main()
{
	list<int> lt, lt2;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(10);

	lt2.push_back(10);
	lt2.push_back(10);
	lt2.push_back(50);
	lt2.push_back(10);
	lt2.push_back(10);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << ", ";
	}
	cout << endl;

	lt.remove_if(Predicate);

	for (iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << ", ";
	}
	cout << endl;

	iter = lt.begin();

	lt.splice(iter, lt2);

	for (iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << ", ";
	}
	cout << endl;

	lt.reverse();
	lt.sort();	// ��������
	lt.sort(greater<int>());	// ��������

	lt.sort();

	lt2.push_back(10);
	lt2.push_back(30);
	lt2.push_back(50);
	lt2.push_back(20);
	lt2.push_back(40);

	for (iter = lt2.begin(); iter != lt2.end(); iter++)
	{
		cout << *iter << ", ";
	}
	cout << endl;
	lt2.sort();

	lt.merge(lt2);

	for (iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << ", ";
	}
	cout << endl;

	

	return 0;
}

// 1, 3, 5, 6, 
// 1, 3, 4, 5,
// 2, 4, 7,
//10, 100, 20, 30, 40, 50, N
//size 5 capacity 10
//


//8. �յڷ� �߰� ������ ����. 4�� �̸� �ø�.
//9. �迭����� �ƴ� ������̹Ƿ� �������Žÿ� �ð��� ���԰ɸ���.
//10. 2. ������ �����̳���. 3. ���ʹ� ����� ��ĭ�� ������ ��� ���������ϳ� list�� �հ� �ڸ� �������ָ� �ȴ�.
//	  4. erase�� ��������
//11. ...?
//12 insert�� �߰����ִ°��̰� splice�� �߶󳻱�.