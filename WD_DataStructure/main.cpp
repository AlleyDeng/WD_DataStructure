#include "WD_Chapter_03_SqQueue.h"
//#include "SqStack.h"


int main(void)
{
	SqStack S1;
	SqStack S2;
	ElemType e;
	
	IntiateSqStack(&S1);
	IntiateSqStack(&S2);

	C_3_T03_EnQueue(&S1, &S2, 1);
	C_3_T03_EnQueue(&S1, &S2, 2);
	C_3_T03_EnQueue(&S1, &S2, 3);
	C_3_T03_EnQueue(&S1, &S2, 4);
	C_3_T03_EnQueue(&S1, &S2, 5);
	C_3_T03_DeQueue(&S1, &S2, &e);
	C_3_T03_DeQueue(&S1, &S2, &e);
	C_3_T03_DeQueue(&S1, &S2, &e);
	C_3_T03_DeQueue(&S1, &S2, &e);
	C_3_T03_DeQueue(&S1, &S2, &e);

	system("pause");
	return 0;
}
