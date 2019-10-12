#define _CRT_SECURE_NO_WARNINGS
#include"NameCard.h"
#include<iostream>
using namespace std;

//typedef struct __namecard
//{
//	char name[NAME_LEN];
//	char phone[PHONE_LEN];
//} NameCard;

NameCard * MakeNameCard(const char * name, const char * phone)
{
	NameCard * newCard;
	newCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);
	return newCard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	cout << pcard->name << ", " << pcard->phone << endl;
}

int NameCompare(NameCard * pcard, const char * name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, const char * phone)
{
	strcpy(pcard->phone, phone);
}