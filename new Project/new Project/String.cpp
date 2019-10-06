#include"String.h"

String::String() :len(0), str(NULL) {}
String::String(const char * s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::~String() {
	if (str != NULL)
		delete[]str;
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
String& String::operator+=(const String& sub) {
	len += sub.len - 1;
	char * temp = new char[len];
	strcpy(temp, str);
	strcat(temp, sub.str);

	if (str != NULL)
		delete[]str;
	str = temp;
	delete[]temp;
	return *this;
}
bool String::operator==(const String& sub) {
	return (!strcmp(str, sub.str) ? true : false);
}
String String::operator+(const String& sub) {
	char * tempstr = new char[len + sub.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, sub.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}
ostream& operator<<(ostream& os, String& sub) {
	os << sub.str;
	return os;
}
istream& operator>>(istream& is, String& sub) {
	char str[100];
	is >> str;
	sub = String(str);
	return is;
}