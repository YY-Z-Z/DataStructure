#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MaxN 100 //最大结点个数
#define Maxbit 255 //最大编码值
#define MaxValue 9999 //最大权值

//树储存结构
typedef struct
{
	int weight;//权值
	int flag;//标记,flag==1则已经加入到hafftree中
	int parent;//父结点下标
	int leftChild;//左孩子结点下标
	int rightChild;//右孩子结点下标
}HaffNode;

//哈夫曼编码结构
typedef struct
{
	int bit[MaxN];//每个叶子结点到根节点路径所对应的哈夫曼编码
	int start;//编码起始下标
	int weight;//字符权值
}Code;

//建立hafftree
//叶节点数为n，权值数组为weight的hafftree*
void Haffman(int weight[], int n, HaffNode haffTree[])
{
	int i, j, m1, m2, x1, x2;

	//初始化hafftree
	//共有n*2+1个结点,前n个是叶子结点
	for (i = 0; i < 2 * n - 1; i++)
	{
		if (i < n)
		{
			haffTree[i].weight = weight[i];
		}
		else
		{
			haffTree[i].weight = 0;
		}
		haffTree[i].parent = 0;
		haffTree[i].flag = 0;
		haffTree[i].leftChild = -1;
		haffTree[i].rightChild = -1;
}

	//构造hafftree的n-1个非叶子结点
	for (i = 0; i < n-1; i++)
	{
		//找到权值最小的两颗树的下标x1,x2
		m1 = m2 = MaxValue;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++)
		{
			//先找一颗权值较小的树，再找另一颗
			if (haffTree[j].weight < m1 && haffTree[j].flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = haffTree[j].weight;
				x1 = j;
			}
			else if (haffTree[j].weight < m2 && haffTree[j].flag == 0)
			{
				m2 = haffTree[j].weight;
				x2 = j;
			}
		}
		//将找出的两棵权值最小的子树合并为一棵子树
		haffTree[x1].parent = n + i;
		haffTree[x2].parent = n + i;
		haffTree[x1].flag = 1;//表示都已经加入hafftree
		haffTree[x2].flag = 1;
		haffTree[n + i].weight = haffTree[x1].weight + haffTree[x2].weight;
		haffTree[n + i].leftChild = x1;
		haffTree[n + i].rightChild = x2;
	}
}

//构造哈夫曼编码
//结点为n
void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[])
{
	Code* cd = (Code*)malloc(sizeof(Code));
	int i, j, child, parent;

	//求n个叶节点的哈夫曼编码
	for (i = 0; i < n; i++)
	{
		cd->start = n - 1;
		cd->weight = haffTree[i].weight;
		child = i;
		parent = haffTree[child].parent;
		//由叶结点向上直到根结点
		while (parent != 0)
		{
			if (haffTree[parent].leftChild == child)
			{
				cd->bit[cd->start] = 0;//左孩子分支编码
			}
			else
			{
				cd->bit[cd->start] = 1;//右孩子分支编码
			}
			cd->start--;
			child = parent;
			parent = haffTree[child].parent;
		}
		for (j = cd->start + 1; j < n; j++)
		{
			haffCode[i].bit[j] = cd->bit[j];//保存每个叶节点的编码
		}
		haffCode[i].start = cd->start;//保存不等长编码的起始位
		haffCode[i].weight = cd->weight;//保存相应字符的权值
	}
}

void OutPut(int n, Code haffCode[])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("weight=%d   Code=", haffCode[i].weight);
		for (j = haffCode[i].start + 1; j < n; j++)
		{
			printf("%6d", haffCode[i].bit[j]);
		}
		printf("\n");
	}
}

int main()
{
	int i, j, n;
	printf("请输入叶结点个数：");
	scanf("%d", &n);
	int weight[MaxN];
	printf("\n请输入各结点权值：");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}
	HaffNode* myHaffTree = (HaffNode*)malloc(sizeof(HaffNode) * (2 * n + 1));
	Code* myHaffCode = (Code*)malloc(sizeof(Code) * n);
	Haffman(weight, n, myHaffTree);
	HaffmanCode(myHaffTree, n, myHaffCode);
	OutPut(n, myHaffCode);
	return 0;
}