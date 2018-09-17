#ifndef WD_CHAPTER_03_SQSTACK_H_
#define WD_CHAPTER_03_SQSTACK_H_

#include "LinkList.h"
#include "SqStack.h"

typedef struct SharingTheStack
{	// C3_1_T05_ 专用结构
	ElemType data[MAXSIZE];
	int top[2];
} SharingTheStack;

Status C3_1_T03_Judge(char A[]);
Status C3_1_T04_IsSymmetry(LinkList L);
Status C3_1_T05_Push(SharingTheStack *S, int i, ElemType e);
Status C3_1_T05_Pop(SharingTheStack *S, int i, ElemType *e);


#endif