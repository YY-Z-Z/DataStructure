#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//定义二叉树结构
typedef struct BiTNode
{
	int data;
	int bf;//平衡因子
	struct BiTNode* lchild, *rchild;
}BiTNode,*BiTree;

typedef struct BiTNode2
{
	int data;
	struct BiTNode2* lchild, * rchild;
}BiTNode2, * BiTree2;

//二叉平衡树
//对以P为根的二叉排列树右旋处理
void R_Rotate(BiTree* P)
{
	BiTree L;
	L = (*P)->lchild;//原左结点变爸爸
	(*P)->lchild = L->rchild;
	L->rchild = (*P);
	*P = L;//P指向新结点
}
//对以P为根的二叉排列树左旋处理
void L_Rotate(BiTree* P)
{
	BiTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->lchild;
	R->lchild = (*P);
	*P = R;
}

#define LH 1 //左高
#define EH 0 //等高
#define RH -1 //右高
//对T结点为根左平衡旋转处理
//结束时，T指向新的根结点
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;//L指向T的左子树根节点
	switch (L->bf)//检查T左子树平衡度，并做相应平衡处理
	{
	 case LH://新结点插入在T左孩子的右子树上，需单右旋处理
		(*T)->bf = L->bf = EH;//单右旋后更新平衡因子
		R_Rotate(T);
		break;
	 case RH://新结点插入T左孩子的右子树上，需双旋处理
		Lr = L->rchild;//Lr指向T左孩子的右子树根
		switch (Lr->bf)//修改T及其左孩子的平衡因子
		{
		case LH:(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:(*T)->bf = L->bf = EH;
			break;
		case RH:(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);//T左子树左旋平衡处理
		R_Rotate(T);//T右旋平衡处理
	}
}
//右平衡旋转处理
void RightBalance(BiTree* T)
{
	BiTree R, RL;
	R = (*T)->rchild;
	switch (R->bf)
	{
	case RH:
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		RL = R->lchild;
		switch (RL->bf)
		{
		case RH:(*T)->bf = LH;
			R->bf = EH;
			break;
		case EH:(*T)->bf = R->bf = EH;
			break;
		case LH:(*T)->bf = EH;
			R->bf = RH;
			break;
		}
		RL->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
	}
}
//平衡二叉树主函数
//插入新结点e，树长高，置taller为true(1)
int InsertAVL(BiTree* T, int e, int* taller)
{
	if (!*T)
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = 1;
	}
	else
	{
		if (e == (*T)->data)//已存在相同关键字结点，则不再插入
		{
			*taller = 0;
			return 0;
		}
		if (e < (*T)->data)
		{
			if (!InsertAVL(&(*T)->lchild, e, taller))//插入不成功
			{
				return 0;
			}
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					LeftBalance(T);
					*taller = 0;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = 1;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = 0;
					break;
				}
			}
		}
		else//T右子树搜索
		{
			if (!InsertAVL(&(*T)->rchild, e, taller))
			{
				return 0;
			}
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					*taller = 0;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = 1;
					break;
				case RH:
					RightBalance(T);
					*taller = 0;
					break;
				}
			}
		}
	}
	return 1;
}

void find1(BiTree *T, int x,int count)
{
	if (!T)return;
	if ((*T)->data == x)
	{
		printf("平衡二叉树查找次数：%d\n",count);
		return;
	}
	if ((*T)->data < x)
	{
		count++;
		find1(&(*T)->rchild, x,count);
	}
	else
	{
		count++;
		find1(&(*T)->lchild, x,count);
	}
}


//二叉排列树
//查找是否存在key
int SearchBST(BiTree2 T, int key, BiTree2 f, BiTree2* p,int c)
{
	if (!T)
	{
		*p = f;
		return 0;
	}
	else if (key == T->data)
	{
		printf("二叉排列树的查找次数：%d\n",c);
		*p = T;
		return 1;
	}
	else if (key < T->data)
	{
		c++;
		return SearchBST(T->lchild, key, T, p,c);
	}
	else
	{
		c++;
		return SearchBST(T->rchild, key, T, p,c);
	}
}
//插入操作
int InsertBST(BiTree2* T, int key)
{
	BiTree2 p, s;
	int c = 0;
	if (!SearchBST(*T, key, NULL, &p,c))
	{
		s = (BiTree2)malloc(sizeof(BiTNode2));
		s->data = key;
		s->lchild = s->rchild=NULL;
		if (!p)
		{
			*T = s;
		}
		else if (key < p->data)
		{
			p->lchild = s;
		}
		else
		{
			p->rchild = s;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i;
	int a[10] = { 3,2,1,4,5,6,7,10,9,8 };
	//二叉平衡树
	BiTree T = NULL;
	int taller;
	for (i = 0; i < 10; i++)
	{
		InsertAVL(&T, a[i], &taller);
	}
	//二叉排列树
	BiTree2 T2 = NULL,p;
	for (i = 0; i < 10; i++)
	{
		InsertBST(&T2, a[i]);
	}
	printf("请输入需要查找的数：\n");
	int x;
	while (~scanf("%d", &x))
	{
		int count = 0;
		find1(&T, x,count);
		int c = 0;
		SearchBST(T2, x, NULL, &p, c);
	}
	return 0;
}