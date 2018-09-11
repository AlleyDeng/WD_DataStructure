/*
 * WD_Chapter_02_LinkList.c
 *
 *  Created on: 2018年9月6日
 *      Author: deng_chao
 */

#include "LinkList.h"

 /**
  *	2.3.7 01:
  *	 要求：递归算法，删除不带头结点的单链表L中所有值为x的节点
  * */
void C2_3_T01_DelX(LinkList *L, ElemType x)
{	// 此处需要对指针L的值进行更改，所有采用二级指针
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
*	 要求：删除带头结点的单链表L中所有值为x的节点
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
	要求：从尾到头反向输出带头结点单链表的每个结点的值
	思路：采用递归入栈的方法
*/
void C2_3_T03_InvertedPrintList(LinkList L)
{	// 带头结点
	if (L->next == NULL)
	{
		return;
	}

	C2_3_T03_InvertedPrintList(L->next);
	printf("%d\t", L->next->data);
}

/*
	2.3.7 04
	要求：删除带结点链表的最小值结点
*/
void C2_3_T04_DelMinNode(LinkList L)
{
	LNode *p = L->next, *minNode = p;
	LNode *pre = L, *minPre = pre;
	//分别用minNode和minPre记录最小值结点和最小值结点的前驱

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
	要求：将带头结点的链表在空间复杂度为O(1)的情况下逆置
	思路：将链表结点依次插入在头结点后面
		 (或者用三个指针域分别为pre、p、r=p->next遍历链表)
*/
LinkList C2_3_T05_ReverseLinkList(LinkList L)
{
	// 思路一
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

	// 思路二
	LNode *head = L;
	LNode *pre = L;
	LNode *p = L->next;
	LNode *r = p->next;

	p->next = NULL;
	while (r != NULL)
	{	// r为NULL时，表示p为最后一个结点
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
	要求：使链表递增有序
	思路：直接插入排序
*/
LinkList C2_3_T06_SortList(LinkList L)
{
	LNode *head = L;
	LNode *p = L->next;
	LNode *r = p->next;
	LNode *pre;				// 待插入位置前驱结点
	p->next = NULL;			// 待插入链表初始状态下只有一个结点
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = head;
		while (pre->next != NULL && pre->next->data < p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;	// 将p结点插入到pre之后
		pre->next = p;
		p = r;
	}

	return head;
}

/*
	2.3.7 07
	要求：删除无序带头结点链表中元素值处于floor和root直接的元素
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
	要求：找出两个链表的公共结点
	思路：两链表公共结点后的部分相同，求出两链表的长度差dist，
	让长链表先向后遍历dist个结点后，共同遍历，知道找到相同结点
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
	要求：按递增次序输出单链表中各结点的数据元素，并释放结点所占存储空间
	不可使用数组作为辅助空间，链表带头结点
	思路：依次遍历选出最小值结点打印并删除
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
			{	// 搜索最小值结点
				minPre = pre;
				minNode = p;
			}
			pre = p;
			p = p->next;
		}
		minPre->next = minNode->next;	// 删除结点并打印数值
		printf("%d\t", minNode->data);
		free(minNode);
		pre = L;						// 回到链表首，重新扫描
		p = L->next;
		minNode = p;
		minPre = pre;
	}
}

/*
	2.3.7 10:
	要求：将带有头结点的链表A分解为两个带有头结点的单链表A和B，其中A
	表中含有原表中序号为奇数的元素结点，B表中含有原表中序号偶数元素结
	点，且保持原有相对顺序不变
	思路：逐一遍历，尾插法（保持原有相对顺序不变）
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
		{	// 序列为奇数
			rearA->next = p;
			rearA = p;
		}
		else
		{	// 序列为偶数
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
	要求：C(a1, b1, a2, b2, ...... , an, bn)
		-------> A(a1, a2, ...... , an), B(bn, ...... b2, b1)
	思路：逐一遍历，B链表采用头插法逆序
*/
LinkList C2_3_T11_ListSepaParity(LinkList A)
{
	LinkList B = (LinkList)malloc(sizeof(LNode));
	LNode *p = A->next, *q;
	LNode *rearA = A;
	A->next = NULL;
	B->next = NULL;

	while (p != NULL)
	{	// 一次向后遍历两个，第一个头插至A，第二个头插至B
		rearA->next = p;		// 尾插至Ａ
		rearA = p;

		p = p->next;			// 向后一位
		q = p->next;			// 头插时断链，q保存p后继

		p->next = B->next;		// 头插至B
		B->next = p;

		p = q;
	}
	rearA->next = NULL;

	return B;
}

/*
	2.3.7 12:
	要求：递增序的链表中，删除其相同的元素（我默认带头结点）
	思路：遍历链表，若结点的后继结点与结点元素值相等，则删除后继结点
*/
void C2_3_T12_ListDelSameElem(LinkList L)
{
	LNode *p = L->next;
	LNode *q;

	if (p == NULL)
	{
		return;
	}
	while (p->next != NULL)
	{
		q = p->next;
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
			q = NULL;
		}
		else
		{
			p = p->next;
		}
	}
}

/*
	2.3.7 13:
	要求：将两个按元素递增排序的单链表，将这两个单链表归并为一个按元素值
	递减排序的单链表，要求用原来两个链表的结点存放归并后的单链表
	思路：头插法，归并
*/
void C2_3_T13_MergeList(LinkList L1, LinkList L2)
{
	LNode *p1 = L1->next;
	LNode *p2 = L2->next;
	LNode *q, *l = L1;		// l指向新链表的头结点
	l->next = NULL;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			q = p1->next;
			p1->next = l->next;
			l->next = p1;
			p1 = q;
		}
		else
		{
			q = p2->next;
			p2->next = l->next;
			l->next = p2;
			p2 = q;
		}
	}
	while (p1 != NULL)
	{
		q = p1->next;
		p1->next = l->next;
		l->next = p1;
		p1 = q;
	}
	while (p2 != NULL)
	{
		q = p2->next;
		p2->next = l->next;
		l->next = p2;
		p2 = q;
	}
	L1->next = l->next;
	L2->next = l->next;
}

/*
	2.3.7 14:
	要求：从两个递增有序的两个链表中，创建新的链表，要求不能破坏原链表
	思路：分别遍历，若相等则创建结点插入新链表之后，若不相等，则元素值
	小的向后移一个位置。
*/
LinkList C2_3_T14_CreateCommElemList(LinkList L1, LinkList L2)
{
	LNode *p1 = L1->next;
	LNode *p2 = L2->next;
	LinkList retLinkList = (LinkList)malloc(sizeof(LNode));
	LNode *rear;
	retLinkList->next = NULL;
	rear = retLinkList;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			p1 = p1->next;
		}
		else if (p2->data < p1->data)
		{
			p2 = p2->next;
		}
		else
		{
			LNode *newNode = (LNode *)malloc(sizeof(LNode));
			newNode->next = NULL;
			newNode->data = p1->data;
			rear->next = newNode;
			rear = newNode;
			p1 = p1->next;
			p2 = p2->next;
		}
	}

	return retLinkList;
}

