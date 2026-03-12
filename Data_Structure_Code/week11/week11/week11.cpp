#define _CRT_SECURE_NO_WARNINGS
//A
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BiTNode
//{
//	 char data;
//	struct BiTNode* lchild, * rchild;
//}BiTNode,*BiTree;
////前序创建
//BiTNode *CreatTree()
//{
//	BiTNode *T;
//	char ch;
//	ch=getchar();
//	if (ch == '#')
//	{
//		T = NULL;
//}
//	else
//	{
//		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))return NULL;
//		T->data = ch;
//		T->lchild = CreatTree();
//		T->rchild = CreatTree();
//	}
//	return T;
//}
////中序遍历
//void InOderTraverse(BiTNode *T)
//{
//	if (T)
//	{
//		InOderTraverse(T->lchild);
//		printf("%c", T->data);
//		InOderTraverse(T->rchild);
//	}
//}
////后序遍历
//void PostOderTraverse(BiTree T)
//{
//	if (T == NULL)return;
//	PostOderTraverse(T->lchild);
//	PostOderTraverse(T->rchild);
//	printf("%c", T->data);
//}
//
//typedef struct Quene
//{
//	int front;//队头指针
//	int rear;//队尾指针
//	BiTNode* data[2001];
//}SqQuene;
////return 1为空
//int EmptyQueue(SqQuene* q)
//{
//	if (q->front == q->rear)return 1;
//	return 0;
//}
//void inQuene(SqQuene* q, BiTNode* node)
//{
//	q->data[q->rear++] = node;
//}
//void outQuene(SqQuene* q)
//{
//	if (q->front==q->rear)return;
//	q->front++;
//}
//
//void LevelOrder(BiTNode *T)
//{
//	BiTree p = T;
//	SqQuene* q;
//	if (!(q = (SqQuene*)malloc(sizeof(SqQuene))))return;
//	q->front = 0;
//	q->rear = 0;
//	inQuene(q, p);
//	while (EmptyQueue(q) == 0)
//	{
//		p = q->data[q->front];
//		printf("%c", p->data);
//		outQuene(q);
//		if (p->lchild != NULL)
//			inQuene(q, p->lchild);
//		if (p->rchild != NULL)
//			inQuene(q, p->rchild);
//	}
//}
//int main()
//{
//	BiTNode *T;
//	T = (BiTNode*)malloc(sizeof(BiTNode));
//	T=CreatTree();
//	InOderTraverse(T);
//	printf(" ");
//	PostOderTraverse(T);
//	printf(" ");
//	LevelOrder(T);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct BiTNode {
//    char data;
//    struct BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;
//int z = 0;
//void CreateBiTree(BiTree T, char* m)
//{
//    char data;
//    data = m[z];
//    z++;
//    if (data == '#')
//        T = NULL;
//    else
//    {
//        T = (BiTree)malloc(sizeof(BiTNode));
//        T->data = data;
//        CreateBiTree(T->lchild, m); 
//        CreateBiTree(T->rchild, m);
//    }
//}
//void Visit(BiTree T)
//{
//    if (T->data != '#')
//        printf("%c", T->data);
//}
//void InOrder(BiTree T)
//{
//    if (T != NULL)
//    {
//        InOrder(T->lchild);
//        Visit(T);
//        InOrder(T->rchild);
//    }
//
//}
//void PostOrder(BiTree T)
//{
//    if (T != NULL)
//    {
//        PostOrder(T->lchild);
//        PostOrder(T->rchild);
//        Visit(T);
//    }
//}
//typedef struct Quene
//{
//	int front;//队头指针
//	int rear;//队尾指针
//	BiTNode* data[2001];
//}SqQuene;
////return 1为空
//int EmptyQueue(SqQuene* q)
//{
//	if (q->front == q->rear)return 1;
//	return 0;
//}
//void inQuene(SqQuene* q, BiTNode* node)
//{
//	q->data[q->rear++] = node;
//}
//void outQuene(SqQuene* q)
//{
//	if (q->front==q->rear)return;
//	q->front++;
//}
//
//void LevelOrder(BiTree T)
//{
//    BiTree p = T;
//    SqQuene *q;
//    if (!(q = (SqQuene*)malloc(sizeof(SqQuene))))return;
//    q->front = 0;
//    q->rear = 0;
//    inQuene(q, p);
//    while (EmptyQueue(q)==0)
//    {
//        p =q->data[q->front];
//        printf("%c", p->data);
//        outQuene(q);
//        if (p->lchild != NULL)
//            inQuene(q,p->lchild);
//        if (p->rchild != NULL)
//            inQuene(q,p->rchild);
//    }
//}
//int main()
//{
//    BiTNode T;
//    char s[2050];
//    int i, len;
//    scanf("%s", s);
//    len = strlen(s);
//        for (i = 0; i <= len - 1; i++)
//            if (s[i] != '#')
//                break;
//        if (i == len) {
//            printf("\n");
//        }
//        CreateBiTree(T, s);
//        InOrder(T);
//        printf("%c", 32);
//        PostOrder(T);
//        printf("%c", 32);
//        LevelOrder(T);             
//    return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BiTNode
//{
//	int data;
//	struct BiTNode* lchild, * rchild;
//}BiTNode,*BiTree;
//int f = 0;
//typedef struct Queue
//{
//	int 
//};
//void preorder(BiTNode *T)
//{
//	if (T!=NULL)
//	{
//		printf("%d ", T->data);
//		preorder(T->lchild);
//		preorder(T->rchild);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		BiTNode* T;
//		T = (BiTNode*)malloc(sizeof(BiTNode));
//		T = Creat();
//		preorder(T);
//		f = 0;
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
////队列结构体
//typedef struct
//{
//	int data[99999];
//	int front;//头指针
//	int rear;//尾指针
//}SqQueue;
////初始化
//void InitQueue(SqQueue* Q)
//{
//	Q->front = 0;
//	Q->rear = 0;
//}
////元素个数，即当前队列长度
//int QueueLength(SqQueue Q)
//{
//	return (Q.rear - Q.front);
//}
////插入新队尾元素
//void EnQueue(SqQueue* Q, int e)
//{
//	if (Q->rear + 1 == Q->front)//队列满的判断
//		return;
//	Q->data[Q->rear] = e;//队尾插入新元素
//	Q->rear++;
//}
////删除队首元素
//void DeQueue(SqQueue* Q, int* e)
//{
//	if (Q->front == Q->rear)return;//队空判断
//	*e = Q->data[Q->front];
//	Q->front++;
//}
////输出队列
//void PutOut(SqQueue* Q)
//{
//	int i;
//	for (i = Q->front; i < Q->rear; i++)
//	{
//		printf("%d ", Q->data[i]);
//	}
//}
//void catalogue()
//{
//	printf("1.队列长度。\n2.插入新元素。\n3.删除队首元素。\n");
//}
//int main()
//{
//	int n;
//	SqQueue Q;
//	InitQueue(&Q);
//	catalogue();
//	while (~scanf("%d", &n))
//	{
//		if (n == 1)
//		{
//			printf("%d",QueueLength(Q));
//		}
//		else if (n == 2)
//		{
//			printf("请输入新元素的值：\n");
//			int e;
//			scanf("%d", &e);
//			EnQueue(&Q, e);
//		}
//		else if (n == 3)
//		{
//			int e;
//			DeQueue(&Q, &e);
//			printf("已经成功删除队首元素：\n");
//			printf("%d\n", e);
//		}
//		printf("\n");
//		PutOut(&Q);
//		printf("\n\n");
//		catalogue();
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BTNode
//{
//	int data;
//	struct BTNode* lchild, * rchild;
//}BTNode;
//typedef struct Queue
//{
//	BTNode data[99999];
//	int rear, front;
//}Queue;
//void InitQueue(Queue *Q)
//{
//	Q->front = 0;
//	Q->rear = 0;
//}
//void EnQueue(Queue* Q, BTNode e)
//{
//	if (Q->rear + 1 == Q->front)return;
//	Q->data[Q->rear] = e;
//	Q->rear++;
//}
//BTNode DeQueue(Queue* Q)
//{
//	return Q->data[Q->front++];
//}
//int EmptyQueue(Queue* Q)
//{
//	if (Q->front == Q->rear)return 1;
//	return 0;
//}
//int f = 0;
//BTNode *Create()
//{
//	int data;
//	BTNode *BT, *CT;
//	Queue Q;
//	InitQueue(&Q);
//	int num;
//	scanf("%d", &num);
//	if (num == -1)
//	{
//		return NULL;
//	}
//	else if(num!=0)
//	{
//		BT = (BTNode*)malloc(sizeof(BTNode));
//		BT->data = num;
//		BT->lchild = BT->rchild = NULL;
//		EnQueue(&Q, *BT);
//	}
//	else
//	{
//		return NULL;
//	}
//	while (EmptyQueue(&Q) == 0)
//	{
//		CT = (BTNode*)malloc(sizeof(BTNode));
//		*CT=DeQueue(&Q);
//		int da;
//		if (f == 0)
//		{
//			scanf("%d", &da);
//			if (da == 0)
//			{
//				CT->lchild == NULL;
//			}
//			else if (da == -1)
//			{
//				f = 1;
//				CT->lchild == NULL;
//			}
//			else 
//			{
//				CT->lchild = (BTNode*)malloc(sizeof(BTNode));
//				CT->lchild->data = da;
//				CT->lchild->lchild = CT->lchild->rchild = NULL;
//				EnQueue(&Q, *CT->lchild);
//			}
//		}
//		if (f == 0)
//		{
//			scanf("%d", &da);
//			if (da == 0)
//			{
//				CT->rchild == NULL;
//			}
//			else if (da == -1)
//			{
//				f = 1;
//				CT->rchild == NULL;
//			}
//			else
//			{
//				CT->rchild = (BTNode*)malloc(sizeof(BTNode));
//				CT->rchild->data = da;
//				CT->rchild->lchild = CT->rchild->rchild = NULL;
//				EnQueue(&Q, *CT->rchild);
//			}
//		}
//	}
//	return BT;
//}
//void PreOrderT(BTNode* T)
//{
//	if (T == NULL)return;
//	printf("%d ", T->data);
//	PreOrderT(T->lchild);
//	PreOrderT(T->rchild);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		f = 0;
//		BTNode *T;
//		T=Create();
//		PreOrderT(T);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BTNode
//{
//	int data;
//	struct BTNode* lchild, * rchild;
//}BTNode,*BTree;
//int a[9999];
//BTNode *CreatBT(int i)
//{
//	BTNode* T;
//	if (i > a[0] || a[i] == 0)
//	{
//		T = NULL;
//		return NULL;
//	}
//	T = (BTNode*)malloc(sizeof(BTNode));
//	T->data = a[i];
//	T->lchild=CreatBT(i*2);
//	T->rchild=CreatBT(i * 2 + 1);
//	return T;
//}
//void preorder(BTNode* T)
//{
//	if (T)
//	{
//		printf(" %d", T->data);
//		preorder(T->lchild);
//		preorder(T->rchild);
//	}
//}
//int depth(BTNode *T)
//{
//	int depl, depr;
//	if (T==NULL)return 0;
//		depl = depth(T->lchild)+1;
//		depr = depth(T->rchild)+1;
//		return depl > depr ? depl : depr;
//	
//
//}
//int main()
//{
//	BTNode *T;
//	T = NULL;
//	int n, x;
//	scanf("%d", &n);
//	while (n--)
//	{
//		a[0] = 0;
//		while (scanf("%d", &x), x != -1)
//		{
//			a[++a[0]] = x;
//		}
//		T=CreatBT(1);
//			printf("%d", depth(T));
//			preorder(T);
//			printf("\n");
//	}
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BTNode
//{
//	int data;
//	struct BTNode* lchild, * rchild;
//}BTNode,*BTree;
//int a[9999];
//BTNode *CreatBT(int i)
//{
//	BTNode* T;
//	if (i > a[0] || a[i] == 0)
//	{
//		T = NULL;
//		return NULL;
//	}
//	T = (BTNode*)malloc(sizeof(BTNode));
//	T->data = a[i];
//	T->lchild=CreatBT(i*2);
//	T->rchild=CreatBT(i * 2 + 1);
//	return T;
//}
//void preorder(BTNode* T)
//{
//	if (T)
//	{
//		preorder(T->lchild);
//		printf(" %d", T->data);
//		preorder(T->rchild);
//	}
//}
//int depth(BTNode *T)
//{
//	int depl, depr;
//	if (T==NULL)return 0;
//		depl = depth(T->lchild)+1;
//		depr = depth(T->rchild)+1;
//		return depl > depr ? depl : depr;
//	
//
//}
//int main()
//{
//	BTNode *T;
//	T = NULL;
//	int n, x;
//	scanf("%d", &n);
//	while (n--)
//	{
//		a[0] = 0;
//		while (scanf("%d", &x), x != -1)
//		{
//			a[++a[0]] = x;
//		}
//		T=CreatBT(1);
//			printf("%d", depth(T));
//			preorder(T);
//			printf("\n");
//	}
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//char s1[9999], s2[9999];
//int cnt=0;
//void Tree(int l, int r, char ch)
//{
//	int i;
//	if (l > r)return;
//	for (i = l; s2[i] != ch; i++);
//	if (l < i)
//	{
//		Tree(l, i, s1[cnt++]);
//	}
//	if (i + 1 < r)
//	{
//		Tree(i + 1, r, s1[cnt++]);
//	}
//	printf("%c", ch);
//}
//int main()
//{
//	while (scanf("%s %s", s1, s2) != EOF)
//	{
//		cnt = 0;
//		Tree(0, strlen(s1), s1[cnt++]);
//		printf("\n");
//	}
//	return 0;
//}

//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[999], b[999];
//	scanf("%s %s", a, b);
//	int len = strlen(a);
//	int i, j,sum=1;
//	for (i = 0; i < len;)
//	{
//		for (j = 0; j < len; j++)
//		{
//			if (a[i] == b[j])break;
//		}
//		while (1)
//		{
//			i++;
//			j--;
//			if (i >= len || j < 0)break;
//			if (a[i] == b[j])
//			{
//				sum = sum * 2;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BTNode
//{
//	int data;
//	struct BTNode* lchild, * rchild;
//}BTNode;
//int k = 1,n,deep=1;
//BTNode* Creat()
//{
//	BTNode* T;
//		if (!(T = (BTNode*)malloc(sizeof(BTNode))))return NULL;
//		T->data = 1;
//		Creat2(T);
//		for (k = 1; k < n; k++)
//		{
//			if (k % 2 == 1)
//			{
//				Creat2(T->lchild);
//			}
//			else
//			{
//				 Creat2(T->rchild);
//			}
//}
//	return T;
//}
//
//void Creat2(BTNode *T)
//{
//	int x, y;
//	if (!(T->rchild = (BTNode*)malloc(sizeof(BTNode))))return NULL;
//	if (!(T->lchild = (BTNode*)malloc(sizeof(BTNode))))return NULL;
//	scanf("%d%d", &x, &y);
//	if (x != 0 || y != 0)deep++;
//	if (x != 0)
//	{
//		T->lchild->data = x;
//	}
//	else
//	{
//		T->lchild = NULL;
//	}
//	if (y != 0)
//	{
//		T->rchild->data = y;
//	}
//	else
//	{
//		T->rchild = NULL;
//	}
//}
//int main()
//{
//	scanf("%d", &n);
//	Creat();
//	printf("%d", deep);
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	int n,deep=1;
//	scanf("%d", &n);
//	int num_c = 1,x,y,f=0;
//	int j = 0;
//	while (j< n)
//	{
//		for (int i=1; i <= num_c&&j<=n ; i++)
//		{
//			scanf("%d%d", &x, &y);
//			j++;
//			if (f == 0 && (x != 0 || y != 0))
//			{
//				deep++;
//				f = 1;
//			}
//		}
//		f = 0;
//		num_c = num_c * 2;
//	}
//	printf("%d", deep);
//	return 0;
//}

//
//#include <stdio.h>
//#include<string.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		char s[9999];
//		int a[9999] = { 0 };
//		int num_c = 0, i,sum=0,d=0;
//		scanf("%s", s);
//		for (i = 0; i < strlen(s); i++)
//		{
//			if (s[i] <= 'Z' && s[i] >= 'A')
//			{
//				a[num_c]++;
//			}
//			else if (s[i] == '(')
//			{
//				num_c++;
//				if (num_c > d)d = num_c;
//			}
//			else if (s[i] == ')')
//			{
//				num_c--;
//			}
//		}
//		for(i = 0; i <= d;i++)
//		{
//			sum += i * a[i];
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BiThrNode
//{
//	char data;
//	int LTag;
//	int RTag;
//	struct BiThrNode* lchild, * rchild;
//}BiThrNode,*BiThrTree;
//int i=-1;
//BiThrNode* Creat(char* str)
//{
//	BiThrNode* T;
//	if (str[++i] == ' ')
//	{
//		return NULL;
//	}
//	else
//	{
//		if (!(T = (BiThrNode*)malloc(sizeof(BiThrNode))))return NULL;
//		T->data = str[i];
//		T->LTag = 0;
//		T->RTag = 0;
//		T->lchild = Creat(str);
//		T->rchild = Creat(str);
//	}
//	return T;
//}
//BiThrTree pre=(BiThrNode*)malloc(sizeof(BiThrNode));
//void preThreading(BiThrTree p)
//{
//	if (p)
//	{
//		if (!p->lchild)
//		{
//			p->LTag = 1;
//			p->lchild = pre;
//		}
//		if (pre&&pre->rchild==NULL)
//		{
//			pre->RTag = 1;
//			pre->rchild = p;
//		}
//		pre = p;
//		if (p->LTag == 0)
//		{
//			preThreading(p->lchild);
//		}
//		if (p->RTag == 0)
//		{
//			preThreading(p->rchild);
//		}
//	}
//}
//void InOrderTraverse_Thr(BiThrTree T)
//{
//	if (T == NULL)return;
//	BiThrTree p;
//	p = T;
//	while (p)
//	{
//		while (p->LTag == 0)
//			p = p->lchild;
//		printf("%c", p->data);
//		while (p&&p->RTag == 1 )
//		{
//			p = p->rchild;
//			printf("%c", p->data);
//		}
//		p = p->rchild;
//	}
//}
//int main()
//{
//	pre->RTag = 1;
//	pre->rchild = NULL;
//	pre->LTag = 1;
//	pre->lchild = NULL;
//	int n;
//	scanf("%d", &n);
//	getchar();
//	BiThrNode* T;
//	while (n--)
//	{
//		char str[9999];
//		gets_s(str);
//		i = -1;
//		T=Creat(str);
//		preThreading(T);
//		InOrderTraverse_Thr(T);
//		printf("\n");
//	}
//	return 0;
//}

