/*
 * WD_Chapter_02_List.c
 *
 *  Created on: 2018��9��2��
 *      Author: deng_chao
 */

#include "WD_Chapter_02_SqList.h"

/**
 *	2.2.3 01:
 *	Ҫ�󣺴�˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�������ɺ������ر�ɾ��Ԫ�ص�ֵ��
 *	�ճ���λ�������һ��Ԫ�����
 *	˼·��ɨ��˳����ҵ���Сֵλ�ã������һ��Ԫ������
 * */
Status C2_2_T01_DelMinVal(SqList *L, ElemType *e)
{
	int k, i;
	ElemType minValue;

	if (L == NULL || L->length == 0)
	{
		return ERROR;
	}

	minValue = L->data[0];
	k = 0;
	for (i = 1; i < L->length; i++)
	{
		if (minValue > L->data[i])
		{
			minValue = L->data[i];
			k = i;
		}
	}

	*e = minValue;
	L->data[k] = L->data[L->length - 1];
	L->length--;

	return OK;
}

/**
 * 	2.2.3 02:
 * 	Ҫ�󣺽�˳��������Ԫ�����ã��ռ临�Ӷ�O(1)��
 * 	˼·��ɨ��ǰ�벿�֣���Ԫ��L->data[i]��L->data[L->length-i-1]����
 * */
void C2_2_T02_Reverse(SqList *L)
{
	int i;

	for (i = 0; i < L->length / 2; i++)
	{
		int temp = L->data[i];
		L->data[i] = L->data[L->length - i - 1];
		L->data[L->length - i - 1] = temp;
	}
}

/**
 * 	2.2.3 03:
 * 	Ҫ��ɾ�����Ա�������ֵΪx������Ԫ��
 * 	˼·��ɨ�����Ա���kͳ�Ʋ�����x�Ĵ���������������x��Ԫ�ط���λ��k
 * */
void C2_2_T03_DelX(SqList *L, ElemType x)
{
	int k = 0;
	int i;
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] != x)
		{
			L->data[k++] = L->data[i];
		}
	}
	L->length = k;
}

/**
 * 	2.2.3 04:
 * 	Ҫ�󣺴�����˳�����ɾ����ֵ�ڸ���ֵs��t(s<t)֮�������Ԫ��
 * 	˼·����Ѱ��ֵ���ڵ���s�ĵ�һ��Ԫ�أ���һ��ɾ����Ԫ�أ���Ȼ��Ѱ��ֵ����t��
 * 	�ĵ�һ��Ԫ�أ�ɾ�����һ��Ԫ�صĺ�һ��Ԫ�أ���������Ԫ��ǰ��
 * */
Status C2_2_T04_DelStoT(SqList *L, ElemType s, ElemType t)
{
	int i, j;
	if (s >= t || L->length == 0)
	{
		return ERROR;
	}
	for (i = 0; i < L->length && L->data[i] < s; i++)
		;
	if (i >= L->length)
	{	// ����Ԫ�ض�С��s�����ش�����Ϣ��
		return ERROR;
	}
	for (j = i; j < L->length && L->data[j] <= t; j++)
		;

	for (; j < L->length; i++, j++)
	{
		L->data[i] = L->data[j];
	}

	L->length = i;

	return OK;
}

/**
 * 	2.2.3 05:
 * 	Ҫ�󣺴�˳�����ɾ����ֵ��s��t֮��(����s��t)�����к���
 * 	˼·��ɨ���������k��¼ֵ��s��t֮���Ԫ�أ���Ԫ��ֵ������֮�䣬
 * 	��ǰ��k��λ�ã�����ִ��k++
 * */
Status C2_2_T05_DelStoT(SqList *L, ElemType s, ElemType t)
{
	int i;
	int k = 0;

	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] >= s && L->data[i] <= t)
		{
			k++;
		}
		else
		{
			L->data[i - k] = L->data[i];
		}
	}

	L->length -= k;

	return OK;
}

/**
 * 	2.2.3 06:
 * 	Ҫ�󣺴��������ɾ�������ظ���Ԫ��
 * 	˼·����һ��Ԫ�ؿ��������������Ԫ������ǰ��Ԫ��������������жϣ������
 * 	�������ظ����������λ��
 * */
Status C2_2_T06_DelSame(SqList *L)
{
	int i, k = 0;

	for (i = 1; i < L->length; i++)
	{
		if (L->data[k] != L->data[i])
		{
			L->data[++k] = L->data[i];
		}
	}
	L->length = k + 1;

	return OK;
}

/**
 * 	2.2.3 07:
 * 	Ҫ�󣺽���������˳�������µ�����������ؽ��˳���
 * 	˼·���鲢
 * */
Status C2_2_T07_MergeSqList(SqList A, SqList B, SqList *C)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < A.length && j < B.length)
	{
		if (A.data[i] < B.data[j])
		{
			C->data[k++] = A.data[i++];
		}
		else
		{
			C->data[k++] = B.data[j++];
		}
	}
	while (i < A.length && k < MAXSIZE)
	{
		C->data[k++] = A.data[i++];
	}
	while (j < B.length && k < MAXSIZE)
	{
		C->data[k++] = B.data[j++];
	}
	C->length = k;

	return OK;
}

/**
 * 	2.2.3 08:
 * 	Ҫ����һά����A[m+n]��һ�δ�����������Ա�a��b����a��b����
 * 	���Ա�λ�û���
 * 	˼·�����Ƚ������������ã��ڷֱ�����ǰn���ͺ�m��Ԫ������
 * */
