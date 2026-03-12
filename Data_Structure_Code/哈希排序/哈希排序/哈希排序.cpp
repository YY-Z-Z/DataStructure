#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
//创建线性表
#define MAXSIZE 20 //储存空间初始分配量
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
//希尔排序
void ShellSort(SqList* L)
{
	int i, j, k = 0;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;//增量序列
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->data[i] < L->data[i - increment])//将data[i]插入增量子数组
			{
				L->data[0] = L->data[i];//暂存在L->data[0]
				for (j = i - increment; j > 0 && L->data[0]<L->data[j]; j -= increment)
				{
					L->data[j + increment] = L->data[j];//记录后移，查找插入位置
				}
				L->data[j + increment] = L->data[0];//插入
			}
		}
	} 
	while (increment > 1);
}
int main()
{
	SqList *L;
	L = (SqList*)malloc(sizeof(SqList));
	printf("请输入排序个数：\n");
	scanf("%d", &L->length);
	printf("请输入待排序序列：\n");
	for (int i = 1; i <= L->length; i++)
	{
		scanf("%d", &L->data[i]);
	}
	ShellSort(L);
	for (int i = 1; i <= L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	return 0;
}