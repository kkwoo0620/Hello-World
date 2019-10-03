#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::cout;
using std::endl;

class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(const char * myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowMyFriendInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(const char * myname, int myage, const char * myaddr, const char * myphone) : MyFriendInfo(myname, myage)
	{
		addr = new char[strlen(myaddr) + 1];
		phone = new char[strlen(myphone) + 1];
		strcpy(addr, myaddr);
		strcpy(phone, myphone);
	}
	void ShowMyfriendDetailInfo() const
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}
	~MyFriendDetailInfo() {
		delete[]addr;
		delete[]phone;
	}
};

int main() {
	MyFriendDetailInfo Ho("김정우", 20, "고척동", "010-1111-1111");
	Ho.ShowMyfriendDetailInfo();
}