#include "WD_Chapter_03_SqQueue.h"


/*
	3.2.5 01:
	Ҫ�����ñ�־��tag�ж϶����������߿գ���֤ѭ�����������е�λ�ö�
	��������
*/
Status C_3_2_T01_EnQueue(SqQueue Q, ElemType e)
{
	if (Q.front == Q.rear && Q.tag == 1)
	{
		return ERROR;
	}

	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.tag = 1;	// ���ܶ���

	return OK;
}

Status C_3_2_T01_DeQueue(SqQueue Q, ElemType *e)
{	
	if (Q.front == Q.rear && Q.tag == 0)
	{
		return ERROR;
	}

	*e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.tag = 0;	// ���ܶԿ�
	return OK;
}

/*
	3.2.5 02:
	Ҫ��Q��һ�����У�����һ����ջ���ѵ�Ԫ������
*/
void C_3_2_T02_Reverse(SqQueue Q)
{

}