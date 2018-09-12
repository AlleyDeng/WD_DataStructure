/*
 * LinkList.h
 *
 *  Created on: 2018Äê9ÔÂ2ÈÕ
 *      Author: deng_chao
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "Macro.h"

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

Status GetLinkListElem(LinkList L, int pos, ElemType *e);
Status LinkListInsert(LinkList LHead, int pos, ElemType e);
Status LinkListDelete(LinkList LHead, int pos, ElemType *e);
Status CreateLinkListNoHNode(LinkList *L);
Status CreateLinkList(LinkList *LHead);
Status CreateCLinkList(LinkList *LHead);
Status DestroyLinkList(LinkList *LHead);
Status DestroyCLinkList(LinkList *LHead);
void PrintLinkListNoHNode(LinkList L);
void PrintLinkList(LinkList LHead);
void PrintCLinkList(LinkList LHead);
int GetLinkListLength(LinkList L);

#endif /* LINKLIST_H_ */
