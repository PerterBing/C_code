#pragma once
#include"Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QDataType front = QueueFront(&q);
	printf("%d ", front);
	QueuePop(&q);


	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");
}


int main()
{
	TestQueue();
	return 0;
}