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
	void Shut()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun * pistol;
public:
	Police(int bnum, int bcuff) :handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shut()
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shut();
	}
	~Police()
	{
		if (pistol != NULL) 
			delete pistol;
		cout << "delete" << endl;
	}
	Police(Police &copy):handcuffs(copy.handcuffs) {
		pistol = new Gun(*copy.pistol);
	}

	Police& operator=(const Police& P) {
		if(pistol != NULL)
			delete[]pistol;
		pistol = new Gun(*P.pistol);
		handcuffs = P.handcuffs;
		return *this;
	}
};

int main() {
	Police pman1(5, 3);
	Police pman2(0, 3);
	pman2 = pman1;
	pman1.Shut();
	pman1.PutHandcuff();
	pman2.Shut();
	pman2.PutHandcuff();
	return 0;
}