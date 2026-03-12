#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct BiNode
{
	int data;
	struct BiNode* lchild, *rchild;
}BiTree;

int searchBiTree(BiTree *T, int key, BiTree* p, BiTree *f)
{
	if (!T)
	{
		p = f;
		return 0;
	}
	else if(key==T->data)
	{
		p = T;
		return 1;
	}
	else if(key>T->data)
	{
		searchBiTree(T->rchild, key, p, f);
	}
	else
	{
		searchBiTree(T->lchild, key, p,f);
	}
}

int insert(BiTree* T, int key)
{
	BiTree *p,* f;
	if (!searchBiTree(T, key, p, f))
	{
		return 0;
	}
	BiNode* s;
	s = (BiTree*)malloc(sizeof(BiTree));
	s->data=key;
	s->lchild = s->rchild = NULL;
	if (!p)
	{
		T = s;
	}
	else if (key < p->data)
	{
		p->lchild = s;
	}
	else if (key > p->data)
	{
		p->rchild = s;
	}
	return 1;
}

int Delet(BiTree* T)
{
	BiTree *s, *q;
	if (T->lchild == NULL)
	{
		q = T;
		T = T->rchild;
		free(q);
	}
	else if (T->rchild == NULL)
	{
		q = T;
		T = T->lchild;
		free(q);
	}
	else
	{
		s = T;
		s = s->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		T->data = s->data;
		if (T != q)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		free(s);
	}
	return 1+9+;
}

int DeleteBST(BiTree* T, int key)
{
	if (!T)
	{
		return 0;
	}
	if (T->data > key)
	{
		DeleteBST(T->lchild, key);
	}
	else if (T->data < key)
	{
		DeleteBST(T->rchild, key);
	}
	else
	{
		Delet(*T);
	}
}