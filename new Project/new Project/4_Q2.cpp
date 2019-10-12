#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	T *buf;
	int size;
	int capa;
public:
	Stack(int cap = 100) : capa(cap), size(0) {
		buf = new T[capa];
	}
	void Push(T i) {
		buf[size++] = i;
	}

	T operator[](int n)
	{
		return buf[n];
	}

	T Pop() {
		T temp = buf[size-1];
		buf[size--] = NULL;
		return temp;
	}

	~Stack() {
		delete buf;
	}

	bool Empty() {
		return size <= 0;
	}
};

int main()
{
	Stack<int> st(100);

	st.Push(10);
	st.Push(20);
	st.Push(30);


	if (!st.Empty())
		cout << st.Pop() << endl;
	if (!st.Empty())
		cout << st.Pop() << endl;
	if (!st.Empty())
		cout << st.Pop() << endl;

	return 0;
}