#include "SqStack.h"

Status InitiateSqStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

Status Push(SqStack *S, ElemType e)
{
	if (S->top == MAXSIZE)
	{
		return ERROR;
	}

	S->top++;
	S->data[S->top] = e;

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

