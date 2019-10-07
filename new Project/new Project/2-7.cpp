#include<iostream>
using std::endl;
using std::cout;
void Client();

/////////////서버////////////
void PrintHello()
{
	cout << "Hello!" << endl;
	Client();
}

/////////////클라이언트////////////
void Client()
{
	cout << "난 Client" << endl;
}


int main()
{
	PrintHello();
}