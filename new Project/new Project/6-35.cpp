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
	lt.sort();	// 오름차순
	lt.sort(greater<int>());	// 내림차순

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


//8. 앞뒤로 추가 해제가 가능. 4씩 미리 늘림.
//9. 배열기반이 아닌 노드기반이므로 삽입제거시에 시간이 적게걸린다.
//10. 2. 시퀀스 컨테이너임. 3. 백터는 지우면 한칸씩 앞으로 모두 움직여야하나 list는 앞과 뒤만 연결해주면 된다.
//	  4. erase와 마찬가지
//11. ...?
//12 insert는 추가해주는것이고 splice는 잘라내기.