#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{}
	void shut()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police : public Gun {
private:
	int handcuffs;
public:
	Police(int bnum, int bcuff) :Gun(bnum), handcuffs(bcuff)
	{}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int main() {
	Police pman(5, 3);
	pman.shut();
	pman.PutHandcuff();
	return 0;
}