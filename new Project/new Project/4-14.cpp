#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

template<class T>
class ObjectInfo
{
private:
	T data;
public:
	ObjectInfo(const T& d) : data(d) { }

	void Print()
	{
		cout << typeid(data).name() << endl;
		cout << sizeof(data) << endl;
		cout << data << endl;
		cout << endl;
	}
};

template<>
class ObjectInfo<string>
{
private:
	string data;
public:
	ObjectInfo(const string& d) : data(d) {}

	void Print()
	{
		cout << "String" << endl;
		cout << data.size() << endl;
		cout << data << endl;
		cout << endl;
	}
};

int main()
{
	ObjectInfo<string> d3("Hello!");
	d3.Print();
}