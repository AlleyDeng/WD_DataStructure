/*
* LinkList.c
*
*  Created on: 2018年9月2日
*      Author: deng_chao
*/

#include "LinkList.h"

Status GetLinkListElem(LinkList LHead, int pos, ElemType *e)
{	// 带头结点
	int j = 1;
	LinkList p = LHead->next;

	while (p != NULL && j < pos)
	{
		p = p->next;
		++j;
	}

	if (p == NULL || j != pos)
	{
		return ERROR;
	}

	*e = p->data;
	return OK;
}

Status LinkListInsert(LinkList LHead, int pos, ElemType e)
{
	int j = 1;
	LinkList p = LHead;
	LinkList s;

	while (p != NULL && j < pos)
	{
		p = p->next;
		++j;
	}

	if (p == NULL || j != pos)
	{
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status LinkListDelete(LinkList LHead, int pos, ElemType *e)
{
	int j;
	LNode *p, *q;
	p = LHead;
	j = 1;
	while (p->next != NULL && j < pos)
	{
		p = p->next;
		++j;
	}

	if (p->next == NULL || j != pos)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	q = NULL;

	return OK;
}

Status CreateLinkListNoHNode(LinkList *L)
{	// 无头结点 尾插法s
	LNode *p, *rear;
	ElemType elem;

	p = (LNode *)malloc(sizeof(LNode));
	if (p == NULL)
	{
		return ERROR;
	}
	scanf("%d", &elem);
	p->data = elem;
	p->next = NULL;
	*L = p;
	rear = p;


	while (scanf("%d", &elem) != EOF)
	{
		p = (LNode *)malloc(sizeof(LNode));
		if (p == NULL)
		{
			return ERROR;
		}
		p->data = elem;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}


	return OK;
}

Status CreateLinkList(LinkList *LHead)
{	// 带头结点 尾插法
	LNode *p = NULL;
	LNode *rear= NULL;
	ElemType elem;

	p = (LNode *)malloc(sizeof(LNode));
	if (p == NULL)
	{
		return ERROR;
	}
	p->next = NULL;
	rear = p;
	*LHead = p;

	while (scanf("%d", &elem) != EOF)
	{
		p = (LNode *)malloc(sizeof(LNode));
		if (p == NULL)
		{
			return ERROR;
		}
		p->data = elem;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}

	return OK;
}

Status CreateCLinkList(LinkList *LHead)
{	// 创建循环链表
	LNode *p = NULL;
	LNode *rear = NULL;
	ElemType elem;

	p = (LNode *)malloc(sizeof(LNode));
	if (p == NULL)
	{
		return ERROR;
	}
	p->next = NULL;
	rear = p;
	*LHead = p;

	while (scanf("%d", &elem) != EOF)
	{
		p = (LNode *)malloc(sizeof(LNode));
		if (p == NULL)
		{
			return ERROR;
		}
		p->data = elem;
		p->next = NULL;
		rear->next = p;
		rear = p;
		rear->next = *LHead;
	}

	return OK;
}

void PrintLinkListNoHNode(LinkList L)
{	// 无头结点
	LNode *p = L;

	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

void PrintLinkList(LinkList LHead)
{
	LNode *p = LHead->next;

	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

void PrintCLinkList(LinkList LHead)
{	// 打印循环链表
	LNode *p = LHead->next;

	while (p != LHead)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

Status DestroyLinkList(LinkList *LHead)
{	// 带头结点，保留头结点
	LNode *q = *LHead;
	LNode *head = *LHead;
	LNode *p = q->next;
	
	while (p != NULL)
	{
		q->next = p->next;
		free(p);
		p = NULL;
		p = q->next;
	}
	head->next = NULL;
	free(*LHead);
	*LHead = NULL;
	
	return OK;
}

Status DestroyCLinkList(LinkList *LHead)
{
	LNode *q = *LHead;
	LNode *head = *LHead;
	LNode *p = q->next;

	while (p != *LHead && p != NULL)
	{
		q->next = p->next;
		free(p);
		p = NULL;
		p = q->next;
	}
	head->next = NULL;
	free(*LHead);
	*LHead = NULL;

	return OK;
}

int GetLinkListLength(LinkList L)
{	// 带头结点
	int len = 0;

	while (L->next != NULL)
	{
		len++;
		L = L->next;
	}

	return len;
}

