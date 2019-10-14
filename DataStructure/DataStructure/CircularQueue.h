#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define QUE_LEN		500
typedef int Data;

typedef struct _QUEUE
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif
