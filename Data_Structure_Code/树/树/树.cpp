#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef char datatype;

typedef struct node
{
	datatype data;
	struct node* lchild, * rchild;
}Bnode;

//前序遍历构造二叉树
//输入数据abd##g##，#代表空树
//1.创建根节点。2.递归左子树。3.递归右子树
Bnode* F_CreateBiTree()
{
	datatype ch;
	Bnode* T;
	ch=getchar();
	if (ch == '#')//空树
	{
		T = NULL;
	}
	else
	{
		if (!(T = (Bnode*)malloc(sizeof(Bnode))))return NULL;//分配内存是否成功
		T->data = ch;//生成根结点
		T->lchild = F_CreateBiTree();//递归构造左子树
		T->rchild = F_CreateBiTree();//递归构造右子树
	}
	return T;//返回根结点
}

//插入左孩子
// 把x写进结点curr的左孩子结点
//1.判断curr是否为空。2.q储存curr原左子树。3.创建新结点p。4.p插入curr
Bnode* InsertLeftNode(Bnode* curr, datatype x)
{
	Bnode* p, * q;
	if (curr == NULL)return NULL;//先判断curr是否为空
	q = curr->lchild;//储存原左子树
	//创建新结点p
	p = (Bnode*)malloc(sizeof(Bnode));
	if (p == NULL)return NULL;
	p->data = x;
	p->lchild = q;
	p->rchild = NULL;
	//p插入curr
	curr->lchild = p;
	return curr->lchild;
}

//插入右孩子
//把x写进结点curr的右孩子结点
//1.判断curr是否为空。2.q储存curr原右子树。3.创建新结点p。4.p插入curr
Bnode* InsertRightNode(Bnode* curr, datatype x)
{
	Bnode* p, * q;
	if (curr == NULL)return NULL;
	q = curr->rchild;
	p = (Bnode*)malloc(sizeof(Bnode));
	if (p == NULL)return NULL;
	p->data = x;
	p->lchild = NULL;
	p->rchild = q;
	curr->rchild = p;
	return curr->rchild;
}

//销毁
//将根结点为root的子树销毁
void Destory(Bnode** root)
{
	if ((*root) != NULL && (*root)->lchild != NULL)
	{
		Destory(&(*root)->lchild);//递归删左结点
	}
	if ((*root) != NULL && (*root)->rchild != NULL)
	{
		Destory(&(*root)->rchild);//递归删右结点
	}
	free(*root);
}

//销毁
//将curr结点的左子树销毁
Bnode* DeleteLeftTree(Bnode* curr)
{
	if (curr == NULL || curr->lchild == NULL)
	{
		return NULL;
	}
	Destory(&curr->lchild);
	curr->lchild = NULL;
	return curr;
}

//销毁
//将curr结点的右子树销毁
Bnode* DeleteRightTree(Bnode* curr)
{
	if (curr == NULL || curr->rchild == NULL)
	{
		return NULL;
	}
	Destory(&curr->rchild);
	curr->rchild = NULL;
	return curr;
}

//拷贝
//将orginal拷贝到temp上
//1.为temp开辟新空间。2.递归左子树。3.递归右子树
Bnode* Copy(Bnode* original)
{
	Bnode* temp;
	if (original)
	{
		temp = (Bnode*)malloc(sizeof(Bnode));
		if (temp == NULL)
		{
			printf("The Memory is Full\n");
			return NULL;
		}
		temp->lchild = Copy(original->lchild);
		temp->rchild = Copy(original->rchild);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}

//判断两颗树是否等价
//1.若根节点都存在，则判断根结点是否相等。2.递归根节点左孩子。3.递归根节点右孩子。4.直到没有结点为止
int Equal(Bnode* first, Bnode* second)
{
	return((!first && !second)//如果没有结点了就返回退出
		|| (first && second//如果两树结点都存在
			&& (first->data == second->data)//判两结点是否相等
			&& Equal(first->lchild, second->lchild)//递归左右子树
			&& Equal(first->rchild, second->lchild)));
}

//先序遍历
//从上往下访问根节点，先遍历左子树，再右子树
void preorder(Bnode* root)
{
	if (root)
	{
		printf("%6c", root->data);//∵从上往下，∴先输出
		preorder(root->lchild);//先遍历左子树
		preorder(root->rchild);//再遍历右子树
	}
}

//中序遍历
//在每一个小树中：1.从根遍历左子树。2.遍历根结点。3.从根遍历右子树
void inorder(Bnode* root)
{
	if (root)
	{
		inorder(root->lchild);
		printf("%6c", root->data);
		inorder(root->rchild);
	}
}

//后序遍历
//在每一颗小树中：1.从根遍历左子树。2.从根遍历右子树。3.访问根结点
void postorder(Bnode* root)
{
	if (root)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%6c", root->data);
	}
}

void Catalugue()
{
	printf("1.根据先序构造二叉树。\n2.插入左孩子。\n3.插入右孩子。\n4.销毁子树。\n5.销毁右子树。\n");
	printf("6.销毁左子树。\n7.拷贝。\n8.判断两树是否等价。\n9.先序遍历。\n10.中序遍历。\n11.后序遍历。\n");
}


int main()
{
	Catalugue();
	int t;
	Bnode *root1,*root2;
	root1 = (Bnode*)malloc(sizeof(Bnode));
	root2 = (Bnode*)malloc(sizeof(Bnode));
	while (~scanf("%d", &t))
	{
		getchar();
		if (t == 1)
		{
			printf("请输入先序序列：\n");
			root1 = F_CreateBiTree();
			printf("Success\n");
		}
		else if (t == 2)
		{
			printf("请输入要插入的内容：\n");
			char ch;
			scanf("%c", &ch);
			InsertLeftNode(root1, ch);
			printf("Success\n");
		}
		else if (t == 3)
		{
			printf("请输入要插入的内容：\n");
			char ch;
			scanf("%c", &ch);
			InsertRightNode(root1, ch);
			printf("Success\n");
		}
		else if (t == 4)
		{
			Destory(&root1);
			printf("Success\n");
		}
		else if (t == 5)
		{
			DeleteLeftTree(root1);
			printf("Success\n");
		}
		else if (t == 6)
		{
			DeleteRightTree(root1);
			printf("Success\n");
		}
		else if (t == 7)
		{
			root2 = Copy(root1);
			printf("Success\n");
		}
		else if (t == 8)
		{
			printf("%d\n", Equal(root1, root2));
			printf("Success\n");
		}
		else if (t == 9)
		{
			preorder(root1);
			printf("\n");
			printf("Success\n");
		}
		else if (t == 10)
		{
			inorder(root1);
			printf("\n");
			printf("Success\n");
		}
		else if (t == 11)
		{
			postorder(root1);
			printf("\n");
			printf("Success\n");
		}
		Catalugue();
	}
	return 0;
}