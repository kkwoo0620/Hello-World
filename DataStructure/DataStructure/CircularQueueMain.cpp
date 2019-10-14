#include<iostream>
#include"CircularQueue.h"
using namespace std;

int main()
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QIsEmpty(&q))
		cout << Dequeue(&q) << ", ";

	return 0;
}