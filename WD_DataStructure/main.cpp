
#include "WD_Chapter_02_LinkList.h"

int main(void)
{
	LinkList L = NULL;
	LinkList L1 = NULL;

	CreateCLinkList(&L);
	CreateCLinkList(&L1);

	C2_3_T18_LinkTwoCLinks(L, L1);
	PrintCLinkList(L);

	DestroyCLinkList(&L);
	DestroyCLinkList(&L1);


	return 0;
}