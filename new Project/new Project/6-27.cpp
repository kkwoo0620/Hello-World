#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int> dq;

	for (deque<int>::size_type i = 0; i < 10; i++)
		dq.push_back((i + 1) * 10);

	for (deque<int>::size_type i = 0; i < dq.size(); i++)
		cout << dq[i] << endl;

	dq.push_front(100);

	cout << dq[0] << endl;

	deque<int>::iterator iter = dq.begin();

	dq.insert(iter, 300);
	cout << " È£¿ì" << endl;
	iter = dq.end()-1;
	dq.erase(iter);

	for (deque<int>::iterator v1 = dq.begin();  v1 != dq.end(); v1++)
		cout << *v1 << endl;


	return 0;
}