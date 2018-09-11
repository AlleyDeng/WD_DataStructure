#pragma once

#include "Macro.h"

typedef struct DLNode
{
	ElemType elem;
	struct Node *next;
	struct Node *prior;
} DLNode, *DLinkList;