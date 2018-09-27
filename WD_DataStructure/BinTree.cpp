#include "BinTree.h"

/*
			A
		   / \
		  B   C
		 / \  / \
		D  E F  G

	PreOrder:	A B D E C F G
	InOrder:	D B E A F C G
	PostOrder:	D E B F G C A
*/

void VisitNode(BiTNode *N)
{
	printf("%d\n", N->data);
}

void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		VisitNode(T);;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}

}

void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		VisitNode(T);;
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		VisitNode(T);
	}
}


void InOrderNoRecursion(BiTree T)
{	// 非递归中序遍历
	BiTNode *p = T;
	BTSqStack S;
	InitiateSqStack(&S);
	
	while (p != NULL || S.top != -1)
	{
		if (p != NULL)
		{
			Push(&S, p);
			p = p->lchild;
		}
		else
		{
			Pop(&S, &p);
			VisitNode(p);
			p = p->rchild;
		}
	}
}

void LevelOrder(BiTree T)
{
	BiTree p;
	BTSqQueue Q;
	InitiateSqQueue(&Q);
	EnQueue(&Q, T);

	while (!IsQueueEmpty(Q))
	{
		DeQueue(&Q, &p);
		VisitNode(p);
		if (p->lchild != NULL)
		{
			EnQueue(&Q, p->lchild);
		}
		if (p->rchild != NULL)
		{
			EnQueue(&Q, p->rchild);
		}
	}
}

// 线索二叉树
void VisitThreadNode(ThreadNode *p)
{
	printf("%d\t", p->data);
}

void InThread(ThreadTree *p, ThreadTree *pre)
{	// 中序线索化
	if (p != NULL)
	{
		InThread(&(*p)->lchild, pre);	// 线索化左子树
		if (p!= NULL && (*p)->lchild == NULL)
		{
			(*p)->lchild = *pre;
			(*p)->ltag = 1;
		}
		if (pre != NULL && (*pre)->rchild == NULL)
		{
			(*pre)->rchild = *p;
			(*pre)->rtag = 1;
		}
		pre = p;
		InThread(&(*p)->rchild, pre);	// 线索化右子树
	}
}

void CreateInThread(ThreadTree T)
{
	ThreadTree pre = NULL;
	if (T != NULL)
	{
		InThread(&T, &pre);
		pre->rchild = NULL;	// 最后一个结点
		pre->rtag = 1;
	}
}

ThreadNode *FirstNode(ThreadNode *p)
{	// 中序遍历线索二叉树p第一个结点
	while (p->ltag == 0)
	{
		p = p->lchild;
	}
	return p;
}

ThreadNode *NextNode(ThreadNode *p)
{	// 中序线索二叉树结点p的下一个结点
	if (p->rtag == 0)
	{	// rtag == 0，返回右子树第一个结点
		return FirstNode(p->rchild);
	}
	else
	{	// rtag == 1，直接返回其后继
		return p->rchild;
	}
}

void InOrderThreadTree(ThreadNode *T)
{	// 中序遍历不含头结点的线索二叉树T
	for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
	{
		VisitThreadNode(p);
	}

}


// 运算过程中需要用到栈和队列保存结点
// 为防止与之前程序所使用数据类型冲突
// 重新定义相关数据结构和操作
Status InitiateSqStack(BTSqStack *S)
{
	S->top = -1;
	return OK;
}

Status Push(BTSqStack *S, BiTree e)
{
	if (S->top == MAXSIZE)
	{
		return ERROR;
	}

	S->top++;
	S->data[S->top] = e;

	return OK;
}

Status Pop(BTSqStack *S, BiTree *e)
{
	if (S->top == -1)
	{
		return ERROR;
	}

	*e = S->data[S->top--];

	return OK;
}

Status InitiateSqQueue(BTSqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

int GetQueueLength(BTSqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) / MAXSIZE;
}

Status EnQueue(BTSqQueue *Q, BiTree e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		return ERROR;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;

	return OK;
}

Status DeQueue(BTSqQueue *Q, BiTree *e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}

	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return OK;
}

Status IsQueueEmpty(BTSqQueue Q)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		return OK;
	}
	return ERROR;
}
