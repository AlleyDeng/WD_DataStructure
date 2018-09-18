#ifndef SQSTACK_H_
#define SQSTACK_H_

#include "Macro.h"

typedef struct SqStack
{
	ElemType data[MAXSIZE];
	int top;
} SqStack;

Status InitiateSqStack(SqStack *S);
Status Push(SqStack *S, ElemType e);
Status Pop(SqStack *S, ElemType *e);

#endif