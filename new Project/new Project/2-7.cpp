#include<iostream>
using std::endl;
using std::cout;
void Client();

/////////////����////////////
void PrintHello()
{
	cout << "Hello!" << endl;
	Client();
}

/////////////Ŭ���̾�Ʈ////////////
void Client()
{
	cout << "�� Client" << endl;
}


int main()
{
	PrintHello();
}