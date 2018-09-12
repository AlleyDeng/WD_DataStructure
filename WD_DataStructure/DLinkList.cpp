#include "DLinkList.h"

Status CreateCDLinkList(DLinkList *LHead)
{	// 创建循环双链表
	ElemType elem;
	DLNode *newNode;
	DLNode *p = NULL;

	p = (DLinkList)malloc(sizeof(DLNode));
	if (p == NULL)
	{
		return ERROR;
	}
	p->next = p;
	p->prior = p;
	*LHead = p;
	while (scanf("%d", &elem) != EOF)
	{
		newNode = (DLNode *)malloc(sizeof(DLNode));
		if (newNode == NULL)
		{
			return ERROR;
		}
		newNode->data = elem;

		newNode->next = p;
		newNode->prior = p->prior;
		p->prior->next = newNode;
		p->prior = newNode;
	}

	return OK;
}

Status DestroyDLinkList(DLinkList *LHead)
{
	DLNode *q, *lNode = *LHead;
	DLNode *p = lNode->next;
	while (p != lNode && p != NULL)
	{
		q = p->next;

		p->prior->next = p->next;
		p->next->prior = p->prior;

		free(p);
		p = NULL;
		p = q;
	}
	free(*LHead);
	*LHead = NULL;

	return OK;
}

int GetDLinkListLength(DLinkList LHead)
{
	DLNode *p = LHead->next;
	int len = 0;

	while (p != LHead)
	{
		len++;
		p = p->next;
	}

	return len;
}

void PrintDLinkList(DLinkList LHead)
{
	DLNode *p = LHead->next;

	while (p != LHead)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}