#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueueLink* Queuelink_init()
{
	QueueLink* tmp = (QueueLink*)malloc(sizeof(QueueLink)*1);
	tmp->front = NULL;
	tmp->rear = NULL;
	return tmp;
}	//tmp마지막에 free
void Queue_print(QueueLink* ql)
{
	Queue* tmp = ql->front;
	while(tmp != NULL)
	{
		printf("all: %d\n", tmp->data);
		tmp = tmp->next;
	}
}
void Queue_push(QueueLink* ql, element data)
{
	Queue* tmp; 
	Queue* new = (Queue*)malloc(sizeof(Queue)*1);
	new->data = data;
	new->next = NULL;
	
	tmp = ql->front;
	if(tmp == NULL)
	{
		ql->front = new;
		ql->rear = new;
		return;
	}
	else
	{
		ql->rear->next = new;
		ql->rear = new;
		return;
	}
}

void Queue_pop(QueueLink* ql)
{
	Queue* tmp = ql->front;
	if(tmp == NULL)
	{
		printf("Queue empty\n");
	}
	else
	{
		ql->front = tmp->next;
		if(tmp->next == NULL)
		{
			ql->rear = NULL;
			ql->front = NULL;
		}
		printf("pop: %d\n", tmp->data);
		free(tmp);
	}
}
void Queue_free(QueueLink* ql)
{
	Queue* tmp = ql->front;
	//ql이 모두 비어있을때 그냥 free
	
	while(tmp != NULL)
	{
		tmp = tmp->next;
		Queue_pop(ql);
	}

	free(ql);
	//ql이 들어잇을때 다 free해줒고 마지막에 ql free해줌
}
