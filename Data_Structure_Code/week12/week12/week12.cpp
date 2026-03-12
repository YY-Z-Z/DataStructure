#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
char s[999];
int l[999] = { 0 }, r[999] = { 0 }, si, ni;
typedef struct BiNode
{
	char data;
	struct BiNode* lchild, * rchild;
}BiNode,*BiTree;
BiNode* Creat(int ii)
{
	BiNode *T;
	char ch = s[ii];
	if (ch == '0'||ch=='\0')
	{
		T = NULL;
	}
	else 
	{
		if (!(T = (BiNode*)malloc(sizeof(BiNode))))return NULL;
		T->data = ch;
		T->lchild = Creat(2*ii);
		T->rchild = Creat(2*ii+1);
	}
	return T;
}
void preorder(BiNode* T)
{
	if (T)
	{
		printf("%c", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
void inorder(BiNode* T)
{
	if (T)
	{
		inorder(T->lchild);
		printf("%c", T->data);
		inorder(T->rchild);
	}
}
void postorder(BiNode* T)
{
	if (T)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c", T->data);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	l[0] = r[0] = 1;
	while (n--)
	{
		BiNode* T;
		ni=si = 1;
		int m,i;
		scanf("%d", &m);
		getchar();
		for (i = 1; i <= m; i++)
		{
			scanf("%c %d%d", &s[i], &l[i], &r[i]);
			getchar();
		}
		T=Creat(s[1]);
		preorder(T);
		printf("\n");
		inorder(T);
		printf("\n");
		postorder(T);
		printf("\n");
	}
	return 0;
}