////
//#include <stdio.h>						
//#include <stdlib.h>
//typedef int ElementType;
//ElementType ERROR = -1;
//typedef enum { FALSE, TRUE } Boolean;
//typedef struct binode {
//	ElementType data;
//	struct binode* lchlid, * rchlid;
//} Binode, * bitree;
//typedef Binode* QElementType;
//typedef struct
//{
//	QElementType* data;
//	int front;
//	int rear;
//	int maxsize;
//}queue;
//void initqueue(queue* q, int maxsize)
//{
//	q->data = (QElementType*)malloc(maxsize * sizeof(QElementType));
//	if (!q->data)exit(1);
//	q->front = q->rear = 0;
//	q->maxsize = maxsize;
//
//}
//Boolean Isempty(queue* q)
//{
//	if (q->front == q->rear)return TRUE;
//	else return FALSE;
//}
//Boolean Isfull(queue* q)
//{
//	if ((q->rear + 1) % q->maxsize == q->front)return TRUE;
//	else return FALSE;
//}
//Boolean enqueue(queue* q, QElementType e)
//{
//	if (Isfull(q))return FALSE;
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxsize;
//	return TRUE;
//}
//Boolean dequeue(queue* q, QElementType* e)
//{
//	if (Isempty(q))return FALSE;
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxsize;
//	return TRUE;
//
//}
////----------------------------------------------------------------------------------------------------------------------------------
//void initbitree(bitree* t)
//{
//	*t = NULL;
//}
//void createbitree(bitree* t)
//{
//	ElementType ch, m, a, b;
//	scanf("%d", &m);
//	if (m == 0)
//	{
//		*t = NULL;
//	}
//	else
//	{
//		*t = (Binode*)malloc(sizeof(Binode));
//		if (!*t)exit(1);
//		(*t)->data = ch;
//		createbitree(&(*t)->lchlid);
//		createbitree(&(*t)->rchlid);
//	}
//	if (ch == '-')
//	{
//		return;
//	}
//}
//void destory(bitree* t)
//{
//	if (*t && (*t)->lchlid)
//		destory(&(*t)->lchlid);
//	if (*t && (*t)->rchlid)
//		destory(&(*t)->rchlid);
//	free(*t);
//	*t = NULL;
//}
//Boolean isempty(bitree* t)
//{
//	if (!t)return TRUE;
//	else return FALSE;
//}
//int bitreedepth(bitree t)
//{
//	int m, n;
//	if (t == NULL)return 0;
//	m = bitreedepth(t->lchlid);
//	n = bitreedepth(t->rchlid);
//	if (m > n)return m + 1;
//	else return n + 1;
//}
//Binode* root(bitree t)
//{
//	return t;
//}
//ElementType value(Binode* p)
//{
//	if (p)return p->data;


//#include<stdio.h>
//#include<stdlib.h>
////线索二叉树储存结构体
//typedef char TElemType;
//typedef enum {Link,Thread} PointerTag;//Link=0表示指向左右孩子指针，Thread表示指向前驱后继的线索
////线索二叉树储存结构
//typedef struct BiThrNode
//{
//    TElemType data;
//    struct BiThrNode* lchild, * rchild;
//    PointerTag LTag;//左右标志
//    PointerTag RTag;
//}BiThrNode,*BiThrTree;
//
//char s[9999];
//int si = 0;
////前序遍历创建二叉树
//void CreateBiTree(BiThrTree* T)
//{
//    char ch=s[si++];
//    if (ch == ' ')
//    {
//        *T=NULL;
//    }
//    else
//    {
//        *T = (BiThrTree)malloc(sizeof(BiThrNode));
//        if (!*T)return;
//        (*T)->data = ch;
//        (*T)->LTag = Link;
//        (*T)->RTag = Link;
//        CreateBiTree(&(*T)->lchild);
//        CreateBiTree(&(*T)->rchild);
//    }
//}
////BiThrNode* Creat()
////{
////    char ch = s[si++];
////    BiThrNode *T;
////    if (ch == ' ')
////    {
////        return NULL;
////    }
////    else
////    {
////        if (!(T = (BiThrNode*)malloc(sizeof(BiThrNode))))return NULL;
////        T->data = ch;
////        T->LTag = Link;
////        T->RTag = Link;
////        T->lchild = Creat();
////        T->rchild = Creat();
////    }
////    return T;
////}
////中序线索化
////BiThrTree pre;//全局变量，始终指向刚刚访问过的结点
//void InThreading(BiThrTree p,BiThrTree *pre)
//{
//    if (!p)return;
//        InThreading(p->lchild,pre);//递归左子树线索化
//        if (!p->lchild)//没有左孩子
//        {
//            p->LTag = Thread;//前驱线索
//            p->lchild = *pre;//左孩子指针指向前驱
//        }
//        if (!(*pre)->rchild)//前驱没有右孩子
//        {
//            (*pre)->RTag = Thread;//后继线索
//            (*pre)->rchild = p;//前驱右孩子指针指向后继（当前结点p）
//        }
//        *pre = p;//保持pre指向p的前驱
//        InThreading(p->rchild,pre);//递归右子树线索化
//}
//
////中序遍历线索二叉树
//void InOderTraverse_Thr(BiThrTree T)
//{
//    BiThrTree p;
//    p = T->lchild;//p指向根结点
//    while (p != T)//空树或遍历结束时，p==T
//    {
//        while (p->LTag == Link)//LTag==0时循环到中序序列第一个结点
//        {
//            p = p->lchild;
//        }
//        printf("%c", p->data);
//        while (p->RTag == Thread && p->rchild != T)
//        {
//            p = p->rchild;
//            printf("%c", p->data);//访问后继结点
//        }
//        p = p->rchild;//p进至其右子树根
//    }
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    getchar();
//    while (n--)
//    {
//        BiThrNode* T,*pre;
//        si = 0;
//        gets_s(s);
//        CreateBiTree(&T);
//        //T = Creat();
//        InThreading(T,&pre);
//        InOderTraverse_Thr(T);
//        printf("\n");
//    }
//    return 0;
//}
//    

