//문자열 저장, 문자열 출력
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;

class Print {
private:
	char EmptyString[20];
public:
	void SetString(const char *String);
	void ShowString();
};

void Print::SetString(const char *String) {
	strcpy(EmptyString, String);
}

void Print::ShowString() {
	cout << EmptyString << endl;
}

int main() {
	Print P;
	P.SetString("Hello");
	P.ShowString();
}