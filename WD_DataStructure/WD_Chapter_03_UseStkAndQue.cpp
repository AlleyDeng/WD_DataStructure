#include "WD_Chapter_03_UseStkAndQue.h"

/*
	3.3.6 01:
	Ҫ���ַ����������������ţ��ж��Ƿ����
	˼·����������ջ�������ų�ջ���жϳ�ջ�����Ƿ�Ϊ��Ӧ������
*/
Status C_3_3_T01_MatchBracket(char A[])
{
	SqStack S;
	ElemType e;
	int i;
	InitiateSqStack(&S);

	for (i = 0; A[i] != '\0'; i++)
	{
		if (A[i] == '(' || A[i] == '[' || A[i] == '{')
		{	// ��������ջ
			Push(&S, A[i]);
		}
		else
		{	// �����ţ�ջ��Ԫ�س�ջ�����ж��Ƿ�ƥ��s
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
	Ҫ�󣺻𳵵���վ�����Ϊ������ʻ�����𳵵���վ��һ�����ڵ��ȵ�ջ����
	�𳵵���վ��ڴ���n��Ӳ�����������ᣬ���ֱ���H��S��ʾ���ȴ����ȣ���
	ʹ�����������ᶼ���ȵ�Ӳ������ǰ��
	˼·����һ��飬Ӳ��������ջ
*/
//void C_3_3_T02_DispatchTrain(char *trainSeq)
//{
//	int i = 0;	// ���ڱ���	
//	int j = 0;
//	SqStack S;
//	InitiateSqStack(&S);
//	while (trainSeq[i] != '\0')
//	{
//		if (trainSeq[i] == 'H')
//		{	// 'H'��ʾӲ��,'S'��ʾ����
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
*************************** ��ͷ�ٿ� ***************************
***************************************************************
***************************************************************/
// ���뿴���������⣬����ʹ, ���󳬼��డ
/*
	3.3.6 03��
	Ҫ��ʹ��ջʵ�ֵݹ麯���ķǵݹ�����
	Pn(x) = 1,						n = 0;
			2x,						n = 1;
			2xPn(x)-2(n-1)Pn-2(x),	n > 1.
*/

//double C_3_3_T03_RecursionByStack(int n, double x)
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
	Ҫ��ĳ�����ֶɿڣ���������ÿ������10����������������Ϊ�ͳ���ͻ��࣬
	�涨��ͬ�೵�ȵ����ϴ����ͳ����ڻ����ϴ�����ÿ��4���ͳ���������һ��������
	���ȴ��ͳ��������������Ի�����������޻����ȴ�������ͳ����ϴ�
	˼·������
*/
//void C_3_3_T04_ManageFerry(SqQueue QTrucks,	SqQueue QCoach)
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
//	// j��ʾ�ɴ��ϵ��ܳ�����(������10��)
//	while (j < 10)
//	{
//		if (IsQueueEmpty(QCoach) == OK && i < 4)
//		{
//			DeQueue(&QCoach, &e);
//			EnQueue(&Q, e);
//			i++;		// �ϴ��ͳ�����1
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
//		{	// �ͳ����л��߻�������Ϊ��
//			while (j < 10 && i < 4 && IsQueueEmpty(QTrucks) == OK)
//			{	// �ͳ�����Ϊ��
//				DeQueue(&QTrucks, &e);
//				EnQueue(&Q, e);
//				i++;
//				j++;
//			}
//			i = 0;
//		}
//		if (IsQueueEmpty(QCoach) && IsQueueEmpty(QTrucks))
//		{	// �ͳ������ͻ�����������������10��
//			j = 10;
//		}
//	}
//}

/**************************************************************
***************************************************************
*************************** ��ͷ�ٿ� ***************************
***************************************************************
***************************************************************/