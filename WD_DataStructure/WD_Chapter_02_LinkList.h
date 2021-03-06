/*
 * WD_Chapter_02_LinkList.h
 *
 *  Created on: 2018��9��6��
 *      Author: deng_chao
 */

#ifndef WD_CHAPTER_02_LINKLIST_H_
#define WD_CHAPTER_02_LINKLIST_H_

#include "Macro.h"
#include "LinkList.h"
#include "DLinkList.h"

void C2_3_T01_DelX(LinkList *L, ElemType x);
void C2_3_T02_DelX(LinkList L, ElemType x);
void C2_3_T03_InvertedPrintList(LinkList L);
void C2_3_T04_DelMinNode(LinkList L);
LinkList C2_3_T05_ReverseLinkList(LinkList L);
LinkList C2_3_T06_SortList(LinkList L);
void C2_3_T07_DelRange(LinkList L, ElemType floor, ElemType root);
LinkList C2_3_T08_SearchCommonNode(LinkList L1, LinkList L2);
void C2_3_T09_DelMinWhole(LinkList L);
LinkList C2_3_T10_ListSepaParity(LinkList A);
LinkList C2_3_T11_ListSepaParity(LinkList A);
void C2_3_T12_ListDelSameElem(LinkList L);
void C2_3_T13_MergeList(LinkList L1, LinkList L2);
LinkList C2_3_T14_CreateCommElemList(LinkList L1, LinkList L2);
LinkList C2_3_T15_SetIntersection(LinkList L1, LinkList L2);
Status C2_3_T16_IsSubSequence(LinkList LSrc, LinkList LSub);
Status C2_3_T17_IsDLinkListSymmetry(DLinkList L);
LinkList C2_3_T18_LinkTwoCLinks(LinkList LHead1, LinkList LHead2);
void C2_3_T19_CirDelMinAll(LinkList *LHead);
DLNode *C2_3_T20_Locate(DLinkList LHead, ElemType x);
Status C2_3_T21_SearchKth(LinkList LHead, int k);
LNode *C2_3_T22_SearchSameSuf(LinkList LHead1, LinkList LHead2);
void C2_3_T23_DelSameElem(LinkList L, int n);

#endif /* WD_CHAPTER_02_LINKLIST_H_ */
