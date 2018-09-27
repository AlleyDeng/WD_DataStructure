#include "WD_Chapter_04_BinTree.h"

/*
	4.3.3 03:
	Ҫ�󣺷ǵݹ�������������
	˼·�����巵�ظ��ڵ�ʱ���Ǵ����������Ǵ����������أ������ø���ָ��r
	ָ����������ʵĽ��
*/
void WD_C4_3_T03_PostOrder(BiTree T)
{
	BiTree p = T;
	BiTree r = NULL;	// ָ��������ʵĽ��
	BTSqStack S;
	InitiateSqStack(&S);

	while (p != NULL && S.top != -1)
	{
		if (p != NULL)
		{	// ��������
			Push(&S, p);
			p = p->lchild;
		}
		else
		{
			p = S.data[S.top];
			if (p->rchild != NULL && p->rchild != r)
			{	// ������������δ������
				p = p->rchild;
				Push(&S, p);
				p = p->lchild;
			}
			else
			{
				Pop(&S, &p);
				VisitNode(p);
				r = p;
				p = NULL;
			}
		}
	}
}