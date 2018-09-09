
#include "WD_Chapter_02_LinkList.h"

int main(void)
{
	LinkList L1, L2;
	ElemType elem = 5;

	CreateLinkList(&L1);
	//CreateLinkList(&L2);

	PrintLinkList(L1);
	L2 = C2_3_T11_ListSepaParity(L1);
	PrintLinkList(L1);
	PrintLinkList(L2);
	//printf("%d\n", C2_3_T08_SearchCommonNode(L1, L2)->data);
	
	/*C2_3_T06_SortList(L);
	C2_3_T07_DelRange(L, 3, 6);
	PrintLinkList(L);*/
	//printf("\n--------------------Debug--------------------\n");
	//PrintLinkList(L);
	//LinkListInsert(L, 5, elem);
	//PrintLinkList(L);
	//LinkListDelete(L, 3, &elem);
	//PrintLinkList(L);
	//C2_3_T03_InvertedPrintList(L);
	//C2_3_T01_DelX(&L, 3);
	//PrintLinkList(L);

	DestroyLinkList(L1);
	DestroyLinkList(L2);

	return 0;
}