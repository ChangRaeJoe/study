#include <stdio.h>
#include <stdlib.h>
//자기 헤더파일추가
#include "fileio.h"

void input(QueueLink** ptr, int* size)
{
	FILE* fp = (FILE*)fopen("disk.txt", "r");
	int i = 0, tmp = 0;
	if(fp == NULL)
	{
		puts(".txt Read Eroor");
		return;
	}
	
	while(1 == fscanf(fp, "%d", &tmp))
	{
		if(*ptr == NULL)
		{
			*ptr = Queuelink_init();
			Queue_push(*ptr, tmp);
		}
		else
		{
			Queue_push(*ptr, tmp);
		}
		*size = *size+1;
	}


	fclose(fp);
	
}

