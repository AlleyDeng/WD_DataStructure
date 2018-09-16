#include "WD_Chapter_03_SqQueue.h"


/*
	3.2.5 01:
	要求：设置标志域，tag判断队列是满或者空，保证循环队列中所有的位置都
	可以利用
*/
Status C_3_2_T01_EnQueue(SqQueue Q, ElemType e)
{
	if (Q.front == Q.rear && Q.tag == 1)
	{
		return ERROR;
	}

	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.tag = 1;	// 可能对满

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
	Q.tag = 0;	// 队能对空
	return OK;
}

/*
	3.2.5 02:
	要求：Q是一个队列，利用一个空栈将Ｑ的元素逆置
*/
void C_3_2_T02_Reverse(SqQueue Q)
{

}