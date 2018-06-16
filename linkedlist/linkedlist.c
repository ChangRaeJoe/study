#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define element int
typedef struct a
{
	element data;
	struct a* next;
}listNode;//노드 값들 정의

typedef struct 
{
	listNode* head;
}linkedList_h;	//노드 헤더 정의


linkedList_h* createlinkedList_h(void) //노드헤더 생성함수
{
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h)*1);
	L->head = NULL;
	return L;
}

void printList(linkedList_h* L)	//현재 연결된 값들 화면찍는 함수
{
	listNode* p;
	p = L->head;
	while(p != NULL)	//p(head)값이 없으면 종료
	{
		printf("%d ", p->data);
		p = p->next;
		if(p !=NULL) printf(", ");
	}
	printf("\n print end \n");
}

void insert(linkedList_h* L, int x)
{
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode)*1);
	newNode->data = x;
	newNode->next = NULL;	//새로운 값 초기화
	if(L->head == NULL)
	{
		L->head = newNode;
		return;
	}

	temp = L->head;	//헤더값이 존재하면
	while(temp->next != NULL)	//링크드리스트의 제일 마지막을 가리킬때까지
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void deleteNode(linkedList_h* L, int x)
{
	listNode* pre;
	listNode* p_pre;
	if(L->head ==NULL)
	{
		printf("헤더가 없음\n");
		return;
	}
	if(L->head->next == NULL)	//Node가 1개밖에 없을 경우
	{
		free(L->head);
		L->head = NULL;
		return;
	}
	else
	{
		p_pre = L->head;
		pre = L->head;
		while(pre != NULL)
		{
			if(pre->data == x &&pre == p_pre)
			{
				//1번째 링크삭제 될때
				L->head = pre->next;
				free(pre);
				return;
			}
			if(pre->data == x)
			{
				//찾은 노드의 next값을 pre next로 대입, 노드들 사이에 있을경우
				p_pre->next = pre->next;
				free(pre);
				return;
			}
			p_pre = pre;
			pre = pre->next;

			if(pre ==NULL)	
			{
				//맨 마지막노드인데, x가 없을 경우
				return;

			}
		}
		
		
	}
}
int main()
{
	linkedList_h* L;	//헤더생성
	listNode* p;
	L = createlinkedList_h();
	printList(L);
	//추가
	insert(L, 1);
	insert(L, 2);
	insert(L, 7);
	insert(L, 11);
	printList(L);
	//출력
	//삭제

	deleteNode(L,1);	
	printList(L);
	deleteNode(L,7);
	printList(L);
	deleteNode(L,2);
	printList(L);
	deleteNode(L,11);
	printList(L);
	deleteNode(L, 3);
	//출력
	printf("hello world!!\n");
	return 0;
}
