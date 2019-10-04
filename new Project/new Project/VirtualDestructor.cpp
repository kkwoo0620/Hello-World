#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class First
{
private:
	char * strOne;
public:
	First(const char * str)
	{
		strOne = new char[(strlen(str) + 1)];
		strcpy(strOne, str);
	}
	virtual ~First() {
		cout << "~First()" << endl;
		delete []strOne;
	}
};

class Second : public First
{
private:
	char * strTwo;
public:
	Second(const char * str1, const char * str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
		strcpy(strTwo, str2);
	}
	~Second()
	{
		cout << "~Second()" << endl;
		delete []strTwo;
	}
};

int main()
{
	First * ptr = new Second("simple", "complex");
	delete ptr;
	return 0;
}