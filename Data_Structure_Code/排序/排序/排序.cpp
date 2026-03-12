#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//线性表储存结构
#define MAXSIZE 9999999
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE+1];//data[0]作为哨兵或临时变量
	int length;
}SqList;

//线性表随机生成n个元素
void CreatL(SqList* L, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (L->length == MAXSIZE)//表已满
			return;
		L->data[i] = rand();
	}
}

//输出
void PrintL(SqList* L)
{
	for (int i = 1; i <= L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n\n");
}

//交换下标i和j元素
void swap(SqList* L, int i, int j)
{
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}

//冒泡排序
void BubbleSort(SqList* L)
{
	int i, j;
	int flag = 1;//flag用来标记，1表示有数据交换
	for (i = 1; i < L->length && flag==1; i++)
	{
		flag = 0;
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->data[j] > L->data[j + 1])
			{
				swap(L, j, j+1);
				flag = 1;
			}
		}
	}
}

//选择排序
void SelectSort(SqList* L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i;
		for (j = i + 1; j < L->length; j++)
		{
			if (L->data[min] > L->data[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(L, i, min);
		}
	}
}

//插入排序
void InsertSort(SqList* L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->data[i] < L->data[i - 1])
		{
			L->data[0] = L->data[i];
			for (j = i - 1; L->data[j] > L->data[0]; j--)
			{
				L->data[j + 1] = L->data[j];
			}
			L->data[j + 1] = L->data[0];
		}
	}
}

//希尔排序
void ShellSort(SqList* L)
{
	int i, j, k = 0;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;//增量
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->data[i] < L->data[i - increment])//将i插入有序增量子表
			{
				L->data[0] = L->data[i];//暂存
				//找到插入位置
				for (j = i - increment; j > 0 && L->data[0]; j -= increment)
				{
					L->data[j + increment] = L->data[j];
				}
				L->data[j + increment] = L->data[0];//插入
			}
		}
	}
	while (increment > 1);
}

//堆排序
//调整L->data[s]~L->data[m]成为大根堆，关键字：s
void HeapAdjust(SqList* L, int s, int m)
{
	int temp, j;
	temp = L->data[s];
	for (j = 2 * s; j <= m; j *= 2)//沿关键字s较大的孩子向下筛选
	{
		if (j < m && L->data[j] < L->data[j + 1])
		{
			j++;//保证j为关键字孩子中较大记录的下标
		}
		if (temp >= L->data[j])//找到应该插入的位置了
		{
			break;
		}
		//s继续向下
		L->data[s] = L->data[j];
		s = j;
	}
	L->data[s] = temp;//插入
}
//堆排序
void HeapSort(SqList* L)
{
	int i;
	//把L构成大根堆
	for (i = L->length / 2; i > 0; i--)
	{
		HeapAdjust(L, i, L->length);
	}
	for (i = L->length; i > 1; i--)
	{
		swap(L, 1, i);//交换队顶和堆尾
		HeapAdjust(L, 1, i - 1);//交换后保持大根堆
	}
}

//归并排序
//将有序的SR[i~m]和SR[m+1,n]归并为有序的TR[i~n]
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;//k是TR[]的下标
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
		{
			TR[k + l] = SR[i + l];
		}
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
		{
			TR[k + l] = SR[j + l];
		}
	}
}

//将SR[]中相邻长度为s的子序列两两归并到TR[],n为总长
void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1,j;
	//两两归并，i为起始位置
	while (i <= n - 2 * s + 1)
	{
		Merge(SR, TR, i, i + s - 1, i + 2*s - 1);
		i = i + 2 * s;
	}
	//归并最后的两个序列（特判单个子序列）
	if (i < n - s + 1)
	{
		Merge(SR, TR, i, i + s - 1,n);
	}
	else//只剩下单个子序列
	{
		for (j = i; j <= n; j++)
		{
			TR[j] = SR[j];
		}
	}
}
//归并排序
void MergeSort(SqList* L)
{
	int* TR = (int*)malloc(L->length * sizeof(int));//申请额外空间
	int k = 1;
	while (k < L->length)
	{
		MergePass(L->data, TR, k, L->length);
		k = 2 * k;
		MergePass(TR, L->data, k, L->length);//归并回线性表
		k = 2 * k;
	}
}

