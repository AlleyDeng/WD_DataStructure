#ifndef BINTREE_H_
#define BINTREE_H_

#include "Macro.h"

typedef struct BinTNode
{
	ElemType data;
	struct BinTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
} ThreadNode, *ThreadTree;

typedef struct BTSqStack
{
	BiTree data[MAXSIZE];
	int top;
} BTSqStack;

typedef struct BTSqQueue
{	// —≠ª∑∂”¡–
	BiTree data[MAXSIZE];
	int front;
	int rear;
} BTSqQueue;


void VisitNode(BiTNode *N);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
//void CreateBinTreeByPre(BiTree *T);
void InOrderNoRecursion(BiTree T);
void LevelOrder(BiTree T);

void InThread(ThreadTree *p, ThreadTree *pre);
void CreateInThread(ThreadTree T);
ThreadNode *FirstNode(ThreadNode *p);
ThreadNode *NextNode(ThreadNode *p);
void InOrderThreadTree(ThreadNode *T);
void VisitThreadNode(ThreadNode *p);

Status InitiateSqStack(BTSqStack *S);
Status Push(BTSqStack *S, BiTree e);
Status Pop(BTSqStack *S, BiTree *e);

Status InitiateSqQueue(BTSqQueue *Q);
Status EnQueue(BTSqQueue *Q, BiTree e);
Status DeQueue(BTSqQueue *Q, BiTree *e);
Status IsQueueEmpty(BTSqQueue Q);

#endif