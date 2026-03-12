#define _CRT_SECURE_NO_WARNINGS
//输入节点数量，先序中序，输出树
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 999;
int n;//结点数量
int F[N];//先序
int M[N];//中序
int L[N];//后序

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

void InPut_FM()
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &F[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &M[i]);
	}
}

void InPut_ML()
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &M[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &L[i]);
	}
}

//后 中 求先
void L_M_Ftree(int* m, int* l, int length)//中序序列，后序序列，中序中需要寻找的字段长度
{
	if (length == 0)return;

	BiTree t = new BiTNode;
	t->data = l[length - 1];//后序中找到根节点

	//中序中找到根节点
	int root;
	for (root = 0; root < length; root++)
	{
		if (m[root] == t->data)break;
	}

	printf("%d ", t->data);
	L_M_Ftree(m, l, root);
	L_M_Ftree(m + root + 1, l + root, length - (root + 1));
}

//先 中 求后
void F_M_Ltree(int* m, int* f, int length)//中序序列，先序序列，中序中需要寻找的字段长度
{
	if (length == 0)return;

	BiTree t = new BiTNode;//新建一个节点，节点的数据为先序的首个元素
	t->data = *f;//先序中找到根节点

	//找根节点在中序数组中的下标
	int root;
	for (root = 0; root < length; root++)
	{
		if (m[root] == *f)break;
	}

	//后序遍历输出结果
	F_M_Ltree(m, f + 1, root);//中序的左边一半长度作为新的需要寻找的字段长度
	F_M_Ltree(m + root + 1, f + root + 1, length - (root + 1));//中序的后面一段长度作为需要寻找的字段长度
	printf("%d ", t->data);
}

int main()
{
	int i;
	printf("1.先序中序求后序。\n2.后序中序求先序。\n");
	while (~scanf("%d", &i))
	{
		if (i == 1)
		{
			printf("请输入 结点数 先序 中序:\n");
			InPut_FM();
			F_M_Ltree(M, F, n);
		}
		else
		{
			printf("请输入 结点数 中序 后序:\n");
			InPut_ML();
			L_M_Ftree(M, L, n);
		}
		printf("\n\n");
		printf("1.先序中序求后序。\n2.后序中序求先序。\n");
	}
	return 0;
}
