#include "WD_Chapter_03_SqStack.h"

/*
	3.1.4 03��
	Ҫ���ж��������������������Ƿ�Ϸ���I��O�ֱ��ʾ��ջ�ͳ�ջ��ջ�ĳ�ʼ״̬��
	��̬��Ϊ�գ���IO���б�ʾ��ջ����ջ�����������Բ��������г�Ϊ�Ϸ�
	˼·�����ñ���top����ʼΪ0�������������У�����topС�������ʾΪ���Ϸ�����������
	��ɺ���top������0�����ʾ���Ϸ�
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
	Ҫ���ж������������Ƿ����ĶԳƣ���ĿҪ������Ԫ������Ϊchar���˴���ʹ��int��
	˼·����ǰ���������ջ���ֱ��ջ���γ�ջ������������α������жϳ�ջԪ������
	�����Ԫ��ֵ�Ƿ����
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
	Ҫ������ջ������˳��洢����ʽ������洢��һ����СMAXSIZE�Ĵ洢��
	˼·��������ջ��ջ���������������ˣ���ʼʱ�����ջ��Ϊ-1���ұ�ջ��Ϊ
	MAXSIZE������ջ��ָ������ʱΪջ����
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