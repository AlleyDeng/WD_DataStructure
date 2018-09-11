/*
* LinkList.c
*
*  Created on: 2018��9��2��
*      Author: deng_chao
*/

#include "LinkList.h"

Status GetLinkListElem(LinkList LHead, int pos, ElemType *e)
{	// ��ͷ���
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
{	// ��ͷ��� β�巨s
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
{	// ��ͷ��� β�巨
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

void PrintLinkListNoHNode(LinkList L)
{	// ��ͷ���
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

Status DestroyLinkList(LinkList LHead)
{	// ��ͷ��㣬����ͷ���
	LNode *q = LHead;
	LNode *p = q->next;
	
	while (p != NULL)
	{
		q->next = p->next;
		free(p);
		p = NULL;
		p = q->next;
	}
	LHead->next = NULL;

	return OK;
}

int GetLinkListLength(LinkList L)
{	// ��ͷ���
	int len = 0;

	while (L->next != NULL)
	{
		len++;
		L = L->next;
	}

	return len;
}