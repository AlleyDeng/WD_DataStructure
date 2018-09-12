#pragma once

#include "Macro.h"

typedef struct DLNode
{
	ElemType data;
	struct DLNode *next;
	struct DLNode *prior;
} DLNode, *DLinkList;

Status CreateCDLinkList(DLinkList *LHead);
Status DestroyDLinkList(DLinkList *LHead);
int GetDLinkListLength(DLinkList LHead);
void PrintDLinkList(DLinkList LHead);