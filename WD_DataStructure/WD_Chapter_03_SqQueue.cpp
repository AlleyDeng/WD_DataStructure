#include "WD_Chapter_03_SqQueue.h"


/*
	3.2.5 01:
	Ҫ�����ñ�־��tag�ж϶����������߿գ���֤ѭ�����������е�λ�ö�
	��������
*/
Status C_3_2_T01_EnQueue(SqQueue *Q, ElemType e)
{
	if (Q->front == Q->rear && Q->tag == 1)
	{
		return ERROR;
	}

	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	Q->tag = 1;	// ���ܶ���

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
	Q->tag = 0;	// ���ܶԿ�
	return OK;
}

/*
	3.2.5 02:
	Ҫ��Q��һ�����У�����һ����ջ���ѵ�Ԫ������
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
	Ҫ��ʹ������ջģ��һ������
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
	{	// S1 ����S2�ǿգ�ջ��
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
	{	// S1Ϊ����S2Ϊ�գ�ջ��
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