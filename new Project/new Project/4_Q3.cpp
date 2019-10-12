#include<iostream>
using namespace std;

template<class T>
class Queue
{
private:
	T *buf;
	int size;
	int del;
	int capa;
public:
	Queue(int cap = 100) :capa(cap), size(0), buf(0), del(0) {
		buf = new T[capa];
	}
	~Queue()
	{
		delete buf;
	}
	void push(const T n) {
		buf[size++] = n;
	}
	T Pop() {
		T temp = buf[del];
		buf[del++] = NULL;
		return temp;
	}
	bool Empty() {
		return size <= 0 ? true : false;
	}
};

int main()
{
	Queue<int> q(100);
	q.push(10);
	q.push(20);
	q.push(30);
	
	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;
	
}