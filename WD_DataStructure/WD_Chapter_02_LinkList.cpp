/*
 * WD_Chapter_02_LinkList.c
 *
 *  Created on: 2018��9��6��
 *      Author: deng_chao
 */

#include "LinkList.h"

/**
 *	2.3.7 01:
 *	 Ҫ�󣺵ݹ��㷨��ɾ������ͷ���ĵ�����L������ֵΪx�Ľڵ�
 * */
void C2_3_T01_DelX(LinkList *L, ElemType x)
{	// �˴���Ҫ��ָ��L��ֵ���и��ģ����в��ö���ָ��
	LNode *p;
	
	if (*L == NULL)
	{
		return;
	}

	if ((*L)->data == x)
	{
		p = *L;
		*L = (*L)->next;
		free(p);
		p = NULL;
		C2_3_T01_DelX(L, x);
	}
	else
	{
		C2_3_T01_DelX(&(*L)->next, x);
	}
}

/**
*	2.3.7 02:
*	 Ҫ��ɾ����ͷ���ĵ�����L������ֵΪx�Ľڵ�
* */
void C2_3_T02_DelX(LinkList L, ElemType x)
{
	LNode *p = L->next;
	LNode *pre = L;
	LNode *q = NULL;
	while (p != NULL)
	{
		if (p->data == x)
		{
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
			q = NULL;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

/*
	2.3.7 03
	Ҫ�󣺴�β��ͷ���������ͷ��㵥�����ÿ������ֵ
	˼·�����õݹ���ջ�ķ���
*/
void C2_3_T03_InvertedPrintList(LinkList L)
{	// ��ͷ���
	if (L->next == NULL)
	{
		return;
	}

	C2_3_T03_InvertedPrintList(L->next);
	printf("%d\t", L->next->data);
}

/*
	2.3.7 04
	Ҫ��ɾ��������������Сֵ���
*/
void C2_3_T04_DelMinNode(LinkList L)
{
	LNode *p = L->next, *minNode = p;
	LNode *pre = L, *minPre = pre;
	//�ֱ���minNode��minPre��¼��Сֵ������Сֵ����ǰ��

	while (p != NULL)
	{
		if (p->data < minNode->data)
		{
			minPre = pre;
			minNode = p;
		}
		pre = p;
		p = p->next;
	}

	minPre->next = minNode->next;
	free(minNode);
	minNode = NULL;
}

/*
	2.3.7 05
	Ҫ�󣺽���ͷ���������ڿռ临�Ӷ�ΪO(1)�����������
	˼·�������������β�����ͷ������
         (����������ָ����ֱ�Ϊpre��p��r=p->next��������)
*/
LinkList C2_3_T05_ReverseLinkList(LinkList L)
{
	// ˼·һ
	/*LNode *head = L;
	LNode *q, *p = L->next;
	head->next = NULL;

	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}

	return head;*/

	// ˼·��
	LNode *head = L;
	LNode *pre = L;
	LNode *p = L->next;
	LNode *r = p->next;

	p->next = NULL;
	while (r != NULL)
	{	// rΪNULLʱ����ʾpΪ���һ�����
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}

	head->next = p;

	return head;
}

/*
	2.3.7 06
	Ҫ��ʹ�����������
	˼·��ֱ�Ӳ�������
*/
LinkList C2_3_T06_SortList(LinkList L)
{
	LNode *head = L;
	LNode *p = L->next;
	LNode *r = p->next;
	LNode *pre;				// ������λ��ǰ�����
	p->next = NULL;			// �����������ʼ״̬��ֻ��һ�����
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = head;
		while (pre->next != NULL && pre->next->data < p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;	// ��p�����뵽pre֮��
		pre->next = p;
		p = r;
	}

	return head;
}

/*
	2.3.7 07
	Ҫ��ɾ�������ͷ���������Ԫ��ֵ����floor��rootֱ�ӵ�Ԫ��
*/
void C2_3_T07_DelRange(LinkList L, ElemType floor, ElemType root)
{
	LNode *pre = L;
	LNode *p = L->next;

	while (p != NULL)
	{
		if (p->data > floor && p->data < root)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

/*
	2.3.7 08:
	Ҫ���ҳ���������Ĺ������
	˼·��������������Ĳ�����ͬ�����������ĳ��Ȳ�dist��
	�ó�������������dist�����󣬹�ͬ������֪���ҵ���ͬ���
*/
LinkList C2_3_T08_SearchCommonNode(LinkList L1, LinkList L2)
{
	LinkList shortList, longList;
	int len1 = GetLinkListLength(L1);
	int len2 = GetLinkListLength(L2);
	int dist = len1 > len2 ? len1 - len2 : len2 - len1;
	shortList = len1 > len2 ? L2 : L1;
	longList = len1 > len2 ? L1 : L2;

	while (dist-- > 0)
	{
		longList = longList->next;
	}

	while (longList->next != NULL && shortList->next != NULL)
	{
		if (longList->data != shortList->data)
		{
			longList = longList->next;
			shortList = shortList->next;
		}
		else
		{
			return longList;
		}
	}


	return NULL;
}

/*
	2.3.7 09:
	Ҫ�󣺰�������������������и���������Ԫ�أ����ͷŽ����ռ�洢�ռ�
	����ʹ��������Ϊ�����ռ䣬�����ͷ���
	˼·�����α���ѡ����Сֵ����ӡ��ɾ��
*/
void C2_3_T09_DelMinWhole(LinkList L)
{
	LNode *pre = L;
	LNode *p = L->next;
	LNode *minPre = pre, *minNode = p;

	while (L->next != NULL)
	{
		while (p != NULL)
		{
			if (minNode->data > p->data)
			{	// ������Сֵ���
				minPre = pre;
				minNode = p;
			}
			pre = p;
			p = p->next;
		}
		minPre->next = minNode->next;	// ɾ����㲢��ӡ��ֵ
		printf("%d\t", minNode->data);
		free(minNode);
		pre = L;						// �ص������ף�����ɨ��
		p = L->next;
		minNode = p;
		minPre = pre;
	}
}

/*
	2.3.7 10:
	Ҫ�󣺽�����ͷ��������A�ֽ�Ϊ��������ͷ���ĵ�����A��B������A
	���к���ԭ�������Ϊ������Ԫ�ؽ�㣬B���к���ԭ�������ż��Ԫ�ؽ�
	�㣬�ұ���ԭ�����˳�򲻱�
	˼·����һ������β�巨������ԭ�����˳�򲻱䣩
*/
LinkList C2_3_T10_ListSepaParity(LinkList A)
{
	LinkList B = (LinkList)malloc(sizeof(LNode));
	LNode *p = A->next;
	LNode *rearA = A;
	LNode *rearB = B;
	int j = 0;
	A->next = NULL;
	B->next = NULL;

	while (p != NULL)
	{
		j++;
		if ((j & 0x0001) != 0)
		{	// ����Ϊ����
			rearA->next = p;
			rearA = p;
		}
		else
		{	// ����Ϊż��
			rearB->next = p;
			rearB = p;
		}
		p = p->next;
	}
	rearA->next = NULL;
	rearB->next = NULL;

	return B;
}

/*
	2.3.7 11:
	Ҫ��C(a1, b1, a2, b2, ...... , an, bn) 
		-------> A(a1, a2, ...... , an), B(bn, ...... b2, b1)
	˼·����һ������B�������ͷ�巨����
*/
LinkList C2_3_T11_ListSepaParity(LinkList A)
{
	LinkList B = (LinkList)malloc(sizeof(LNode));
	LNode *p = A->next, *q;
	LNode *rearA = A;
	A->next = NULL;
	B->next = NULL;

	while (p != NULL)
	{	// һ����������������һ��ͷ����A���ڶ���ͷ����B
		rearA->next = p;		// β������
		rearA = p;

		p = p->next;			// ���һλ
		q = p->next;			// ͷ��ʱ������q����p���
		
		p->next = B->next;		// ͷ����B
		B->next = p;
		
		p = q;
	}
	rearA->next = NULL;

	return B;
}
