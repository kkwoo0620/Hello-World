#include<iostream>
#include"ArryList.h"
using namespace std;

int main()
{
	List list;
	NameCard * NC;
	NameCard * TempNC;
	NameCard * temp;

	ListInit(&list);	// list 초기화

	NC = MakeNameCard("김정우", "010-4149-3759");
	LInsert(&list, NC);
	
	NC = MakeNameCard("김현수", "010-2022-6482");
	LInsert(&list, NC);

	NC = MakeNameCard("박상거", "010-2558-1652");
	LInsert(&list, NC);

	if (LFirst(&list, &TempNC))
	{
		if (!NameCompare(TempNC, "김정우"))
			ShowNameCardInfo(TempNC);
		while (LNext(&list, &TempNC))
		{
			if (!NameCompare(TempNC, "김정우"))
				ShowNameCardInfo(TempNC);
		}
	}

	if (LFirst(&list, &TempNC))
	{
		if (!NameCompare(TempNC, "박상거"))
			ChangePhoneNum(TempNC, "010-1234");
		while (LNext(&list, &TempNC))
		{
			if (!NameCompare(TempNC, "박상거"))
				ChangePhoneNum(TempNC, "010-1234");
		}
	}

	if (LFirst(&list, &TempNC))
	{
		if (!NameCompare(TempNC, "김현수"))
		{
			temp = LRemove(&list);
			delete temp;
		}
		while (LNext(&list, &TempNC))
		{
			if (!NameCompare(TempNC, "김현수"))
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



















