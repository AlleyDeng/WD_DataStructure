#ifndef WD_CHAPTER_03_SQQUEUE_H_
#define WD_CHAPTER_03_SQQUEUE_H_

#include "SqQueue.h"
#include "SqStack.h"

Status C3_2_T01_EnQueue(SqQueue *Q, ElemType e);
Status C3_2_T01_DeQueue(SqQueue *Q, ElemType *e);
void C3_2_T02_Reverse(SqQueue *Q);
//Status C_3_T03_InitiateSqQueue(SqQueue *Q);
Status C3_T03_EnQueue(SqStack *S1, SqStack *S2, ElemType e);
Status C3_T03_DeQueue(SqStack *S1, SqStack *S2, ElemType *e);


#endif