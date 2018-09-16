#include "WD_Chapter_03_SqStack.h"

/*
	3.1.4 03：
	要求：判定存放在数组里面的序列是否合法。I、O分别表示入栈和出栈，栈的初始状态和
	终态均为空，用IO序列表示出栈和入栈操作，若可以操作的序列称为合法
	思路：设置变量top，初始为0，若操作过程中，出现top小于零则表示为不合法操作，操作
	完成后若top不等于0，则表示不合法
*/
Status C3_1_T03_Judge(char A[])
{
	int top = 0;
	int i = 0;

	for (i = 0; A[i] != '\0'; i++)
	{
		if (A[i] == 'I')
		{
			++top;
		}
		else
		{
			if (top == 0)
			{
				return ERROR;
			}
			else
			{
				--top;
			}
		}
	}

	if (top != 0)
	{
		return ERROR;
	}

	return OK;
}

/*
	3.1.4 04:
	要求：判断链表数据域是否中心对称，题目要求数据元素类型为char，此处仍使用int型
	思路：将前半段链表入栈，分别对栈依次出栈，链表后半段依次遍历，判断出栈元素与链
	表后半段元素值是否相等
*/
Status C3_1_T04_IsSymmetry(LinkList L)
{
	int i = 0;
	ElemType elem;
	SqStack S;
	int len = GetLinkListLength(L);
	LNode *p = L->next;
	Intiate(&S);
	for (i = 0; i < len / 2; i++)
	{
		Push(&S, p->data);
		p = p->next;
	}

	if ((len & 0x01) != 0)
	{
		p = p->next;
	}

	while (p != NULL && p->data == S.data[S.top])
	{
		p = p->next;
		Pop(&S, &elem);
	}

	if (p != NULL || S.top != -1)
	{
		return ERROR;
	}

	return OK;
}


/*
	3.1.5 05:
	要求：两个栈都采用顺序存储的形式，共享存储在一个大小MAXSIZE的存储区
	思路：将两个栈的栈底设在向量的两端，初始时，左边栈顶为-1，右边栈顶为
	MAXSIZE。两个栈顶指针相邻时为栈满。
*/
Status C3_1_T05_Push(SharingTheStack s,  int i, ElemType e)
{
	if (i < 0 || i > 1)
	{
		return ERROR;
	}
	if (s.top[1] - s.top[0] == 1)
	{
		return ERROR;
	}

	switch (i)
	{
	case 0: 
		s.data[++s.top[0]] = e;
		break;
	case 1:
		s.data[--s.top[1]] = e;
		break;
	default:
		return ERROR;
	}

	return OK;
}

Status C3_1_T05_Pop(SharingTheStack s, int i, ElemType *e)
{
	if (i < 0 || i > 1)
	{
		return ERROR;
	}

	switch (i)
	{
	case 0:
		if (s.top[0] == -1)
		{
			return ERROR;
		}
		*e = s.data[s.top[0]--];
		break;
	case 1:
		if (s.top[1] == MAXSIZE)
		{
			return ERROR;
		}
		*e = s.data[s.top[1]++];
	}

	return OK;
}