//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//typedef char TElemType;
//int si;
//char str[9999];
//
//typedef struct BiThrNode 
//{
//    TElemType data;
//    struct BiThrNode* lchild, * rchild;
//    int LTag;
//    int RTag;
//}BiThrNode, * BiThrTree;
//
////线索二叉树初始化
//void CreateBiThrNode(BiThrTree* B)
//{
//    char ch;
//        ch = str[++si];
//        if (ch == ' ')
//        {
//            *B = NULL;
//        }
//    else 
//        {
//        if (!((*B) = (BiThrNode*)malloc(sizeof(BiThrNode))))return ;
//        (*B)->data = ch;
//        (*B)->LTag = 1;
//        (*B)->RTag = 1;
//        CreateBiThrNode(&(*B)->lchild);
//        CreateBiThrNode(&(*B)->rchild);
//    }
//}
//
////线索二叉树线索化
//void InThreading(BiThrTree B, BiThrTree* pre) 
//{
//    if (!B) return;
//
//    InThreading(B->lchild, pre);
//
//    if (!B->lchild) {
//        B->LTag = 0;
//        B->lchild = *pre;
//    }
//
//    if (!(*pre)->rchild) {
//        (*pre)->RTag = 0;
//        (*pre)->rchild = B;
//    }
//
//    *pre = B;
//    InThreading(B->rchild, pre);
//}
//
//////为线索二叉树添加头结点，使之可以双向操作
////void InOrderThreading(BiThrTree* Thrt, BiThrTree T) {
////    if (!(*Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) return;
////    (*Thrt)->LTag = 1;
////    (*Thrt)->RTag = 0;
////    (*Thrt)->rchild = (*Thrt);
////    if (!T) {
////        (*Thrt)->lchild = (*Thrt);
////        return ;       //若根结点不存在,则该二叉树为空,让该头结点指向自身.
////    }
////    BiThrTree pre;
////    //令头结点的左指针指向根结点
////    pre = (*Thrt);
////    (*Thrt)->lchild = T;
////    //开始递归输入线索化
////    InThreading(T, &pre);
////    //此时结束了最后一个结点的线索化了,下面的代码把头结点的后继指向了最后一个结点.
////    //并把最后一个结点的后继也指向头结点,此时树成为了一个类似双向链表的循环.
////    pre->rchild = *Thrt;
////    pre->RTag = 0;
////    (*Thrt)->rchild = pre;
////    return ;
////}
//
////非递归遍历线索二叉树
//void InOrderTraverse(BiThrTree T) {
//    BiThrNode* p = T->lchild;
//    while (p != T) {
//        while (p->LTag == 1) p = p->lchild;    //走向左子树的尽头
//        printf("%c", p->data);
//        while (p->RTag == 0 && p->rchild != T) {  //访问该结点的后续结点
//            p = p->rchild;
//            printf("%c", p->data);
//        }
//        p = p->rchild;
//    }
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    getchar();
//    while (n--)
//    {
//        si = -1;
//        gets_s(str);
//        int i=strlen(str);
//        str[i] = ' ';
//        str[i + 1] = '\0';
//        BiThrTree  T,pre;
//        CreateBiThrNode(&T);
//        InThreading(T, &pre);
//        InOrderTraverse(T);
//        printf("\n");
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct BiNode
//{
//	char data;
//	struct BiNode* lchild, *rchild;
//}BiNode,*BiTree;
//char str[999];
//int si;
//BiNode *Creat()
//{
//	BiNode *T;
//	char ch;
//	ch = str[++si];
//	if (ch == ' ')
//	{
//		return NULL;
//	}
//	else
//	{
//		if (!(T = (BiNode*)malloc(sizeof(BiNode))))return NULL;
//		T->data = ch;
//		T->lchild=Creat();
//		T->rchild = Creat();
//	}
//	return T;
//}
//void Inoderprint(BiNode* T)
//{
//	if (!T)return;
//	Inoderprint(T->lchild);
//	printf("%c", T->data);
//	Inoderprint(T->rchild);
//}
//int main()
//{
//	BiNode *T;
//	int n;
//	scanf("%d", &n);
//	getchar();
//	while (n--)
//	{
//		gets_s(str);
//		int i = strlen(str);
//		str[i] = ' ';
//		str[i + 1] = '\0';
//		si = -1;
//		T=Creat();
//		Inoderprint(T);
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>						
//#include <stdlib.h>
//typedef int ElementType;
//ElementType ERROR = -1;
//typedef enum { FALSE, TRUE } Boolean;
//typedef struct binode {
//	ElementType data;
//	struct binode* lchlid, * rchlid;
//} Binode, * bitree;
////----------------------------------------------------------------------------------------------------------------------------------
//typedef Binode* QElementType;
//typedef struct
//{
//	QElementType* data;
//	int front;
//	int rear;
//	int maxsize;
//}queue;
//void initqueue(queue* q, int maxsize)
//{
//	q->data = (QElementType*)malloc(maxsize * sizeof(QElementType));
//	if (!q->data)exit(1);
//	q->front = q->rear = 0;
//	q->maxsize = maxsize;
//
//}
//Boolean Isempty(queue* q)
//{
//	if (q->front == q->rear)return TRUE;
//	else return FALSE;
//}
//Boolean Isfull(queue* q)
//{
//	if ((q->rear + 1) % q->maxsize == q->front)return TRUE;
//	else return FALSE;
//}
//Boolean enqueue(queue* q, QElementType e)
//{
//	if (Isfull(q))return FALSE;
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxsize;
//	return TRUE;
//}
//Boolean dequeue(queue* q, QElementType* e)
//{
//	if (Isempty(q))return FALSE;
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxsize;
//	return TRUE;
//
//}
////----------------------------------------------------------------------------------------------------------------------------------
//void initbitree(bitree* t)
//{
//	*t = NULL;
//}
//void createbitree(bitree* t)
//{
//	ElementType ch, m, a, b;
//	scanf("%d", &m);
//	if (m == 0)
//	{
//		*t = NULL;
//	}
//	else
//	{
//		*t = (Binode*)malloc(sizeof(Binode));
//		if (!*t)exit(1);
//		(*t)->data = ch;
//		createbitree(&(*t)->lchlid);
//		createbitree(&(*t)->rchlid);
//	}
//	if (ch == '-')
//	{
//		return;
//	}
//}
//void destory(bitree* t)
//{
//	if (*t && (*t)->lchlid)
//		destory(&(*t)->lchlid);
//	if (*t && (*t)->rchlid)
//		destory(&(*t)->rchlid);
//	free(*t);
//	*t = NULL;
//}
//Boolean isempty(bitree* t)
//{
//	if (!t)return TRUE;
//	else return FALSE;
//}
//int bitreedepth(bitree t)
//{
//	int m, n;
//	if (t == NULL)return 0;
//	m = bitreedepth(t->lchlid);
//	n = bitreedepth(t->rchlid);
//	if (m > n)return m + 1;
//	else return n + 1;
//}
//Binode* root(bitree t)
//{
//	return t;
//}
//ElementType value(Binode* p)
//{
//	if (p)return p->data;
//}