/*
	2.3.7 15:
	要求：链表L1、L2表示连个递增集合，求L1、L2的交集，并存放于L1
	思路：采用归并思想。两集合相同的元素保留，其他全部释放
*/
LinkList C2_3_T15_SetIntersection(LinkList L1, LinkList L2)
{
	LNode *p1 = L1->next;
	LNode *p2 = L2->next;
	LNode *rear = L1, *q;
	L1->next = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			q = p1;
			p1 = p1->next;
			free(q);
			q = NULL;
		}
		else if (p2->data < p1->data)
		{
			q = p2;
			p2 = p2->next;
			free(q);
			q = NULL;
		}
		else
		{	// 元素相等，交集
			q = p1->next;		// L1中结点保存
			rear->next = p1;
			p1->next = NULL;
			rear = p1;
			p1 = q;
		
			q = p2;				// L2中结点释放
			p2 = p2->next;
			free(q);			// q释放之后，与链表不再有联系，q=NULL不会给p2赋值，
			q = NULL;			// p2仍为野指针
		}
	}

	while (p1 != NULL)
	{
		q = p1;
		p1 = p1->next;
		free(q);
		q = NULL;
	}

	while (p2 != NULL)
	{
		q = p2;
		p2 = p2->next;
		free(q);
		q = NULL;
	}
	L2->next = NULL;
	return L1;
}

/*
	2.3.7 16:
	要求：判断LSub序列是否是LSrc的子序列
	思路：两层嵌套循环遍历
*/
Status C2_3_T16_IsSubSequence(LinkList LSrc, LinkList LSub)
{
	LNode *p = LSrc->next;
	LNode *pre = p;
	LNode *q = LSub->next;
	
	while (p != NULL && q != NULL)
	{
		if (p->data == q->data)
		{
			p = p->next;
			q = q->next;
		}
		else
		{
			pre = pre->next;
			p = pre;
			q = LSub->next;
		}
	}

	if (q == NULL)
	{	// 子列遍历到尾端
		return OK;
	}
	else
	{
		return ERROR;
	}
}