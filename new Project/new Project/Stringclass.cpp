#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * str);
	String(const String& copy);
	~String();
	String& operator=(const String& sub);
	String& operator+=(const String& sub);
	bool operator==(const String& sub);
	String operator+(const String& sub);

	friend ostream& operator<<(ostream& os, const String& sub);
	friend istream& operator>>(istream& os, String& sub);

};

String::String() : str(NULL), len(0) {};

String::String(const char * sub) {
	len = strlen(sub) + 1;
	str = new char[len];
	strcpy(str, sub);
}

String::String(const String& sub) {
	len = sub.len;
	str = new char[len];
	strcpy(str, sub.str);
}

String& String::operator=(const String& sub) {
	if (str != NULL)
		delete[]str;
	len = sub.len;
	str = new char[len];
	strcpy(str, sub.str);
	return *this;
}

String String::operator+(const String& sub) {
	char * tempstr = new char[len + sub.len - 1];
	strcat(tempstr, str);
	strcat(tempstr, sub.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

String& String::operator+=(const String& sub) {
	len += (sub.len - 1);
	char * temp = new char[len];
	strcat(temp, str);
	strcat(temp, sub.str);

	if (str != NULL)
		delete str;
	str = temp;
	return *this;
}

bool String::operator==(const String& sub) {
	if (!strcmp(str, sub.str))
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const String& sub) {
	os << sub.str;
	return os;
}

istream& operator>>(istream& os, String& sub) {
	char temp[100];
	cin >> temp;
	sub = String(temp);
	return os;
}

String::~String() {
	if (str != NULL)
		delete[]str;
}

int main()
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3) {
		cout << "동일 문자열" << endl;
	}
	else {
		cout << "동일하지 않은 문자열" << endl;
	}

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;

}