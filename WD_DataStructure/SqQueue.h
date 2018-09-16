#ifndef SQQUEUE_H_
#define SQQUEUE_H_

#include "Macro.h"

typedef struct SqQueue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
#ifdef C_3_2_T01
	int tag;
#endif;
} SqQueue;

Status InitQueue(SqQueue *Q);
int GetQueueLength(SqQueue Q);
Status EqQueue(SqQueue *Q, ElemType e);
Status DeQueue(SqQueue *Q, ElemType *e);

#endif