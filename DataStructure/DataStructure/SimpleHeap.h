#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define HEAP_LEN	100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
	Priority pr;	// ���� �������� ���� �켱����
	HData data;
} HeapElem;

typedef struct _heap
{
	int numOfdata;
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(HEap * ph);

#endif
