#include<iostream>
using std::cout;
using std::endl;

template <class T=int, int capT=100>
class Array
{
private:
	T *buf;
	int capacity;
	int size;
public:
	Array(int cap = capT) : capacity(cap), size(0), buf(0)
	{
		buf = new T[capacity];
	}
	
	~Array()
	{
		delete buf;
	}

	void Add(T data)
	{
		buf[size++] = data;
	}

	T operator[](int idx) const
	{
		return buf[idx];
	}

	int GetSize() const
	{
		return size;
	}
};

int main()
{
	Array<int> arr(10);
	
	arr.Add(10);
	arr.Add(20);
	arr.Add(30);

	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}