
#include "WD_Chapter_02_LinkList.h"

int main(void)
{
	LinkList L1, L2;
	ElemType elem = 5;

	CreateLinkList(&L1);
	CreateLinkList(&L2);

	PrintLinkList(L1);
	PrintLinkList(L2);
	L1 = C2_3_T14_CreateCommElemList(L1, L2);
	PrintLinkList(L1);
	//PrintLinkList(L2);

	//DestroyLinkList(L1);
	DestroyLinkList(L2);

	return 0;
}