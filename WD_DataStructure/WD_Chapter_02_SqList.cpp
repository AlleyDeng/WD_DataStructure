/*
 * WD_Chapter_02_List.c
 *
 *  Created on: 2018年9月2日
 *      Author: deng_chao
 */

#include "WD_Chapter_02_SqList.h"

/**
 *	2.2.3 01:
 *	要求：从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删除元素的值。
 *	空出的位置由最后一个元素填补。
 *	思路：扫描顺序表，找到最小值位置，将最后一个元素填入
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
 * 	要求：将顺序表的所有元素逆置（空间复杂度O(1)）
 * 	思路：扫描前半部分，将元素L->data[i]与L->data[L->length-i-1]交换
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
 * 	要求：删除线性表中所有值为x的数据元素
 * 	思路：扫描线性表，用k统计不等于x的次数，并将不等于x的元素放在位置k
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
 * 	要求：从有序顺序表中删除其值在给定值s与t(s<t)之间的所有元素
 * 	思路：先寻找值大于等于s的第一个元素（第一个删除的元素），然后寻找值大于t的
 * 	的第一个元素（删除最后一个元素的后一个元素），将后面元素前移
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
	{	// 所有元素都小于s，返回错误信息！
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
 * 	要求：从顺序表中删除其值在s与t之间(包含s和t)的所有函数
 * 	思路：扫描过程中用k记录值在s到t之间的元素，若元素值不在其之间，
 * 	则前移k个位置，否则执行k++
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
 * 	要求：从有序表中删除所有重复的元素
 * 	思路：第一个元素看做待插入表，后面元素若与前面元素相等则继续向后判断，不相等
 * 	则插入非重复有序表的最后位置
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
 * 	要求：将两个有序顺序表组成新的有序表，并返回结果顺序表
 * 	思路：归并
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
 * 	要求：在一维数组A[m+n]中一次存放着两个线性表a和b，将a和b两个
 * 	线性表位置互换
 * 	思路：首先将整个数组逆置，在分别将数组前n个和后m个元素逆置
 * */
void C2_2_T08_Reverse(int A[], int m, int n)
{
	int i = 0;
	int len = m + n;

//	for (i = left; i <= (right+left)/2; i++)
//	{	// 数组逆置
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
 * 	要求：在有序表中查找数值为x的元素，若找到则与后继元素交换，若找不到则将其插
 * 	入有序表中，保证表中元素仍递增有序。（查找时间需最短）
 * 	思路：采用折半查找，查找成功则与后继元素交换（最后一个元素不交换），若查找失
 * 	败，在L->data[right]处插入x
 * */
void C2_2_T09_SearchExchangeInsert(SqList *L, ElemType x)
{
	int i = 0;
	int left = 0;
	int right = L->length - 1;
	int mid;
	while (left <= right)
	{	// 	折半查找
		mid = (left + right) / 2;
		if (L->data[mid] == x)
		{	// 	找到x
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
	{	// 	最后一个元素不执行交换
		L->data[mid] ^= L->data[mid + 1];
		L->data[mid + 1] ^= L->data[mid];
		L->data[mid] ^= L->data[mid + 1];
	}

	if (left > right)
	{	// 	查找失败
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
 * 	要求：将一维数组保存的序列循环左移p个位置
 * 	思路：现将整个数组所有元素逆置，在分别将前L->length-p个位置和后p个位置逆置
 * */
void C2_2_T10_ROLpElem(int arr[], int n, int p)
{
	int i;
	//	for (i = left; i <= (right+left)/2; i++)
	//	{	// 数组逆置
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
 * 	要求：求出两个有序数列的中位数
 * 	思路：先分别求出两个数列的中位数
 * 	若m1=m2，则返回
 * 	若m1<m2，则舍弃A中较小的一半和B中较大的一半
 * 	若m1>m2，则舍弃A中较大的一半和B中较小的一半
 *
 * */
int C2_2_T11_SearchMedian(int A[], int B[], int len)
{
	int s1 = 0, s2 = 0;					//	首位
	int d1 = len - 1, d2 = len - 1;		//	末位
	int m1, m2;							//	中位数

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
			{	// 奇数个元素，保留中间点
				s1 = m1;
				d2 = m2;
			}
			else
			{	// 偶数个元素，舍弃中间点
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
 * 	要求：若一个整序列中某一元素数量占数组的一半以上，则称该元素为该序列的主元素
 * 	思路：删除两个不同的元素，主元素不变
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
