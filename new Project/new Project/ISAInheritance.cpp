#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char * name)
	{
		strcpy(owner, name);
	}
	void Calculate() const {
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int battary;
public:
	NotebookComp(const char * name, int initChag) :Computer(name), battary(initChag)
	{}
	void Charging() { battary += 5; }
	void UseBattary() { battary -= 1; }
	void MovingCal() {
		if (GetBattaryInfo() < 1) {
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		Calculate();
		UseBattary();
	}
	int GetBattaryInfo() const { return battary; }
};

class TabletNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(const char * name, int initChag, const char * pen) : NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void write(const char * penInfo)
	{
		if (GetBattaryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�" << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattary();
	}
};

int main()
{
	NotebookComp nc("�̼���", 5);
	TabletNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.write("ISE-241-242");
	return 0;
}