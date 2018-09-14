
#include "WD_Chapter_02_LinkList.h"

int main(void)
{
	LinkList L = NULL;
	//LinkList L1 = NULL;

	CreateLinkList(&L);
	//CreateCLinkList(&L1);
	PrintLinkList(L);

	C2_3_T23_DelSameElem(L, 10);
	PrintLinkList(L);

	DestroyLinkList(&L);
	//DestroyCLinkList(&L1);


	return 0;
}