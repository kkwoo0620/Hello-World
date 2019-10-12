#include<iostream>
#include"ArryList.h"
using namespace std;

int main()
{
	List list;
	NameCard * NC;
	NameCard * TempNC;
	NameCard * temp;

	ListInit(&list);	// list �ʱ�ȭ

	NC = MakeNameCard("������", "010-4149-3759");
	LInsert(&list, NC);
	
	NC = MakeNameCard("������", "010-2022-6482");
	LInsert(&list, NC);

	NC = MakeNameCard("�ڻ��", "010-2558-1652");
	LInsert(&list, NC);

	if (LFirst(&list, &TempNC))
	{
		if (!NameCompare(TempNC, "������"))
			ShowNameCardInfo(TempNC);
		while (LNext(&list, &TempNC))
		{
			if (!NameCompare(TempNC, "������"))
				ShowNameCardInfo(TempNC);
		}
	}

	if (LFirst(&list, &TempNC))
	{
		if (!NameCompare(TempNC, "�ڻ��"))
			ChangePhoneNum(TempNC, "010-1234");
		while (LNext(&list, &TempNC))
		{
			if (!NameCompare(TempNC, "�ڻ��"))
				ChangePhoneNum(TempNC, "010-1234");
		}
	}

	if (LFirst(&list, &TempNC))
	{
		if (!NameCompare(TempNC, "������"))
		{
			temp = LRemove(&list);
			delete temp;
		}
		while (LNext(&list, &TempNC))
		{
			if (!NameCompare(TempNC, "������"))
			{
				temp = LRemove(&list);
				delete temp;
			}
		}
	}

	if (LFirst(&list, &TempNC))
	{
		ShowNameCardInfo(TempNC);

		while (LNext(&list, &TempNC))
		{
			ShowNameCardInfo(TempNC);
		}
	}

}



















