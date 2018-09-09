/*
 * List
 *
 *  Created on: 2018Äê9ÔÂ2ÈÕ
 *      Author: deng_chao
 */

#ifndef SQLIST_H_
#define SQLIST_H_

#include "Macro.h"

#define MAXSIZE	10

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqList;

Status GetSqListElem(SqList L, int i, ElemType *e);
Status SqListInsert(SqList *L, int pos, ElemType e);
Status SqListDelete(SqList *L, int pos, ElemType *e);


#endif /* SQLIST_H_ */
