#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int Status;
typedef int SElemtype;
#define OK 1;
#define ERROR 0;
#define MAXSIZE 10

//两栈
typedef struct Node
{
	SElemtype data;
	Node *next;
 } Node;
 typedef struct Node *List;
 //创建两表 
 void CreateList(List &L,int n)
 {
 	L=(Node*)malloc(sizeof(Node));
 	if(L==NULL)
 	{
 		printf("创建失败")； 
 		return ERROR;
	 }
	 L->next=NULL;
	 List p,r;//r尾结点 
	 r=*L;
	 srand(time(0));
	 while(n--)
	 {
	 	p=(Node*)malloc(sizeof(Node));
	 	p->data=rand()%100+1;
	 	r->next=p;
	 	r=p;
	 }
  } 

//两栈共享的空间结构
typedef struct
{
	SElemtype data[MAXSIZE];
	int top1;//栈1顶指针
	int top2;//栈2顶指针 
 }SqDoubleStack;
 
 //插入e
 Status Push(SqDoubleStack *S,SElemtype e,int stackNumber)//需选择栈
 {
 	//判是否满
	  if(S->top1+1==S->top2)return ERROR;
	  //进栈
	  if(stackNumber==1)
	  {
	  	S->data[++S->top1]=e;
	  }
	  else 
	  {
	  	S->data[--S->top2]=e;//注意 往前存！ 
	  }
	  return OK;
  } 
  
  //删除,删除值存入e 
  Status Pop(SqDoubleStack *S,SElentype *e,int stackNumber)
  {
  	if(stackNumber==1)
  	{
  		if(S->top1==1)return ERROR;
  		*e=S->data[S->top1--]; 
	}
	else 
	{
	    if(S->top2==MAXSIZE)return ERROR;
	  	*e=S->data[S->top2++];
	}
	return OK;
   } 
   
void OutPut1(List *L)
{
	List p;
	p=(*L)->next;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("\n");
}

void OutPut2(SqDoubleStack *L)
{
    int i=1;
	while(i<=top1)
	{
		printf("%d",L->data[i++]);
	}
	i=top2;
	while(i<=MAXSIZE)
	{
		printf("%d",L->data[i++]);
	}
}
   
int main()
{
	Node *L1,*L2;
	SqDoubleStack *LL;
	Creat(L1,3);
	OutPut1(L1);
	OutPut1(L2);
	Creat(L2,3);
	while(1)
	{
	printf("1.合并\n2.插入\n3.删除\n");
	int m;
	scanf("%d",&m);
	if(m==1)
	{
		Node p;
		p=*L1->next;
		while(p)
		{
			Push(*LL,p->data,1);
			p->next;
		}
		p=*L2->next;
		while(p)
		{
			Push(*LL,p->data,2);
			p->next;
		}
		OutPut2(LL);
	}
	else if(m==2)
	{
		printf("插入的值   需插入的表\n");
		int num,listnum;
		scanf("%d%d\n",&num,&listnum);
		Push(*LL,&num,listnum); 
		OutPut2(LL);
		printf("\n");	
	}
	else 
	{
		int e,listnum;
		printf("需删除的栈\n");
		scanf("%d\n",&listnum);
		Pop(*LL,&e,listnum);
		OutPut2(LL); 
	}
}
}
 
