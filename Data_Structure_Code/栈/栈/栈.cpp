#define _CRT_SECURE_NO_WARNINGS

//顺序储存
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef int SElemtype;
//typedef int Status;
//#define ERROR 0;
//#define OK 1;
//#define MAXSIZE 100
//
////建立栈 
//typedef struct 
//{
//	SElemtype data[MAXSIZE];//栈的数据 
//	int top;//栈顶指针 
//}SpStack;
//
//SpStack StackCreat()
//{
//	SpStack* S = (SpStack*)malloc(sizeof(SpStack));
//	if (S == NULL)
//	{
//		printf("创建失败");
//	}
//	S->top = -1;
//	return *S;
//}
//
////进栈
//Status Push(SpStack* S, SElemtype e)
//{
//	if (S->top == MAXSIZE - 1)//如果栈已经满了 
//	{
//		return ERROR;
//	}
//	S->top++;
//	S->data[S->top] = e;
//	return OK;
//}
//
////出栈
//Status Pop(SpStack* S, SElemtype* e)
//{
//	if (S->top == -1)
//	{
//		return ERROR;
//	}
//	*e = S->data[S->top];//将要删除的栈顶赋给e 
//	S->top--;
//	return OK;
//}
//
//int main()
//{
//	SpStack S;
//	S=StackCreat();
//	int n, i, e;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &e);
//		Push(&S, e);
//	}
//	Pop(&S, &e);
//	printf("%d", e);
//	return 0;
//}

//共享空间
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef int Statue;
//typedef int SElemtype;
//#define OK 1;
//#define ERROR 0;
//#define MAXSIZE 1009
//
////两栈共享空间内存
//typedef struct 
//{
//	SElemtype data[MAXSIZE];
//	int top1;//栈1顶点指针
//	int top2;//栈2顶点指针
//}SqDoubleStack;
//
////插入
//Statue Push(SqDoubleStack* S, SElemtype e, int stackNumber)//需穿入栈号
//{
//	if (S->top1 + 1 == S->top2)//满栈
//	{
//		return ERROR;
//	}
//	if (stackNumber == 1)
//	{
//		S->data[++S->top1] = e;
//	}
//	else if(stackNumber==2)
//	{
//		S->data[--S->top2] = e;
//	}
//	return OK;
//}
//
////弹出,返回值存e
//Statue Pop(SqDoubleStack* S, SElemtype* e, int stackNumber)
//{
//	if (stackNumber == 1)
//	{
//		if (S->top1 == -1)//栈为空
//			return ERROR;
//		*e = S->data[S->top1--];//存并弹出
//	}
//	else
//	{
//		if (S->top2 == -1)
//			return ERROR;
//		*e = S->data[S->top2++];
//	}
//}
//
//void OutPut(SqDoubleStack *S)
//{
//	for (int i = 0; i <= S->top1; i++)printf("%d\n", S->data[i]);
//	for (int i = MAXSIZE-2; i >=S->top2; i--)printf("%d\n", S->data[i]);
//}
//
//void Print()
//{
//	printf("1.入栈\n2.出栈\n");
//}
//
//SqDoubleStack StackCreat()
//{
//	SqDoubleStack* S = (SqDoubleStack*)malloc(sizeof(SqDoubleStack));
//	if (S == NULL)printf("LOSE\n");
//	S->top1 = -1;
//	S->top2 = MAXSIZE-1;
//	return *S;
//}
//
//int main()
//{
//	SqDoubleStack S;
//	S=StackCreat();
//	int n,e=0,num;
//	Print();
//	while (~scanf("%d", &n))
//	{
//		if (n == 1)
//		{
//			printf("输入元素和需要插入的栈号：\n");
//			scanf("%d %d", &e, &num);
//			Push(&S,e,num);
//			OutPut(&S);
//		}
//		else
//		{
//			printf("输入需要弹出元素的栈：\n");
//			scanf("%d", &num);
//			Pop(&S, &e, num);
//			printf("弹出的元素为：%d\n", e);
//			OutPut(&S);
//		}
//		printf("\n");
//		Print();
//	}
//	return 0;
//}