#include "SqStack.h"

Status Intiate(SqStack *S)
{
	int i;
	S->top = -1;
	return OK;
}

Status Push(SqStack *S, ElemType e)
{
	if (S->top == MAXSIZE)
	{
		return ERROR;
	}

	S->data[++(S->top)] = e;

	return OK;
}

Status Pop(SqStack *S, ElemType *e)
{
	if (S->top == -1)
	{
		return ERROR;
	}

	*e = S->data[S->top--];

	return OK;
}

