#include "WD_Chapter_03_SqQueue.h"


/*
	3.2.5 01:
	要求：设置标志域，tag判断队列是满或者空，保证循环队列中所有的位置都
	可以利用
*/
Status C_3_2_T01_EnQueue(SqQueue *Q, ElemType e)
{
	if (Q->front == Q->rear && Q->tag == 1)
	{
		return ERROR;
	}

	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	Q->tag = 1;	// 可能对满

	return OK;
}

Status C_3_2_T01_DeQueue(SqQueue *Q, ElemType *e)
{	
	if (Q->front == Q->rear && Q->tag == 0)
	{
		return ERROR;
	}

	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	Q->tag = 0;	// 队能对空
	return OK;
}

/*
	3.2.5 02:
	要求：Q是一个队列，利用一个空栈将Ｑ的元素逆置
*/
void C_3_2_T02_Reverse(SqQueue *Q)
{
	SqStack S;
	ElemType e;
	InitiateSqStack(&S);
	if (Q->rear == Q->front)
	{
		return;
	}

	while (Q->rear != Q->front)
	{
		DeQueue(Q, &e);
		Push(&S, e);
	}

	while (S.top != -1)
	{
		Pop(&S, &e);
		EnQueue(Q, e);
	}
}

/*
	3.2.5 03
	要求：使用两个栈模拟一个队列
*/
Status C_3_T03_EnQueue(SqStack *S1, SqStack *S2, ElemType e)
{	
	ElemType tempE;
	if (S1->top != MAXSIZE)
	{
		Push(S1, e);
		return OK;
	}
	else if (S1->top == MAXSIZE && S2->top != -1)
	{	// S1 满，S2非空，栈满
		return ERROR;
	}
	else /*if (S1->top == MAXSIZE && S2->top == -1)*/
	{
		while (S1->top != -1)
		{
			Pop(S1, &tempE);
			Push(S2, tempE);
		}
		Push(S1, e);
	}

	return OK;
}

Status C_3_T03_DeQueue(SqStack *S1, SqStack *S2, ElemType *e)
{
	ElemType tempE;
	if (S2->top != -1)
	{
		Pop(S2, e);
		return OK;
	}
	else if (S1->top == -1 && S2->top == -1)
	{	// S1为空且S2为空，栈空
		return ERROR;
	}
	else /*if (S1->top != -1 && S2->top == -1)*/
	{
		while (S1->top != -1)
		{
			Pop(S1, &tempE);
			Push(S2, tempE);
		}
		Pop(S2, e);
	}



	return OK;
}