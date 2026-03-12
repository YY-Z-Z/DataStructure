#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int VertexType;//顶点类型
typedef int EdgeType;//边上权值类型
#define MAXVEX 10  //最大顶点数
#define INFINITY 65535 //代表∞，表示矩阵中没有结点连接的空值
//表

//邻接表储存结构
//边表结点
typedef struct EdgeNode
{
	int adjvex;//邻接点域，储存该结点对应下标
	int info;//权值
	struct EdgeNode* next;//链表，指向下一个邻接点
}EdgeNode;
//顶点表结点+顶点对应的边表
typedef struct VertexNode
{
	VertexType data;//存顶点数据
	EdgeNode* firstedge;//边表头指针,相当于last
	int in;//用于关键路径的计算，顶点入度
}VertexNode, AdjList[MAXVEX];
//总表
typedef struct
{
	AdjList adjList;
	int numNodes, numEdges;//图中当前顶点数和边数
}GraphAdjList;

//创建邻接表
void CreateALGraph(GraphAdjList* G)
{
	int i, j, k, w, nn;
	EdgeNode* e;
		printf("请输入顶点数和边数：\n");
		scanf("%d %d", &G->numNodes, &G->numEdges);
		//建立顶点表
		printf("请输入顶点信息：\n");
		for (i = 0; i < G->numNodes; i++)
		{
			scanf("%d", &G->adjList[i].data);
			G->adjList[i].firstedge = NULL;//将边表置为空表
			G->adjList[i].in = 0;//初始化顶点入度
		}
		getchar();
		//建立边表
		for (k = 0; k < G->numEdges; k++)
		{
			printf("请输入边(vi,vj)上的顶点序号及权值\n");
			scanf("%d%d%d", &i, &j, &w);
			//头插法
			//连接vi->vj
			e = (EdgeNode*)malloc(sizeof(EdgeNode));//边表结点申请内存空间
			e->info = w;
			e->adjvex = j;//该结点对应下标为j
			if (G->adjList[i].firstedge == NULL)
			{
				G->adjList[i].firstedge = e;
				e->next = NULL;
			}
			else
			{
				e->next = G->adjList[i].firstedge;//e指针指向当前顶点指向的结点
				G->adjList[i].firstedge = e;//更新下一个顶点
			}
			G->adjList[j].in++;
		}
}

//关键路径
// 
//定义全局变量
//事件：顶点vk。活动：有向边。活动的持续时间：边上的权值。
//AOE网：用这种有向图的边表示的网                                                  
int* etv;//事件（顶点vk)最早发生时间数组
int* ltv;//事件最迟发生时间数组
int* stack2;//储存拓扑排序的栈
int top2;//stack2栈顶指针
//拓扑排序
//若GL无回路，则输出拓扑排序序列并返回1；有回路输出0.
int TopologicalSort(GraphAdjList* GL)
{
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;//栈指针下标
	int count = 0;//统计输出栈顶个数
	int* stack;//储存入度为0的顶点数组
	stack = (int*)malloc((GL->numNodes) * sizeof(int));//开辟GL->numNodes个int类型数组
	//找第一个入度为0的点，为初始点
	for (i = 0; i < GL->numNodes; i++)
	{
		if (0 == GL->adjList[i].in)
		{
			stack[++top] = i;//将入度为0的顶点入栈
		}
	}
	//初始化
	top2 = 0;//初始化栈顶指针
	etv = (int*)malloc(GL->numNodes * sizeof(int));//事件最早发生时间数组开辟内存
	for (i = 0; i < GL->numNodes; i++)etv[i] = 0;//初始化事件最早发生数组
	stack2 = (int*)malloc(GL->numNodes * sizeof(int));//初始化拓扑序列栈
	while (top != 0)
	{
		gettop = stack[top--];//弹出入度为0的第一个顶点
		count++;//统计输出顶点个数
		stack2[++top2] = gettop;//将弹出的顶点序列号压入拓扑序列栈
		//遍历与该结点连接的结点
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;//储存e结点下标
			if (!(--GL->adjList[k].in))stack[++top] = k;//压入 入度为0的结点
			//求各顶点事件最早发生时间
			if ((etv[gettop] + e->info) > etv[k])
			{
				etv[k] = etv[gettop] + e->info;
			}
		}
	}
	//判断是否形成回路
	if (count < GL->numNodes)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//求关键路径
//GL为有向网，输出G的各顶点关键活动（最小权值）
void CriticalPath(GraphAdjList *GL)
{
	EdgeNode* e;
	int i, gettop, k, j;
	int ete;//活动（有向边）最早发生时间
	int lte;//活动（有向边）最迟发生时间
	TopologicalSort(GL);//求拓扑序列，计算数组etv和stack2
	//初始化ltv（事件最迟发生时间）
	ltv = (int*)malloc(GL->numNodes * sizeof(int));
	for (i = 0; i < GL->numEdges; i++)
	{
		ltv[i] = etv[GL->numEdges - 1];
	}
	while (top2 != 0)
	{
		gettop = stack2[top2--];
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			//求各顶点时间最晚发生时间ltv
			if (ltv[k] - e->info < ltv[gettop])ltv[gettop] = ltv[k] - e->info;
		}
	}
	//求ete，lte和关键活动
	for (j = 0; j < GL->numNodes; j++)
	{
		for (e = GL->adjList[j].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];//活动最早发生时间
			lte = ltv[k] - e->info;//活动最迟发生时间
			if (ete == lte)//两者相等即在关键路径上
			{
				printf("<v%d - v%d> length: %d \n", GL->adjList[j].data, GL->adjList[k].data, e->info);
			}
		}
	}
}

int main()
{
	GraphAdjList Glist;
	CreateALGraph(&Glist);
	CriticalPath(&Glist);
	printf("Success!\n");
	return 0;
}

