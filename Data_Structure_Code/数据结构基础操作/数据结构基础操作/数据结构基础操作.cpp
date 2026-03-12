#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>//用于生成随机数

typedef int Status;//用Status来进行替代int,方便数据类型的修改
typedef int ElemType;
#define OK 1;
#define ERROR 0;

//单链表储存结构
typedef struct Node//定义结构体LNode
{
    ElemType data;//结点数据域
    struct Node* next;//结点指针域
}Node;
typedef struct Node* LinkList;//LinkList为指向结构体Node的指针类型

//初始化一个空的单链表L
Status InitList(LinkList& L) //InitList()顺序表的初始化函数
{	 
    L = (Node*)malloc(sizeof(Node));        	 //申请空间，生成新结点作为L头结点
    if (L == NULL)						//判断是否有足够的内存空间 
    {
        printf("申请内存空间失败\n");
    }
    L->next = NULL;          //头结点的指针域置空，初始长度为0
    return OK;
}

//尾插法创建链表
void CreateListTail(LinkList* L, int n)//*L即调用已经存在的线性表L
{
    LinkList p, r;//L：指整个单链表；p：需创建的新节点；r：指向尾结点的变量。
    r = *L;//r指向尾部节点
    printf("1.输入初始数据\n2.自动生成数据\n");//链表生成类型选择
    int a;
    scanf("%d", &a);
    if (a == 1)
    {
        while (n--)
        {
            p = (Node*)malloc(sizeof(Node));//为新结点开辟内存
            scanf("%d", &p->data);//读取数据
            r->next = p;//在原来的尾结点r后存入
            r = p;//更新尾结点
        }
        r->next = NULL;//链表结束
    } 
    else if(a==2)
    {
        srand(time(0));//初始化随机数种子
        r = *L;//r指向链表尾部
        while (n--)
        {
            p = (Node*)malloc(sizeof(Node));//生成新结点
            p->data = rand() % 100 + 1;//随机产生100以内的数
            r->next = p;//将新结点添加到表尾
            r = p;//更新尾结点：将新结点更新为尾结点
        }
        r->next = NULL;//表示链表结束
    }
    printf("链表创建成功！\n");
}

//整表删除，即变成空表
Status ClearList(LinkList* L)
{
    LinkList p, q;
    p =(*L)->next;//使p指向线性表第一个结点
    while (p)//如果p不为NULL
    {
        q = p->next;//q指向p的下一个结点,防止释放p后找不到下一个结点
        free(p);//释放p结点
        p = q;//p指向下一个结点
    }
    (*L)->next = NULL;//使头结点为空，相当于链表初始化时的操作
    return OK;
}

//查找，读取元素，获取第i个元素数据,返回到e
Status GetElem(LinkList *L, int i, ElemType* e)
{
    int j=1;//计数,最后一个结点是NULL，不需要遍历∴从1开始计
    LinkList p;
    p=(*L)->next;//p从头结点开始找
    //遍历链表，找到第i个元素
    while (j <i&&p)//若没找到||p=NULL退出
    {
        p=p->next;//指向下一个结点
        j++;
    }
    if (!p||j>i)//p为空||不存在i结点时
    {
        printf("出错！查找位置在链表之外！\n");
        return ERROR;
    }
    *e = p->data;
    return OK;
}

//在位置i插入元素e,使链表成为 a，e，a+1
Status ListInsert(LinkList* L, int i, ElemType *e)
{
    //先遍历找到第i个结点
    int j=1;
    LinkList p;
    p = (*L)->next;//p指向链表头结点
    if (i == 0)//头结点插入特判
    {
        LinkList s;
        s = (Node*)malloc(sizeof(Node));
        s->data = *e;//存数据域
        s->next = (*L)->next;//把原头结点给s的下一个结点
        (*L)->next = s;//更新新结点
        printf("成功！\n");
        return OK;
    }
    while (j < i && p)
    {
        p=p->next;
        j++;
    }
    if (!p || j > i)//没找到
    {
        printf("出错！插入位置在链表之外！\n");
        return ERROR;
    }

    //找到位置后插入
    LinkList s;//创建要插入的新结点
    s= (Node*)malloc(sizeof(Node));//为新节点开辟内存
    s->data = *e;//储存数据域
    s->next = p->next;//将p后继结点给s的后继，即连接e和a+1
    p->next = s;//将s给p的后继，即连接a和e
    printf("成功！\n");
    return OK;
}

//删除第i个元素，并用e返回其值
Status ListDelete(LinkList* L, int i, ElemType* e)
{
    //遍历找到第i个结点
    int j=1;
    LinkList p;
    p = (*L)->next;
    if (i == 1)//若是头结点需特判
    {
        *e = p->data;
        (*L)->next = p->next;//使链表头结点直接指向下一个
        printf("删除元素的值为：%d\n", *e);
        printf("成功！\n");
        return OK;
    }
    i--;
    while (j < i && p->next)//∵需删除p后的结点，∴p->next必须存在
    {
        p = p->next;
        j++;
    }
     if (!(p->next) || i < j)
     {
        printf("出错！删除位置在链表之外！\n");
        return ERROR;
     }
        LinkList q;
        q = p->next;//将预删除的结点给q
        p->next = q->next;//p连接需删除结点后的结点，即p->next=p->next->next
        *e = q->data;//删除结点中的数据给e
        free(q);//释放删除的结点
        printf("删除元素的值为：%d\n", *e);
        printf("成功！\n");
    return OK;
}

//输出链表
void OutPutList(LinkList* L)
{
    LinkList p;
    p = (*L)->next;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    Node *L;
    int n,i,e,q;
    InitList(L);
    //目录
    printf("                目录\n");
    printf("1.创建链表\n2.查找列表元素\n3.清空链表\n4.插入元素\n5.删除元素\n6.输出链表\n\n");
    while (~scanf("%d", &q))
    {
        if (q == 1)
        {
            printf("请输入链表数据个数：\n");
            scanf("%d", &n);
            CreateListTail(&L, n);
        }
        else if (q == 2)
        {
            scanf("%d", &i);
            GetElem(&L, i, &e);
        }
        else if (q == 3)
        {
            ClearList(&L);
            printf("链表已清空！\n");
        }
        else if(q==4)
        {
            printf("请输入需插入的位置：\n");
            scanf("%d", &i);
            printf("请输入需插入元素的值：\n");
            scanf("%d", &e);
            ListInsert(&L, i, &e);
        }
        else if (q == 5)
        {
            printf("请输入需删除的元素位置：\n");
            scanf("%d", &i);
            ListDelete(&L, i, &e);
        }
        else if (q == 6)
        {
            printf("\n");
            OutPutList(&L);
        }
        printf("                目录\n");
        printf("1.创建链表\n2.查找列表元素\n3.清空链表\n4.插入元素\n5.删除元素\n6.输出链表\n\n");
    }
    return 0;
}
