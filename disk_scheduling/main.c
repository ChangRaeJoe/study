#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "fileio.h"
#define CUR 50
#define MAX 1004
void fcfs(QueueLink* ql, int cpos);
void ssjf(QueueLink* ql, int cpos, const int size);
void scan(QueueLink* ql, int cpos, int size);
void look(QueueLink* ql, int cpos, int size);
void menu(QueueLink* ql, int* size);
void bubble(int* tmp_arr, const int init, const int last, int asc); //if asc==1 then small->big

const int direction = 1;

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
	int cur = CUR;
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
			fcfs(ql, cur);
			break;
		case 2:
			ssjf(ql, cur, *size);
			break;
		case 3:
			scan(ql, cur, *size);
			break;
		case 4:
			look(ql, cur, *size);
			break;
		case 5:
			break;
		default:
			break;
			
	}
}

void fcfs(QueueLink* ql, int cpos)
{
	Queue* tmp = ql->front;
	int next = 0;
	int result = 0;
	while(tmp != NULL)
	{
		next = Queue_pop(ql);
		result += abs(next-cpos);
		printf("mid_data: %d\n", abs(next-cpos));
		cpos = next;
		tmp = tmp->next;
	}
	printf(" distance: %d\n", result);
}

void ssjf(QueueLink* ql, int cpos, const int size)
{
	//const int size를 넣으면 오류발생함.
	int tmp_arr[7] = {0, };
	Queue* tmp = ql->front;
	int next = 0;
	int tmp_data = 0;
	int i = 0, j = 0;
	int index=0, min=MAX, minus = 0;

	while(tmp != NULL && size>i)		//배열에 저장
	{
		next = Queue_pop(ql);
		tmp_arr[i] = next;
		tmp = tmp->next;
		i++;
	}
	for(i=0; i<size; i++)				//배열을 정렬
	{
		if(i != 0 )
		{
			cpos = tmp_arr[i-1];
		}
		min = MAX;
		for(j=i; j<size; j++)
		{
			minus = abs(cpos - tmp_arr[j]);
			if( minus < min )
			{
				index = j;
				min = minus;
			}
		}
		tmp_data = tmp_arr[i];
		tmp_arr[i] = tmp_arr[index];
		tmp_arr[index] = tmp_data;
	}
	for(i=0; i<size; i++)				//큐에 push
	{
		printf(" %d ", tmp_arr[i]);
		Queue_push(ql, tmp_arr[i]);
	}
	printf("\n");
	fcfs(ql, CUR);						//fcfs로 순서대로 실행
}
void bubble(int* tmp_arr, const int init, const int last, int asc) //if asc==1 then small->big
{
	int i, j;
	int tmp_data;
	if(asc == 1)
	{
			for(i=init; i<last; i++)				//array sorting
			{
				for(j=init; j<last-i-1; j++)
				{
					if(tmp_arr[j]>tmp_arr[j+1])	
					{
						tmp_data = tmp_arr[j];
						tmp_arr[j] = tmp_arr[j+1];
						tmp_arr[j+1] = tmp_data;
					}
				}
			}
	}
	else if(asc == 0)
	{
		for(i=init; i<last; i++)				//array sorting
			{
				for(j=init; j<last-i-1; j++)
				{
					if(tmp_arr[j]<tmp_arr[j+1])	
					{
						tmp_data = tmp_arr[j];
						tmp_arr[j] = tmp_arr[j+1];
						tmp_arr[j+1] = tmp_data;
					}
				}
			}
	}
	else
	{
		printf("sortin Error\n");
	}

}

void scan(QueueLink* ql, int cpos, int size)
{
	int tmp_arr[7] = {0, };
	Queue* tmp = ql->front;
	int next = 0;
	int tmp_data = 0;
	int i = 0, j = 0;
	int index=0, min=MAX, minus = 0;
	int cyl_index = 0;
	while(tmp != NULL && size>i)		//array save
	{
		next = Queue_pop(ql);
		tmp_arr[i] = next;
		tmp = tmp->next;
		i++;
	}
	if(direction == 0)	bubble(tmp_arr, 0, size, 1);
	else bubble(tmp_arr, 0, size, 0);
	
	for(i=0; i<size; i++)				//current cylinder index
	{
		if(direction==0 && CUR > tmp_arr[i])
		{
			cyl_index = i;
		}
		else if(direction==1 && CUR < tmp_arr[i])
		{
			cyl_index = i;
		}
		
	}

	if(direction == 0){
		bubble(tmp_arr, 0, cyl_index+1, 0);		//<=cyl_index	
		bubble(tmp_arr, cyl_index+1, size, 1);	//>cyl_index
	}
	else{
		bubble(tmp_arr, 0, cyl_index+1, 1);
		bubble(tmp_arr, cyl_index+1, size, 0);
	}

	for(i=0; i<size; i++)				//큐에 push
	{
		printf(" %d ", tmp_arr[i]);
		Queue_push(ql, tmp_arr[i]);
	}
	printf("\n");
	fcfs(ql, CUR);						//fcfs algorithm executing


}

void look(QueueLink* ql, int cpos, int size)
{
	printf("look 입니다.");
}
