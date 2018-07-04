#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "fileio.h"

void fcfs(QueueLink* ql);
void ssjf(QueueLink* ql);
void scan(QueueLink* ql);
void look(QueueLink* ql);
void menu(QueueLink* ql, int* size);
int main()
{
	QueueLink* ql = NULL;
	int size = 0;
	input(&ql, &size);


	//menu
	menu(ql, &size);

	Queue_free(ql);	
	return 0;
}

void menu(QueueLink* ql, int* size)
{
	int input= 0;
	printf("hello, a program is simulation for disk scheduling\n");
	printf("1. fcfs\n");
	printf("2. ssjf\n");
	printf("3. scan\n");
	printf("4. look\n");
	printf("5. quit\n");

	while(1)
	{
		if(1 != scanf("%d", &input) )
			continue;
		else
			break;
	}
	
	switch(input)
	{
		case 1:
			fcfs(ql);
			break;
		case 2:
			ssjf(ql);
			break;
		case 3:
			scan(ql);
			break;
		case 4:
			look(ql);
			break;
		case 5:
			break;
		default:
			break;
			
	}
}

void fcfs(QueueLink* ql)
{
	printf("fcfs입니다.");
}

void ssjf(QueueLink* ql)
{
	printf("ssjf입니다.");
}

void scan(QueueLink* ql)
{
	printf("scan입니다.");
}

void look(QueueLink* ql)
{
	printf("look 입니다.");
}
