#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

namespace RISK_LEVEL
{
	double RISK_A = 0.3;
	double RISK_B = 0.2;
	double RISK_C = 0.1;
}

class Employee
{
private:
	char name[100];
public:
	Employee(const char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char * name, int pay) :Employee(name), workTime(0), payPerHour(pay) {}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	virtual int GetPay() const
	{
		return workTime * payPerHour;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char * name, int money) :Employee(name), salary(money)
	{
	}
	virtual int GetPay() const
	{
		return salary;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << salary << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	virtual int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class ForeignSalesWorker : public SalesWorker
{
private:
	double risk;
public:
	ForeignSalesWorker(const char * name, int money, double ratio, double risk) :SalesWorker(name, money, ratio), risk(risk) {}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
		cout << "risk pay: " << (int)(GetPay()*risk) << endl;
		cout << "sum: " << GetPay() + ((int)(GetPay()*risk)) << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main()
{
	EmployeeHandler handler;

	//정규직
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));

	//임시직
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//영업직 등록
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("hodu", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("hodu", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);



	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
}