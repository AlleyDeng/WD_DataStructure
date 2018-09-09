/*
 * WD_Chapter_02_List.h
 *
 *  Created on: 2018Äê9ÔÂ2ÈÕ
 *      Author: deng_chao
 */

#ifndef WD_CHAPTER_02_SQLIST_H_
#define WD_CHAPTER_02_SQLIST_H_

#include "Macro.h"
#include "SqList.h"
#include "LinkList.h"

Status C2_2_T01_DelMinVal(SqList *L, ElemType *e);
void C2_2_T02_Reverse(SqList *L);
void C2_2_T03_DelX(SqList *L, ElemType x);
Status C2_2_T04_DelStoT(SqList *L, ElemType s, ElemType t);
Status C2_2_T05_DelStoT(SqList *L, ElemType s, ElemType t);
Status C2_2_T06_DelSame(SqList *L);
Status C2_2_T07_MergeSqList(SqList A, SqList B, SqList *C);
void C2_2_T08_Reverse(int A[], int n, int m);
void C2_2_T09_SearchExchangeInsert(SqList *L, ElemType x);
void C2_2_T10_ROLpElem(int arr[], int n, int p);
int C2_2_T11_SearchMedian(int A[], int B[], int len);
int C2_2_T12_SearchMajorElem(int A[], int n);

#endif /* WD_CHAPTER_02_SQLIST_H_ */