//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BiNode
//{
//	int data;
//	struct BiNode* lchild, * rchild;
//}BiNode,*BiTree;
//typedef struct Queue
//{
//	BiNode* front;
//	BiNode* tail;
//	int size;
//}Queue;
//void InitQ(Queue* Q)
//{
//	if(!(Q = (Queue*)malloc(sizeof(Queue))))return;
//	Q->size = 9999;
//}
//void enQ(Queue* Q,BiNode e)
//{
//	if (Q->tail + 1 == Q->front)return;
//	*Q->tail = e;
//	Q->tail++;
//}
//void DeQ(Queue* Q)
//{
//	if (!Q)return;
//	Q->front++;
//}
//int Empty(Queue* Q)
//{
//	if (Q->front == Q->tail)
//	{
//		return 1;
//	}
//	return 0;
//}
//BiNode* Creat()
//{
//	BiNode *T;
//	int ch;
//	scanf("%d", &ch);
//	if (ch == 0)
//	{
//		T = NULL;
//	}
//	else
//	{
//		T = (BiNode*)malloc(sizeof(BiNode));
//		T->data = ch;
//		T->lchild = Creat();
//		T->rchild
//	}
//}
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node {
//    int data;
//    struct node* lchild, * rchild;
//}BinTree;
//BinTree* que[1000];
//int s[1000], ss = 0;
//int front = 0, rear = 0;
//int num;
//BinTree* CreateBiTree()
//{
//    int n = num;
//    int d, d1, d2;
//    BinTree* t, * bt, * q;
//    d = s[ss++];
//    if (d != 0 ) {
//        bt = (BinTree*)malloc(sizeof(BinTree));
//        bt->data = d;
//        bt->rchild = bt->lchild = NULL;
//        que[rear++] = bt;
//        n--;
//    }
//    else
//        return NULL;
//    while (n) {
//        t = que[front];
//        front++;
//        if (n == 0)
//            break;
//        d1 = s[ss++];
//        if (d1 != 0) {
//            q = (BinTree*)malloc(sizeof(BinTree));
//            q->data = d1;
//            t->lchild = q;
//            q->rchild = q->lchild = NULL;
//            que[rear++] = q;
//            n--;
//        }
//        else
//        {
//            t->lchild = NULL;
//        }
//            d2 = s[ss++];
//        if (d2 != 0) {
//            q = (BinTree*)malloc(sizeof(BinTree));
//            q->data = d2;
//            t->rchild = q;
//            q->rchild = q->lchild = NULL;
//            que[rear++] = q;
//            n--;
//        }
//        else
//            t->rchild = NULL;
//    }
//    return bt;
//}
//int bitreedepth(BinTree *t)
//{
//	int m, n;
//	if (t == NULL)return 0;
//	m = bitreedepth(t->lchild);
//	n = bitreedepth(t->rchild);
//	if (m > n)return m + 1;
//	else return n + 1;
//}
//int main()
//{
//    BinTree* root;
//    int n;
//    num = 0, ss = 0;
//    front = rear = 0;
//    scanf("%d", &n);
//    n = n * 2;
//    while (n--) {
//        scanf("%d", &s[num]);
//        num++;
//    }
//    root = CreateBiTree();
//    printf("%d", bitreedepth(root));
//    return 0;
//}
//

//#include <stdio.h>						
//#include <stdlib.h>
//typedef int ElementType;
//ElementType ERROR = -1;
//typedef enum { FALSE, TRUE } Boolean;
//typedef struct binode {
//	ElementType data;
//	struct binode* lchlid, * rchlid;
//} Binode, * bitree;
////----------------------------------------------------------------------------------------------------------------------------------
//typedef Binode* QElementType;
//typedef struct
//{
//	QElementType* data;
//	int front;
//	int rear;
//	int maxsize;
//}queue;
//void initqueue(queue* q, int maxsize)
//{
//	q->data = (QElementType*)malloc(maxsize * sizeof(QElementType));
//	if (!q->data)exit(1);
//	q->front = q->rear = 0;
//	q->maxsize = maxsize;
//
//}
//Boolean Isempty(queue* q)
//{
//	if (q->front == q->rear)return TRUE;
//	else return FALSE;
//}
//Boolean Isfull(queue* q)
//{
//	if ((q->rear + 1) % q->maxsize == q->front)return TRUE;
//	else return FALSE;
//}
//Boolean enqueue(queue* q, QElementType e)
//{
//	if (Isfull(q))return FALSE;
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxsize;
//	return TRUE;
//}
//Boolean dequeue(queue* q, QElementType* e)
//{
//	if (Isempty(q))return FALSE;
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxsize;
//	return TRUE;
//
//}
////----------------------------------------------------------------------------------------------------------------------------------
//void initbitree(bitree* t)
//{
//	*t = NULL;
//}
//void createbitree(bitree* t)
//{
//	ElementType ch, m, a, b;
//	scanf("%d", &m);
//	if (m == 0)
//	{
//		*t = NULL;
//	}
//	else
//	{
//		*t = (Binode*)malloc(sizeof(Binode));
//		if (!*t)exit(1);
//		(*t)->data = ch;
//		createbitree(&(*t)->lchlid);
//		createbitree(&(*t)->rchlid);
//	}
//	if (ch == '-')
//	{
//		return;
//	}
//}
//void destory(bitree* t)
//{
//	if (*t && (*t)->lchlid)
//		destory(&(*t)->lchlid);
//	if (*t && (*t)->rchlid)
//		destory(&(*t)->rchlid);
//	free(*t);
//	*t = NULL;
//}
//Boolean isempty(bitree* t)
//{
//	if (!t)return TRUE;
//	else return FALSE;
//}
//int bitreedepth(bitree t)
//{
//	int m, n;
//	if (t == NULL)return 0;
//	m = bitreedepth(t->lchlid);
//	n = bitreedepth(t->rchlid);
//	if (m > n)return m + 1;
//	else return n + 1;
//}
//Binode* root(bitree t)
//{
//	return t;
//}
//ElementType value(Binode* p)
//{
//	if (p)return p->data;

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct BiNode
//{
//	int data;
//	struct BiNode* lchild, * rchild;
//}BiNode,*BiTree;
//
//typedef struct Queue
//{
//	struct BiNode* data[9999];
//	int rear, front;
//}Queue,*LinkQueue;
//
//LinkQueue CreatQueue()
//{
//	LinkQueue Q;
//	Q = (Queue*)malloc(sizeof(Queue));
//	Q->front = Q->rear = 0;
//	return Q;
//}
//
////T加入Q
//void AddQ(LinkQueue Q, BiTree T)
//{
//	if (Q->rear + 1 == Q->front)return;//满
//	Q->rear++;
//	Q->data[Q->rear] = T;
//}
//
////出队
//BiTree DeleteQ(LinkQueue Q)
//{
//	BiTree T;
//	Q->front++;
//	T = Q->data[Q->front];
//	return T;
//}
//
////1为满
//int IsEmpty(LinkQueue Q)
//{
//	if (Q->front == Q->rear)return 1;
//	return 0;
//}
//
////层次创建二叉树
//BiTree CreatBiTree()
//{
//	BiTree T, BT;
//	LinkQueue Q;
//	Q = CreatQueue();
//	int d;
//	d = 1;//根结点
//	//scanf("%d",&d);
//	BT = (BiNode*)malloc(sizeof(BiNode));
//	BT->data = d;
//	BT->lchild = BT->rchild = NULL;
//	AddQ(Q, BT);
//	while (!IsEmpty(Q))
//	{
//		T = DeleteQ(Q);
//		//左儿子
//		scanf("%d", &d);
//		if (d == 0)
//		{
//			T->lchild == NULL;
//		}
//		else
//		{
//			T->lchild = (BiNode*)malloc(sizeof(BiNode));
//			T->lchild->data = d;
//			T->lchild->lchild = T->lchild->rchild = NULL;
//			AddQ(Q, T->lchild);
//		}
//		//右儿子
//		scanf("%d", &d);
//		if (d == 0)
//		{
//			T->rchild = NULL;
//		}
//		else
//		{
//			T->rchild = (BiNode*)malloc(sizeof(BiNode));
//			T->rchild->data = d;
//			T->rchild->lchild = T->rchild->rchild = NULL;
//			AddQ(Q, T->rchild);
//		}
//	}
//	return BT;
//}
//
//int DepthT(BiTree T)
//{
//	int n, m;
//	if (T == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		m = DepthT(T->lchild);
//		n = DepthT(T->rchild);
//		if (m > n)
//		{
//			return m + 1;
//		}
//		else
//		{
//			return n + 1;
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	BiNode *T;
//	T = (BiNode*)malloc(sizeof(BiNode));
//	if (T == NULL)return 0;
//	T = CreatBiTree();
//	printf("%d", DepthT(T));
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int num[999] = { 0 }, deep[999] = { 0 };
//char str[999];
//int main()
//{
//	int n,i;
//	scanf("%d", &n);
//	getchar();
//	while (n--)
//	{
//		gets_s(str);
//		int ni = 0, di = 0, maxx = 0,ans=0;
//		for (i = 0; i < strlen(str); i++)
//		{
//			if (str[i] >= 'A' && str[i] <= 'Z')
//			{
//				num[ni]++;
//			}
//			else if (str[i] == '(')
//			{
//				deep[++di]++;
//				ni++;
//				if (maxx < di)maxx = di;
//			}
//			else if (str[i] == ')')
//			{
//				ni--;
//				di--;
//			}
//		}
//		for (i = 0; i <= maxx; i++)
//		{
//			ans = ans + num[i] * deep[i];
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//char str[9999];
//int main()
//{
//	gets_s(str);
//	int i, deep = 0, hight[9999] = { 0 },hi=0,maxx=0;
//	for (i = 0; i < strlen(str); i++)
//	{
//		if (str[i] == '(')
//		{
//			deep++;
//			hi++;
//		}
//		else if (str[i] >= 'A' && str[i] <= 'Z')
//		{
//			hight[hi]++;
//			if (hight[hi] > maxx)
//			{
//				maxx = hight[hi];
//			}
//		}
//		else if (str[i] == ')')
//		{
//			hi--;
//		}
//	}
//	printf("%d %d", deep, maxx);
//	return 0;
//}

//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define MaxN 100 //最大结点个数
//#define Maxbit 255 //最大编码值
//#define MaxValue 9999 //最大权值
//
////树储存结构
//typedef struct
//{
//	int weight;//权值
//	int flag;//标记,flag==1则已经加入到hafftree中
//	int parent;//父结点下标
//	int leftChild;//左孩子结点下标
//	int rightChild;//右孩子结点下标
//}HaffNode;
//
////哈夫曼编码结构
//typedef struct
//{
//	int bit[MaxN];//每个叶子结点到根节点路径所对应的哈夫曼编码
//	int start;//编码起始下标
//	int weight;//字符权值
//}Code;
//
////建立hafftree
////叶节点数为n，权值数组为weight的hafftree*
//void Haffman(int weight[], int n, HaffNode haffTree[])
//{
//	int i, j, m1, m2, x1, x2;
//
//	//初始化hafftree
//	//共有n*2+1个结点,前n个是叶子结点
//	for (i = 0; i < 2 * n - 1; i++)
//	{
//		if (i < n)
//		{
//			haffTree[i].weight = weight[i];
//		}
//		else
//		{
//			haffTree[i].weight = 0;
//		}
//		haffTree[i].parent = 0;
//		haffTree[i].flag = 0;
//		haffTree[i].leftChild = -1;
//		haffTree[i].rightChild = -1;
//	}
//
//	//构造hafftree的n-1个非叶子结点
//	for (i = 0; i < n - 1; i++)
//	{
//		//找到权值最小的两颗树的下标x1,x2
//		m1 = m2 = MaxValue;
//		x1 = x2 = 0;
//		for (j = 0; j < n + i; j++)
//		{
//			//先找一颗权值较小的树，再找另一颗
//			if (haffTree[j].weight < m1 && haffTree[j].flag == 0)
//			{
//				m2 = m1;
//				x2 = x1;
//				m1 = haffTree[j].weight;
//				x1 = j;
//			}
//			else if (haffTree[j].weight < m2 && haffTree[j].flag == 0)
//			{
//				m2 = haffTree[j].weight;
//				x2 = j;
//			}
//		}
//		//将找出的两棵权值最小的子树合并为一棵子树
//		haffTree[x1].parent = n + i;
//		haffTree[x2].parent = n + i;
//		haffTree[x1].flag = 1;//表示都已经加入hafftree
//		haffTree[x2].flag = 1;
//		haffTree[n + i].weight = haffTree[x1].weight + haffTree[x2].weight;
//		haffTree[n + i].leftChild = x1;
//		haffTree[n + i].rightChild = x2;
//	}
//}
//
////构造哈夫曼编码
////结点为n
//void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[])
//{
//	Code* cd = (Code*)malloc(sizeof(Code));
//	int i, j, child, parent;
//
//	//求n个叶节点的哈夫曼编码
//	for (i = 0; i < n; i++)
//	{
//		cd->start = n - 1;
//		cd->weight = haffTree[i].weight;
//		child = i;
//		parent = haffTree[child].parent;
//		//由叶结点向上直到根结点
//		while (parent != 0)
//		{
//			if (haffTree[parent].leftChild == child)//如果是左孩子
//			{
//				cd->bit[cd->start] = 0;//左孩子分支编码
//			}
//			else//如果是右孩子
//			{
//				cd->bit[cd->start] = 1;//右孩子分支编码
//			}
//			cd->start--;
//			child = parent;
//			parent = haffTree[child].parent;
//		}
//		for (j = cd->start + 1; j < n; j++)
//		{
//			haffCode[i].bit[j] = cd->bit[j];//保存每个叶节点的编码
//		}
//		haffCode[i].start = cd->start;//保存不等长编码的起始位
//		haffCode[i].weight = cd->weight;//保存相应字符的权值
//	}
//}
//
//void OutPut(int n, Code haffCode[])
//{
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		printf("weight=%d   Code=", haffCode[i].weight);
//		for (j = haffCode[i].start + 1; j < n; j++)
//		{
//			printf("%6d", haffCode[i].bit[j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int i, j, n,m;
//	scanf("%d", &m);
//	while (m--)
//	{
//		scanf("%d", &n);
//		int weight[MaxN];
//		for (i = 0; i < n; i++)
//		{
//			scanf("%d", &weight[i]);
//		}
//		HaffNode* myHaffTree = (HaffNode*)malloc(sizeof(HaffNode) * (2 * n + 1));
//		Code* myHaffCode = (Code*)malloc(sizeof(Code) * n);
//		Haffman(weight, n, myHaffTree);
//		HaffmanCode(myHaffTree, n, myHaffCode);
//		OutPut(n, myHaffCode);
//	}
//	return 0;
//}

//#include<stdio.h>
//#define INF 65535
//struct huffman {
//	int w;
//	int parent;//可用来判是否加入树
//	int lchild, rchild;
//}HT[1001];
//int n;
//
//void createHT()
//{
//
//	int i, j;
//	for (i = 0; i < 2 * n - 1; i++)
//	{
//		HT[i].parent = HT[i].lchild = HT[i].rchild = -1;
//	}
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &HT[i].w);
//	}
//	int a=0, b=0;
//	int a1, b1;//找最小两个权值
//	for (i = 0; i < n - 1; i++)
//	{
//		a1 = b1 = INF;
//		for (j = 0; j < n + i; j++)
//		{
//			if (HT[j].parent == -1 && HT[j].w < a1)
//			{
//				b = a;
//				a = j;
//				b1 = a1;
//				a1 = HT[j].w;
//			}
//			else if (HT[j].parent == -1 && HT[j].w < b1)
//			{
//				b = j;
//				b1 = HT[j].w;
//			}
//		}
//
//		HT[n + i].w = HT[a].w + HT[b].w;
//		HT[n + i].lchild = a;
//		HT[n + i].rchild = b;
//		HT[a].parent = HT[b].parent = n + i;
//	}
//}
//
//int main()
//{
//	int m;
//	scanf("%d", &m);
//	while (m--)
//	{
//		scanf("%d", &n);
//			int i, sum = 0;
//			createHT();
//			for (i = n; i < 2 * n - 1; i++)
//			{
//				sum += HT[i].w;
//			}
//			printf("%d\n", sum);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//struct Huffman
//{
//	int w;
//	int parent, lchild, rchild;
//}HuffTree[9999];
//int num,ans;
//void Creat()
//{
//	int i, j;
//	scanf("%d", &num);
//	//初始化
//	for (i = 0; i < num * 2 - 1; i++)
//	{
//		HuffTree[i].lchild = HuffTree[i].rchild = HuffTree[i].parent = -1;
//	}
//	for (i = 0; i < num; i++)
//	{
//		scanf("%d", &HuffTree[i].w);
//	}
//	//找最小两个结点
//	int a = 0, b = 0;//记录最小结点下标
//	for (i = 0; i < num-1; i++)
//	{
//		int a1 = 9999, b1 = 9999;//记录最小的值
//		for (j = 0; j < num + i; j++)
//		{
//			if (HuffTree[j].parent == -1 && HuffTree[j].w < a1)
//			{
//				b = a;
//				a = j;
//				b1 = a1;
//				a1 = HuffTree[j].w;
//			}
//			else if (HuffTree[j].parent == -1 && HuffTree[j].w < b1)
//			{
//				b = j;
//				b1 = HuffTree[j].w;
//			}
//		}
//		HuffTree[num + i].w = HuffTree[a].w + HuffTree[b].w;
//		HuffTree[num + i].lchild = a;
//		HuffTree[num + i].rchild = b;
//		HuffTree[a].parent = HuffTree[b].parent = num + i;
//	}
//}
//void OutPut()
//{
//	int i;
//	for (i = num; i < 2 * num-1 ; i++)
//	{
//		ans += HuffTree[i].w;
//	}
//	printf("%d\n", ans);
//}
//int main()
//{
//	int n;
//		ans = 0;
//		Creat();
//		OutPut();
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//typedef struct PTNode
//{
//	int data;
//	int parent;
//}PTNode;
//typedef struct
//{
//	PTNode nodes[999];
//	int n;
//}PTree;
//int m;
//PTree *Creat()
//{
//	int nn,i;
//	PTree* T;
//	T = (PTree*)malloc(sizeof(PTree));
//	for (i = 0; i < m ; i++)
//	{
//		T->nodes[i].
//	}
//	for (int i = 0; i < m-1; i++)
//	{
//		scanf("%d %d", &nn, &T->nodes[++T->n].data);
//	}
//	T->n = m;
//	return T;
//}
//int main()
//{
//	PTree *T;
//	scanf("%d", &m);
//	T = Creat();
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//typedef int VertexType;
//typedef int EdgeType;
//#define MAXVEX 100  
//#define INFINITY 65535 
//#define TRUE 1;
//#define FALSE 0;
//typedef int BOOL;
//BOOL visited[MAXVEX];
//
//typedef struct EdgeNode
//{
//	int adjvex;
//	EdgeType info;
//	struct EdgeNode* next;
//}EdgeNode;
//typedef struct VertexNode
//{
//	VertexType data;
//	EdgeNode* firstedge;
//}VertexNode, AdjList[MAXVEX];
//typedef struct
//{
//	AdjList adjList;
//	int numNodes, numEdges;
//}GraphAdjList;
//void CreateALGraph(GraphAdjList* G)
//{
//	int i, j, k;
//	EdgeNode* e;
//	scanf("%d", &G->numNodes);
//	G->numEdges = G->numNodes - 1;
//	for (i = 0; i < G->numNodes; i++)
//	{
//		G->adjList[i].data=i;
//		G->adjList[i].firstedge = NULL;
//	}
//	for (k = 0; k < G->numEdges; k++)
//	{
//		scanf("%d%d", &i, &j);
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		e->adjvex = j;
//		e->next = G->adjList[i].firstedge;
//		G->adjList[i].firstedge = e;
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		e->adjvex = i;
//		e->next = G->adjList[j].firstedge;
//		G->adjList[j].firstedge = e;
//	}
//}
//int maxx = 0, ma = 0;
//void DFS_2(GraphAdjList* GL, int i)
//{
//	EdgeNode* p;
//	visited[i] = TRUE;
//	p = GL->adjList[i].firstedge;
//	while (p)
//	{
//		if (!visited[p->adjvex])DFS_2(GL, p->adjvex);
//		p = p->next;
//		ma++;
//	}
//}
//void DFSTraverse_2(GraphAdjList* GL)
//{
//	int i;
//	for (i = 0; i < GL->numNodes; i++)visited[i] = FALSE;
//	for (i = 0; i < GL->numNodes; i++)
//	{
//		if (!visited[i])DFS_2(GL, i);//从vi出发
//		if (ma > maxx)maxx = ma;
//		ma = 0;
//	}
//}
//
//
//int main()
//{
//	GraphAdjList G;
//	CreateALGraph(&G);
//	DFSTraverse_2(&G);
//	printf("%d", maxx);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int n, r, j[999] = { 0 };
	scanf("%d%d", &n, &r);
	int i;
	for (i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		j[a]++;
		j[b]++;
	}
	for (i = 1; i < (n - 1) / 2; i++)
	{
		if (j[i] != 2)
		{
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}