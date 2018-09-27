#include "WD_Chapter_04_BinTree.h"

/*
	4.3.3 03:
	要求：非递归后序遍历二叉树
	思路：分清返回根节点时，是从左子树还是从右子树返回，所以用辅助指针r
	指向其最近访问的结点
*/
void WD_C4_3_T03_PostOrder(BiTree T)
{
	BiTree p = T;
	BiTree r = NULL;	// 指向最近访问的结点
	BTSqStack S;
	InitiateSqStack(&S);

	while (p != NULL && S.top != -1)
	{
		if (p != NULL)
		{	// 到最左结点
			Push(&S, p);
			p = p->lchild;
		}
		else
		{
			p = S.data[S.top];
			if (p->rchild != NULL && p->rchild != r)
			{	// 右子树存在且未被访问
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