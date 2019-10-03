#include<iostream>
using std::cout;
using std::endl;

void counter() {
	static int cnt;
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main() {
	for (int i = 0; i < 10; i++)
	{
		counter();
	}
}