void C2_2_T08_Reverse(int A[], int m, int n)
{
	int i = 0;
	int len = m + n;

//	for (i = left; i <= (right+left)/2; i++)
//	{	// ��������
//		int temp = A[i];
//		A[i] = A[right+left-i];
//		A[right+left-i] = temp;
//	}

	for (i = 0; i < len / 2; i++)
	{
		int temp = A[i];
		A[i] = A[len - i - 1];
		A[len - i - 1] = temp;
	}

	for (i = 0; i < n / 2; i++)
	{
		int temp = A[i];
		A[i] = A[n - i - 1];
		A[n - i - 1] = temp;
	}

	for (i = n; i < (len + n) / 2; i++)
	{
		int temp = A[i];
		A[i] = A[len + n - i - 1];
		A[len + n - i - 1] = temp;
	}
}

/**
 * 	2.2.3 09:
 * 	Ҫ����������в�����ֵΪx��Ԫ�أ����ҵ�������Ԫ�ؽ��������Ҳ��������
 * 	��������У���֤����Ԫ���Ե������򡣣�����ʱ������̣�
 * 	˼·�������۰���ң����ҳɹ�������Ԫ�ؽ��������һ��Ԫ�ز���������������ʧ
 * 	�ܣ���L->data[right]������x
 * */
void C2_2_T09_SearchExchangeInsert(SqList *L, ElemType x)
{
	int i = 0;
	int left = 0;
	int right = L->length - 1;
	int mid;
	while (left <= right)
	{	// 	�۰����
		mid = (left + right) / 2;
		if (L->data[mid] == x)
		{	// 	�ҵ�x
			break;
		}
		else if (L->data[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (L->data[mid] == x && mid != L->length - 1)
	{	// 	���һ��Ԫ�ز�ִ�н���
		L->data[mid] ^= L->data[mid + 1];
		L->data[mid + 1] ^= L->data[mid];
		L->data[mid] ^= L->data[mid + 1];
	}

	if (left > right)
	{	// 	����ʧ��
		for (i = L->data[L->length - 1]; i > right; i--)
		{
			L->data[i + 1] = L->data[i];
		}
		L->data[i + 1] = x;
		L->length++;
	}
}

/**
 * 	2.2.3 10:
 * 	Ҫ�󣺽�һά���鱣�������ѭ������p��λ��
 * 	˼·���ֽ�������������Ԫ�����ã��ڷֱ�ǰL->length-p��λ�úͺ�p��λ������
 * */
void C2_2_T10_ROLpElem(int arr[], int n, int p)
{
	int i;
	//	for (i = left; i <= (right+left)/2; i++)
	//	{	// ��������
	//		int temp = A[i];
	//		A[i] = A[right+left-i];
	//		A[right+left-i] = temp;
	//	}
	for (i = 0; i < n / 2; i++)
	{
		arr[i] ^= arr[n - i - 1];
		arr[n - i - 1] ^= arr[i];
		arr[i] ^= arr[n - i - 1];
	}

	for (i = 0; i < (n - p) / 2; i++)
	{
		arr[i] ^= arr[n - p - i - 1];
		arr[n - p - i - 1] ^= arr[i];
		arr[i] ^= arr[n - p - i - 1];
	}

	for (i = n - p; i < ((n - p) + n) / 2; i++)
	{
		arr[i] ^= arr[(n - p) + n - i - 1];
		arr[(n - p) + n - i - 1] ^= arr[i];
		arr[i] ^= arr[(n - p) + n - i - 1];
	}
}

/**
 * 	2.2.3 11:
 * 	Ҫ����������������е���λ��
 * 	˼·���ȷֱ�����������е���λ��
 * 	��m1=m2���򷵻�
 * 	��m1<m2��������A�н�С��һ���B�нϴ��һ��
 * 	��m1>m2��������A�нϴ��һ���B�н�С��һ��
 *
 * */
int C2_2_T11_SearchMedian(int A[], int B[], int len)
{
	int s1 = 0, s2 = 0;					//	��λ
	int d1 = len - 1, d2 = len - 1;		//	ĩλ
	int m1, m2;							//	��λ��

	int i, j;

	while (s1 != d1 && s2 != d2)
	{
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;

		if (A[m1] == B[m2])
		{
			return A[m1];
		}
		else if (A[m1] < B[m2])
		{
			if ((s1 + d1) % 2 == 0)
			{	// ������Ԫ�أ������м��
				s1 = m1;
				d2 = m2;
			}
			else
			{	// ż����Ԫ�أ������м��
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else
		{
			if ((s2 + d2) % 2 == 0)
			{
				d1 = m1;
				s2 = m2;
			}
			else
			{
				d1 = m1;
				s2 = m2 + 1;
			}
		}

		for (i = s1; i <= d1; i++)
		{
			printf("%d\t", A[i]);
		}
		printf("\n");
		for (j = s2; j <= d2; j++)
		{
			printf("%d\t", B[j]);
		}
		printf("\n");
	}

	return A[s1] < B[s2] ? A[s1] : B[s2];
}

/**
 * 	2.2.3 12:
 * 	Ҫ����һ����������ĳһԪ������ռ�����һ�����ϣ���Ƹ�Ԫ��Ϊ�����е���Ԫ��
 * 	˼·��ɾ��������ͬ��Ԫ�أ���Ԫ�ز���
 * */
int C2_2_T12_SearchMajorElem(int A[], int n)
{
	int i, temp;
	int count = 1;
	temp = A[0];

	for (i = 1; i < n; i++)
	{
		if (A[i] == temp)
		{
			count++;
		}
		else
		{
			if (count > 0)
			{
				count--;
			}
			else
			{
				temp = A[i];
				count = 1;
			}
		}
	}

	if (count > 0)
	{
		count = 0;
		for (i = 0; i < n; i++)
		{
			if (A[i] == temp)
			{
				count++;
			}
		}
	}

	if (count > n / 2)
	{
		return temp;
	}
	else
	{
		return -1;
	}
}
