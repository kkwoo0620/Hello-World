#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include"Account.h"
typedef Account * ACCOUNT_PTR;

class BoundCheckPointPtrArray
{
private:
	ACCOUNT_PTR * arr;
	int arrlen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& copy) {};
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& copy) {};
public:
	BoundCheckPointPtrArray(int len);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckPointPtrArray();
};

#endif