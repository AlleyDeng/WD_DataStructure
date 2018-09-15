#ifndef SQSTAKC_H_
#define SQSTACK_H_

#include "Macro.h"

typedef struct SqStackNode
{
	ElemType data[MAXSIZE];
	int top;
} SqStack;

Status Intiate(SqStack *S);
Status Push(SqStack *S, ElemType e);
Status Pop(SqStack *S, ElemType *e);








#endif