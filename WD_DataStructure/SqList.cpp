/*
 * List.c
 *
 *  Created on: 2018��9��2��
 *      Author: deng_chao
 */
#include "SqList.h"

Status GetSqListElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i < 1 || i > L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];

	return OK;
}

Status SqListInsert(SqList *L, int pos, ElemType e)
{	// �����ַ��1��ʼ�������±��0��ʼ
	int k;
	if (L->length == MAXSIZE)
	{
		return ERROR;
	}
	if (pos < 1 || pos > L->length + 1)
	{
		return ERROR;
	}
	if (pos <= L->length)
	{
		for (k = L->length - 1; k >= pos - 1; k--)
		{	// �����һ��Ԫ�ؿ�ʼɨ�裬�ҵ���pos��λ��,��������Ԫ�غ���һλ
			L->data[k+1] = L->data[k];
		}
	}
	L->data[pos - 1] = e;
	L->length++;

	return OK;
}

Status SqListDelete(SqList *L, int pos, ElemType *e)
{
	int k;
	if (L->length == 0)
	{
		return ERROR;
	}
	if (pos < 1 || pos > L->length)
	{
		return ERROR;
	}
	*e = L->data[pos - 1];

	if (pos != L->length)
	{
		for (k = pos; k <= L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}

	L->length--;
	return OK;
}

