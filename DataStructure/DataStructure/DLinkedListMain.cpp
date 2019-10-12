#include<iostream>
#include"DLinkedList.h"
using namespace std;

int main()
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 44);
	LInsert(&list, 55);

	cout << LCount(&list) << endl;

	if (LFirst(&list, &data))
	{
		cout << data << endl;

		while (LNext(&list, &data)) 
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	cout << LCount(&list) << endl;

	if (LFirst(&list, &data))
	{
		cout << data << endl;
		while (LNext(&list, &data))
		{
			cout << data << endl;
		}
	}

	void;
}