//快速排序
int Partition(SqList* L, int low, int high)
{
	//确定枢轴
	int pivotkey;
	int m = low + (high - low) / 2;
	//保证数据m<low<hight
	if (L->data[low] > L->data[high])
	{
		swap(L, low, high);
	}
	if (L->data[m] > L->data[high])
	{
		swap(L, m, high);
	}
	if (L->data[m] > L->data[low])
	{
		swap(L, m, low);
	}
	//三数取中作为枢轴
	pivotkey = L->data[low];
	L->data[0] = pivotkey;

	//双指针交替从两边向中间扫描
	while (low < high)
	{
		while (low < high && L->data[high] >= pivotkey)high--;//找到从后往前第一个小于key的
		L->data[low] = L->data[high];//把low替换成较小值，不是交换（原low存在0里了）
		while (low < high && L->data[low] <= pivotkey)low++;//找到从前往后第一个大于key的
		L->data[high] = L->data[low];//把high替换成较大值，不是交换（原high已经在原low里了）
	}
	L->data[low] = L->data[0];//原数据替换回low
	return low;
}
//尾递归
void QuickSort(SqList* L, int low, int high)
{
	int pivot;
	while (low < high)
	{
		pivot = Partition(L, low, high);//将L->r[low~high]一分为二，算出枢轴值pivot
		QuickSort(L, low, pivot - 1);//对低子表递归排序
		low = pivot + 1;
	}
}

//计时器
clock_t start, end; //clock_t为clock()函数返回的变量类型
double duration;

int main()
{
	int n;
	printf("请输入线性表长度：\n");
	while (~scanf("%d", &n))
	{
		SqList* L, * copyL;
		//创建线性表
		if (!(L = (SqList*)malloc(sizeof(SqList))))return 0;
		if (!(copyL = (SqList*)malloc(sizeof(SqList))))return 0;
		L->length = n;
		CreatL(L, n);
		copyL = L;
		//PrintL(L);

		start = clock();
		BubbleSort(L);
		end = clock();
		duration = (double)(end -start) / CLK_TCK; //CLK_TCK以毫秒为单位
		printf("冒泡排序：%f\n", duration);
		//PrintL(L);

		L = copyL;
		start = clock();
		SelectSort(L);
		end = clock();
		duration = (double)(end - start) / CLK_TCK;
		printf("选择排序：%f\n", duration);
		//PrintL(L);

		L = copyL;
		start = clock();
		InsertSort(L);
		end = clock();
		duration = (double)(end - start) / CLK_TCK;
		printf("插入排序：%f\n", duration);
		//PrintL(L);

		L = copyL;
		start = clock();
		BubbleSort(L);
		end = clock();
		duration = (double)(end - start) / CLK_TCK;
		printf("希尔排序：%f\n", duration);
		//PrintL(L);

		L = copyL;
		start = clock();
		HeapSort(L);
		end = clock();
		duration = (double)(end - start) / CLK_TCK;
		printf("堆排序：%f\n", duration);
		//PrintL(L);

		L = copyL;
		start = clock();
		MergeSort(L);
		end = clock();
		duration = (double)(end - start) / CLK_TCK;
		printf("归并排序：%f\n", duration);
		//PrintL(L);

		L = copyL;
		start = clock();
		QuickSort(L, 1, L->length);
		end = clock();
		duration = (double)(end - start) / CLK_TCK;
		printf("快速排序：%f\n", duration);
		//PrintL(L);

		printf("请输入线性表长度：\n");
	}
	return 0;
}