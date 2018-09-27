#include "WD_Chapter_03_UseStkAndQue.h"

/*
	3.3.6 01:
	要求：字符串中三种类型括号，判断是否配对
	思路：左括号入栈，右括号出栈并判断出栈括号是否为对应左括号
*/
Status C3_3_T01_MatchBracket(char A[])
{
	SqStack S;
	ElemType e;
	int i;
	InitiateSqStack(&S);

	for (i = 0; A[i] != '\0'; i++)
	{
		if (A[i] == '(' || A[i] == '[' || A[i] == '{')
		{	// 左括号入栈
			Push(&S, A[i]);
		}
		else
		{	// 右括号，栈顶元素出栈，并判断是否匹配s
			switch (A[i])
			{
			case ')':
				Pop(&S, &e);
				if (e != '(')
				{
					return ERROR;
				}
				break;
			case ']':
				Pop(&S, &e);
				if (e != '[')
				{
					return ERROR;
				}
				break;
			case '}':
				Pop(&S, &e);
				if (e != '{')
				{
					return  ERROR;
				}
				break;
			default:
				return ERROR;
				break;
			}
		}
	}

	if (S.top == -1)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/*
	3.3.6 02:
	要求：火车调度站两侧均为单向行驶道，火车调度站有一个用于调度的栈道，
	火车调度站入口处有n节硬座和软座车厢，（分别以H和S表示）等待调度，以
	使所有软座车厢都调度到硬座车厢前面
	思路：逐一检查，硬座车厢入栈
*/
//void C3_3_T02_DispatchTrain(char *trainSeq)
//{
//	int i = 0;	// 用于遍历	
//	int j = 0;
//	SqStack S;
//	InitiateSqStack(&S);
//	while (trainSeq[i] != '\0')
//	{
//		if (trainSeq[i] == 'H')
//		{	// 'H'表示硬座,'S'表示软座
//			Push(&S, trainSeq[i]);
//		}
//		else
//		{
//			trainSeq[j++] = trainSeq[i];
//		}
//		i++;
//	}
//
//	while (S.top != -1)
//	{
//		Pop(&S, &trainSeq[j++]);
//	}
//}

/**************************************************************
***************************************************************
*************************** 回头再看 ***************************
***************************************************************
***************************************************************/
// 不想看这种类型题，脑阔痛, 错误超级多啊
/*
	3.3.6 03：
	要求：使用栈实现递归函数的非递归运算
	Pn(x) = 1,						n = 0;
			2x,						n = 1;
			2xPn(x)-2(n-1)Pn-2(x),	n > 1.
*/

//double C3_3_T03_RecursionByStack(int n, double x)
//{	
//	struct stack
//	{
//		int no;
//		double val;
//	} st[MAXSIZE];
//	int top = -1, i;
//	double fv1 = 1;
//	double fv2 = 2 * x;
//	
//	if (n == 0)
//	{
//		return fv1;
//	}
//	for (i = n; i >= 2; i--)
//	{
//		top++;
//		st[top].no = i;
//	}
//	while (top != -1)
//	{
//		st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
//		fv1 = fv2;
//		fv2 = st[top].val;
//		top--;
//	}
//	
//
//	return fv2;
//}

/*
	3.3.6 04:
	要求：某汽车轮渡口，过江渡轮每次能载10辆车过江，车辆分为客车类和火车类，
	规定：同类车先到先上船，客车先于货车上船，且每上4辆客车在允许上一辆货车，
	若等待客车不足四辆，则以货车替代，若无货车等待，允许客车都上船
	思路：队列
*/
//void C3_3_T04_ManageFerry(SqQueue QTrucks,	SqQueue QCoach)
//{
//	int i = 0; 
//	int j = 0;
//	SqQueue Q;
//	ElemType e;
//
//	InitiateSqQueue(&Q);
//	//InitiateSqQueue(&QTrucks);
//	//InitiateSqQueue(&QCoach);
//	
//	// j表示渡船上的总车辆数(不超过10辆)
//	while (j < 10)
//	{
//		if (IsQueueEmpty(QCoach) == OK && i < 4)
//		{
//			DeQueue(&QCoach, &e);
//			EnQueue(&Q, e);
//			i++;		// 上船客车数加1
//			j++;
//		}
//		else if (i == 4 && IsQueueEmpty(QTrucks) == OK)
//		{
//			DeQueue(&QTrucks, &e);
//			EnQueue(&Q, e);
//			j++;
//			i = 0;
//		}
//		else
//		{	// 客车队列或者货车队列为空
//			while (j < 10 && i < 4 && IsQueueEmpty(QTrucks) == OK)
//			{	// 客车队列为空
//				DeQueue(&QTrucks, &e);
//				EnQueue(&Q, e);
//				i++;
//				j++;
//			}
//			i = 0;
//		}
//		if (IsQueueEmpty(QCoach) && IsQueueEmpty(QTrucks))
//		{	// 客车数量和货车数量加起来不足10辆
//			j = 10;
//		}
//	}
//}

/**************************************************************
***************************************************************
*************************** 回头再看 ***************************
***************************************************************
***************************************************************/