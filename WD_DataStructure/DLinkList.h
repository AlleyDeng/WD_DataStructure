#pragma once

#include "Macro.h"

typedef struct DLNode
{
	ElemType data;
	struct DLNode *next;
	struct DLNode *prior;
	
#ifdef C2_3_T20
	int freq; // 2.3.7 T20 ×¨ÓÃ
#endif

} DLNode, *DLinkList;

Status CreateDLinkList(DLinkList *LHead);
Status CreateCDLinkList(DLinkList *LHead);
Status DestroyDLinkList(DLinkList *LHead);
int GetDLinkListLength(DLinkList LHead);
void PrintDLinkList(DLinkList LHead);
void PrintCDLinkList(DLinkList LHead);