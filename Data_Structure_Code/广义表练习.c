#include<stdio.h>
#include <stdlib.h>
#define DataType char//定义广义表存储类型为 char
//广义表结构
typedef enum{atom,list} NodeTag;
typedef struct GLNode{
    NodeTag tag;//用以区分原子节点和表节点
    union{//c语言共用体
        DataType data;//用以存放原子节点的值
        struct GLNode *slink;//指向自表的指针
    };
    struct GLNode *next;//指向下一个表节点
}* Glist;//广义表类型
Glist p;//静态变量 在查找元素时使用
/************************************
 * 作用：建立广义表
 * 函数名： CreatGList
 * 参数列表：Glist GL
 * 返回类型：Glist
************************************/
Glist CreatGList(Glist GL)
{
    char ch;//创建接收字符变量
    scanf("%c",&ch);//接收一个屏幕打印字符
    if(ch!=' ')//如果字符有内容，而非空表
    {
        GL = (struct GLNode *)malloc(sizeof(struct GLNode));//在指针处开辟空间，大小为一个GLNode结构体的类型
        if(ch=='(') //如果这个字符是左括号，表示一个子表开始
        {
            //此处开始创建新表
            GL->tag = list;//把标志位置为表
            GL->slink = CreatGList(GL->slink);//递归构建子表
        }        
        else//表示元素既非空也不是子表
        {
            GL->tag = atom;//把标志位置为原子
            GL->data = ch;//赋值
        }
    }
    else
        GL = NULL;//如果元素为空，GL节点赋值为NULL并开始下一个节点
    scanf("%c",&ch);//获取下一个字符
    if(ch == ',')//如果字符‘，’表示开始下一个结点
    {
        GL->next = CreatGList(GL->next);//递归构造下一节点
    }
    else//如果不是‘，’表示可能碰到了‘）’或‘；’或错误输入
    {
        GL->next = NULL;//此节点置空
    }
    return GL;//返回GL节点
    
}
/************************************
 * 作用：输出广义表
 * 函数名： PrintGList
 * 参数列表：Glist GL
 * 返回类型：void
************************************/
void PrintGList(Glist GL)
{
    if(GL!=NULL)//如果节点不为空
    {
        if(GL->tag == list)//如果这个节点的标志位是list
        {
            printf("(");//就输出一个“（”
            if(GL->slink == NULL)//如果这个列表的连接为空
                printf(" ");//就显示一个空格
            else//如果这个节点不为空
                PrintGList(GL->slink);//如果不是就迭代输出该节点
        }
        else//如果这个节点的标志位是原子
            printf("%c",GL->data);//输出原子节点
        if(GL->tag == list)//在前面已经迭代完了list所以要输出一个“）”
            printf(")");
        if(GL->next!=NULL)//如果这个节点有下一个元素
        {
            printf(",");//输出一个逗号
            PrintGList(GL->next);//继续输出下一个元素
        }
    }
}
/************************************
 * 作用：在广义表中查找某元素
 * 函数名： FindGlistX
 * 参数列表：Glist GL,DataType x,int*mark
 * 返回类型：void
************************************/
void FindGlistX(Glist GL,DataType x,int *mark)
{
    //调用广义表GL所指向的广义表，mark=false，x为待查找的元素值，
    //若查找成功，mark=true，p为指向数据域为x的结点
    if(GL!=NULL)//如果这个结点不为空就继续
    {
        if(GL->tag == 0 && GL->data == x)//如果这个节点是原子节点并且元素值等于目标
        {
            *mark = 1;//把标志位置1；
            p = GL;//全局节点 p赋值为当前节点的地址
        }
        else//不是原子节点或者数据不是目标值
        {
            if(GL->tag == 1)//如果是子表
                FindGlistX(GL->slink,x,mark);//递归检查子表
            FindGlistX(GL->next,x,mark);//如果是原子元素，就递归检查下一个元素
        }
    }
}
/************************************
 * 作用：返回广义表表头
 * 函数名： head
 * 参数列表：Glist GL
 * 返回类型：Glist
************************************/
Glist head(Glist GL)
{
    //函数会改变原广义表
    Glist p;//创建一个Glist类型的节点p
    if(GL != NULL && GL->tag != 0)//如果表不为空并且不是原子节点
    {
        p = GL->slink;//把GL节点的子表赋值给GL
        p ->next = NULL;//把p节点的下一个元素置空
        return p;//返回p节点
    }
    else 
        return NULL;
}
/************************************
 * 作用：返回广义表表尾
 * 函数名： tail
 * 参数列表：Glist GL
 * 返回类型：Glist
************************************/
Glist tail(Glist GL)
{
    //函数会改变原广义表
    Glist p;//创建一个Glist类型的节点p
    if(GL != NULL && GL->tag != 0)//如果表不为空并且有表尾
    {
        p = GL->slink;//进入广义表
        p = p ->next;//指向第二个元素
        GL->slink = p;//将广义表头的指针指向第二个元素也就是删除第一个元素
    }
    return p;//返回NULL
}
/************************************
 * 作用：返回广义表深度
 * 函数名： depth
 * 参数列表：Glist GL,int *maxdh
 * 返回类型：void
************************************/
void depth(Glist GL,int*maxdh)
{
    int h; // 创建一个flag
    if(GL->tag==0)//如果这个广义表为单个元素
        *maxdh = 0;//深度等于零
    else//如果广义表不是单个元素
    {
        GL = GL->slink;//进入这个广义表
        *maxdh = 0;//深度赋初值
        do
        {//依次遍历所有元素
            depth(GL,&h);//递归子表
            if(h > *maxdh)//如果这个过程中到达的深度大于maxdh
                *maxdh = h;//那么就更新maxdh
                GL = GL->next;//指针指向下一个元素
        } while (GL!=NULL);//直到所有元素遍历完成
        *maxdh = *maxdh+1;//把深度加一
        
    }
    
}
int main(int argc, char const *argv[])
{
    Glist test;
    int flag;
    test = CreatGList(test);
    depth(test,&flag);
    printf("%d",flag);
    // test = tail(test);
    // PrintGList(test);
    // FindGlistX(test,'3',&flag);
    return 0;
}
