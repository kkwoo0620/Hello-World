#include<iostream>
#include<cstdlib>
#include"DLinkedList.h"
#include"Point.h"

using namespace std;

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1->xpos < d2->xpos)
		return 0;
	else if (d1->xpos == d2->ypos) {
		if (d1->ypos < d2->ypos)
			return 0;
		else
			return 1;
	}
		return 1;
}

int main()
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);
	SetSortRule(&list, WhoIsPrecede);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos,2, 1);
	LInsert(&list,ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	cout << LCount(&list) << endl;

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}

	cout << endl;

	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
}