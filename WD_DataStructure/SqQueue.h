#ifndef SQQUEUE_H_
#define SQQUEUE_H_

#include "Macro.h"

typedef struct SqQueue
{	// —≠ª∑∂”¡–
	ElemType data[MAXSIZE];
	int front;
	int rear;
#ifdef C_3_2_T01
	int tag;
#endif;
} SqQueue;

Status InitiateSqQueue(SqQueue *Q);
//int GetQueueLength(SqQueue *Q);
Status EnQueue(SqQueue *Q, ElemType e);
Status DeQueue(SqQueue *Q, ElemType *e);
Status IsQueueEmpty(SqQueue Q);

#endif