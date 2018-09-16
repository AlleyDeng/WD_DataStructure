#include "WD_Chapter_03_SqStack.h"

int main(void)
{
	LinkList L;

	CreateLinkList(&L);
	if (C3_1_T04_IsSymmetry(L) == OK)
	{
		printf("OK\n");
	}
	else
	{
		printf("ERROR");
	}

	DestroyLinkList(&L);

	system("pause");
	return 0;
}
