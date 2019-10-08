#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::cout;
using std::endl;

class String
{
private:
	char * s;
public:
	String(const char * str) {
		s = new char[strlen(str) + 1];
		strcpy(s, str);
	}

	operator char*() {
		return s;
	}

	String& operator=(const String& str) {
		delete s;
		s = new char[(strlen(str.s))+1];
		strcpy(s, str.s);
		return *this;
	}
};


int main()
{
	/*String s("Hello!");
	const char* sz = s;
	cout << sz << endl;*/

	const char* sz = "Hello";
	String s("Hi~!");
	s = sz;
	cout << s << endl;

	return 0;
}

// 2, 3
// 4
// 3