#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int VertexType;//顶点类型
typedef int EdgeType;//边上权值类型
#define MAXVEX 10  //最大顶点数
#define INFINITY 65535 //代表∞，表示矩阵中没有结点连接的空值
//创建访问标志的数组
typedef int BOOL;
#define TRUE 1;
#define FALSE 0;
BOOL visited[MAXVEX];
//队列中元素类型
typedef int QElemType;


//队列操作——用于广度优先遍历
//循环队列顺序储存结构
typedef struct
{
	QElemType data[MAXVEX];
	int front;//头指针
	int rear;//尾指针
}SqQueue;
//队列初始化
void InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}
//入队
void EnQueue(SqQueue* Q, QElemType e)
{
	if ((Q->rear + 1) % MAXVEX == Q->front)return;//判队列是否满
	Q->data[Q->rear] = e;//将e赋值给队尾
	Q->front = (Q->rear + 1) % MAXVEX;//rear尾指针后移一位，若到最后则转到数组头部
}
//出队
void DeQueue(SqQueue* Q, QElemType *e)
{
	if (Q->front == Q->rear)return;//判断队列是否为空
	*e = Q->data[Q->front];//把要删掉的值给e
	Q->front = (Q->front + 1) % MAXVEX;//front头指针后移一位，若到最后则转到数组头部
}
//判断是否为空
int QueueEmpty(SqQueue* Q)
{
	if (Q->front == Q->rear)return 0;
	return 1;
}


//矩阵

//邻接矩阵储存结构
typedef struct
{
	VertexType vexs[MAXVEX];//顶点数组：vexs[顶点下标]=顶点的值
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵(边的信息）arc[vi][vj]=权值
	int numNodes;//图中当前顶点数
	int numEdges;//图中当前边数
}MGraph;

//建立无向网图邻接矩阵
void CreateMGraph(MGraph* G)
{
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d%d", &G->numNodes, &G->numEdges);//读取顶点数和边数
	//初始化顶点数组
	printf("请输入顶点数据：\n");
	for (i = 0; i < G->numNodes; i++)
	{
		scanf("%d", &G->vexs[i]);
	}
	//初始化邻接矩阵
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;//对角线元素为0
			}
			else
			{
				G->arc[i][j] = INFINITY;
			}
		}
	}
	//读取邻接矩阵（初始化边的数组）
	for (k = 0; k < G->numEdges; k++)
	{
		printf("输入边(vi,vj)上的下标i,j和权w：\n");
		scanf("%d%d%d", &i, &j, &w);//输入边(vi,vj)上的权w
		i--;
		j--;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];//因为是无向图，所以矩阵对称
	}
}

//邻接矩阵深度优先遍历
//深度遍历的递归算法
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;//第i个顶点被访问
	printf("%d ", G.vexs[i]);//打印顶点
	for (j = 0; j < G.numNodes; j++)
	{
		//在与vi邻接的结点中深度遍历，对未访问的邻接顶点递归
		if (G.arc[i][j] > 0 && G.arc[i][j] < INFINITY && !visited[j])DFS(G, j);
	}
}
//深度遍历操作
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numNodes; i++)visited[i] = FALSE;//初始化所有顶点为未访问状态
	for (i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])DFS(G, i);//从vi出发，对未访问过的顶点递归调用
	}
}

//邻接矩阵广度遍历算法
void BFSTraverse(MGraph G)
{
	int i, j;
	SqQueue Q;
	for (i = 0; i < G.numNodes; i++)visited[i] = FALSE;//初始化
	InitQueue(&Q);
	for (i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%d->", G.vexs[i]);//打印此顶点
			EnQueue(&Q, i);//此顶点入队列
			while (!QueueEmpty(&Q))
			{
				DeQueue(&Q, &i);//将队首元素出队列，赋给i
				for (j = 0; j < G.numNodes; j++)
				{
					if (G.arc[i][j]>0&&G.arc[i][j]<MAXVEX && !visited[j])
					{
						visited[j] = TRUE;//标记已经找到的顶点
						printf("%d->", G.vexs[j]);//打印顶点
						EnQueue(&Q, j);//将找到的顶点入队列
					}
				}
			}
		}
	}
}

//输出邻接矩阵
void OutPutGraph(MGraph *G)
{
	int i, j;
	printf("输出顶点信息：\n");
	for (i = 0; i < G->numNodes; i++)
	{
		printf("%d ", G->vexs[i]);
	}
	printf("\n输出邻接矩阵的信息:\n");
	printf("  ");
	for (i = 0; i < G->numNodes; i++)
	{
		printf("%3d", i+1);//输出矩阵第一行序号
	}
	for (i = 0; i < G->numNodes; i++)
	{
		printf("\n%d ", i + 1);
		for (j = 0; j < G->numNodes; j++)
		{
			if (G->arc[i][j] == INFINITY)
			{
				printf(" ∞");
			}
			else
			{
				printf("%3d", G->arc[i][j]);
			}
		}
		printf("\n");
	}
}

//最短路径(Floyd算法)
typedef int F_Patharc[MAXVEX][MAXVEX];//当前中转的顶点下标
typedef int F_ShortPathTable[MAXVEX][MAXVEX];//最短路径的权值
void ShortestPath_Floyd(MGraph G, F_Patharc* P, F_ShortPathTable* D)
{
	int v, w, k;
	//初始化D，P
	for (v = 0; v < G.numNodes; v++)
	{
		for (w = 0; w < G.numNodes; w++)
		{
				(*D)[v][w] = G.arc[v][w];//D[v][w]指v和w之间的权值
				(*P)[v][w] = w;//初始化P
		}
	}
	//生成最短路径
	for (k = 0; k < G.numNodes; k++)
	{
		for (v = 0; v < G.numNodes; v++)
		{
			for (w = 0; w < G.numNodes; w++)
			{
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])//如果经过下标为k的顶点中转后比原两点间路径更短
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];//当前权值取最小
					(*P)[v][w] = (*P)[v][k];//路径设置为经过下标为k的顶点
				}
			}
		}
	}
	//输出最短路径
	printf("各顶点间最短路径如下：\n");
	for (v = 0; v < G.numNodes; v++)
	{
		for (w = v + 1; w < G.numNodes; w++)
		{
			if ((*D)[v][w] >= INFINITY)
			{
				printf("v%d-v%d 无法联通\n", v+1, w+1);
				continue;
			}
			printf("v%d-v%d weight: %d \n", v+1, w+1, (*D)[v][w]);//输出点v到w的最短路径D[v][w]
			k = (*P)[v][w];//获得第一个路径顶点下标
			printf("PATH: %d", v+1);//打印源点
			while (k != w)//如果路径顶点下标不是终点
			{
				printf(" -> %d", k+1);//打印路径顶点
				k = (*P)[k][w];//获得下一个路径顶点下标
			}
			printf(" -> %d\n", w+1);//打印终点
		}
		printf("\n");
	}
}

//Dijkstra最短路径
typedef int D_Patharc[MAXVEX];//储存最短路径下标的数组
typedef int D_ShortPathTable[MAXVEX];//储存到各点最短路径的权值和
//Dijkstra算法
//求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v]
//P[v]的值为前驱顶点的下标，D[v]表示v0到v的最短路径长度和
void ShortestPath_Dijkstra(MGraph G, int v0, D_Patharc* P, D_ShortPathTable* D)
{
	int v, w, k=0, min;
	int final[MAXVEX];//final[w]=1表示求得顶点v0至vw的最短路径
	//初始化数据
	for (v = 0; v < G.numNodes; v++)
	{
		final[v] = 0;//初始化为未知最短路径
		(*D)[v] = G.arc[v0][v];//将与v0点有连接的顶点加上权值
		(*P)[v] = -1;//初始化路径数组
	}
	(*D)[v0] = 0;//v0到v0路径为0
	final[v0] = 1;//v0到v0不需要求路径
	//求v0到v的最短路径
	for (v = 1; v < G.numNodes; v++)
	{
		min = INFINITY;//当前所知离v0顶点的最近距离
		for (w = 0; w < G.numNodes; w++)//寻找离v0最近的顶点
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;//目前顶点找到的最近顶点
		for (w = 0; w < G.numNodes; w++)//修正当前最短路径及距离
		{
			//如果经过v顶点的路径比现在这条路径的长度短的话
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				//说明找到更短路径，修改D[w],P[w]
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
	//输出最短路径
	printf("各顶点间最短路径如下：\n");
	k = v0;
	for (v = 0; v < G.numNodes; v++)
	{
		if ((*D)[v] >= INFINITY)
		{
			printf("v%d-v%d 无法联通\n", v0 + 1, v + 1);
			continue;
		}
		else 
		{
				printf("v0 %d v%d weight: %d \n",v0+1, v + 1, (*D)[v]);
				printf("\n");
		}
	}
}

//Prim 最小生成树
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//保存相关顶点间边的权值点下标
	int lowcost[MAXVEX];//保存相关顶点间边的权值
	lowcost[0] = 0;//初始化第一个权值为0，即v0加入生成树
	adjvex[0] = 0;//初始化第一个顶点下标为0
	for (i = 1; i < G.numNodes; i++)
	{
		lowcost[i] = G.arc[0][i];//将v0顶点与之有边的权值存入数组
		adjvex[i] = 0;//初始化都为v0下标
	}
	for (i = 1; i < G.numNodes; i++)
	{
		min = INFINITY;//初始化最小值
		j = 1;
		k = 0;
		while (j < G.numNodes)//循环全部顶点，找到当前与第i个顶点相连的最小边
		{
			if (lowcost[j] != 0 && lowcost[j] < min)//如果权值不为0（与当前结点连通）&&权值比min小
			{
				min = lowcost[j];//更新最小值
				k = j;//保存当前最小值下标
			}
			j++;
		}
		printf("(%d,%d) %d\n", adjvex[k]+1, k+1,lowcost[k]);//打印当前边中权值最小的边
		lowcost[k] = 0;//将当前顶点权值设为0，表示顶点已完成任务
		for (j = 1; j < G.numNodes; j++)
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];//将较小权值存入lowcost相应位置
				adjvex[j] = k;//将选定顶点下标存入adjvex
			}
		}
	}
}

//Krusal最小生成树
//边集数组
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;
//快排
void quick_sort(Edge *edges,int l, int r)
{
	if (l >= r)return ;
	int i = l - 1, j = r + 1, x = edges[(l + r) / 2].weight;
	while (i < j)
	{
		do i++; while (edges[i].weight < x);
		do j--; while (edges[j].weight > x);
		if (i < j)
		{
			Edge t = edges[i];
			edges[i] = edges[j];
			edges[j] = t;
		}
	}
	quick_sort(edges, l, j);
	quick_sort(edges, j + 1, r);
}
//查找连线顶点的尾部下标
int Find(int* parent, int f)
{
	while (parent[f] >0)
	{
		f = parent[f];
	}
	return f;
}
void MinSpanTree_Kruskal(MGraph G)
{
	int n, m, i,j,k=0;
	Edge edges[MAXVEX];//定义边集数组
	int parent[MAXVEX];//判断边与边是否形成环路
	//将矩阵G化为边集数组，并按权值从小到大排列
		for (i = 0; i < G.numNodes; i++)
		{
			for (j = 0; j < G.numNodes; j++)
			{
				if (G.arc[i][j] < INFINITY&&i<j)
				{
					edges[k].begin = i;
					edges[k].end = j;
					edges[k].weight = G.arc[i][j];
					k++;
				}
				else if (G.arc[i][j] < INFINITY)
				{
					edges[k].begin = j;
					edges[k].end = i;
					edges[k].weight = G.arc[i][j];
					k++;
				}
			}
		}
	quick_sort(edges, 0,G.numNodes-1);
	//初始化判断环路的数组
	for (i = 0; i < G.numNodes; i++)parent[i] = 0;
	for (i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m;
			printf("(%d,%d) %d\n", edges[i].begin+1, edges[i].end+1, edges[i].weight);
		}
	}
}



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
}VertexNode,AdjList[MAXVEX];
//总表
typedef struct
{
	AdjList adjList;
	int numNodes, numEdges;//图中当前顶点数和边数
}GraphAdjList,*graphAdjList;

//创建邻接表
void CreateALGraph(GraphAdjList* G)
{
	int i, j, k,w,nn;
	EdgeNode* e;
	printf("1.有向图\n2.无向图\n");
	scanf("%d", &nn);
	if (nn == 2)
	{
		printf("请输入顶点数和边数：\n");
		scanf("%d %d", &G->numNodes, &G->numEdges);
		//建立顶点表
		printf("请输入顶点信息：\n");
		for (i = 0; i < G->numNodes; i++)
		{
			scanf("%d", &G->adjList[i].data);
			G->adjList[i].firstedge = NULL;//将边表置为空表
		}
		//建立边表
		for (k = 0; k < G->numEdges; k++)
		{
			printf("请输入边(vi,vj)上的顶点序号\n");
			scanf("%d%d", &i, &j);
			//头插法
			//连接vi->vj
			e = (EdgeNode*)malloc(sizeof(EdgeNode));//边表结点申请内存空间
			e->adjvex = j;//该结点对应下标为j
			e->next = G->adjList[i].firstedge;//e指针指向当前顶点指向的结点
			G->adjList[i].firstedge = e;//更新下一个顶点
			//连接vj->vi
			e = (EdgeNode*)malloc(sizeof(EdgeNode));
			e->adjvex = i;
			e->next = G->adjList[j].firstedge;
			G->adjList[j].firstedge = e;
		}
	}
	else
	{
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
}

//邻接表的深度优先遍历
//递归算法
void DFS_2(GraphAdjList *GL,int i)
{
	EdgeNode* p;
	visited[i] = TRUE;//访问vi,已遍历
	printf("%d->", GL->adjList[i].data);//打印顶点
	p = GL->adjList[i].firstedge;//从vi出发深度遍历
	while (p)
	{
		if (!visited[p->adjvex])DFS_2(GL, p->adjvex);
		p = p->next;
	}
}
//邻接表深度遍历操作
void DFSTraverse_2(GraphAdjList* GL)
{
	int i;
	for (i = 0; i < GL->numNodes; i++)visited[i] = FALSE;//初始化所有顶点状态
	for (i = 0; i < GL->numNodes; i++)
	{
		if (!visited[i])DFS_2(GL, i);//从vi出发
	}
}

//邻接表的广度遍历算法
void BFSTraverse_2(GraphAdjList *GL)
{
	int i;
	EdgeNode* p;
	SqQueue Q;
	for (i = 0; i < GL->numNodes; i++)visited[i] = FALSE;
	InitQueue(&Q);
	for (i = 0; i < GL->numNodes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%d->", GL->adjList[i].data);
			EnQueue(&Q, i);
			while (!QueueEmpty(&Q))
			{
				DeQueue(& Q,&i);//队首出队列，赋给i
				p = GL->adjList[i].firstedge;//找到当前顶点的边链表的表头指针
				while (p)
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = TRUE;
						printf("%d->", GL->adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex);//顶点入队列
					}
					p = p->next;
				}
			}
		}
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
int TopologicalSort(GraphAdjList *GL)
{
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;//栈指针下标
	int count = 0;//统计输出栈顶个数
	int* stack;//储存入度为0的顶点数组
	stack = (int*)malloc(GL->numNodes * sizeof(int));//开辟GL->numNodes个int类型数组
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
		for (e = GL->adjList[gettop].firstedge; e; e=e->next)
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
void CriticalPath(graphAdjList GL)
{
	EdgeNode* e;
	int i, gettop, k, j;
	int ete;//活动（有向边）最早发生时间
	int lte;//活动（有向边）最迟发生时间
	TopologicalSort(GL);//求拓扑序列，计算数组etv和stack2
	//初始化ltv（事件最迟发生时间）
	ltv = (int*)malloc(GL->numNodes * sizeof(int));
	for (i = 0; i < GL->numNodes; i++)
	{
		ltv[i] = etv[GL->numNodes - 1];
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
		for (e = GL->adjList[j].firstedge; e; e=e->next)
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

//输出邻接表
void OutPutLink(GraphAdjList* GL)
{
	int i;
	EdgeNode *p; 
	printf("图的邻接表表示如下：\n");
	printf("%6s%8s%12s\n", "编号", "顶点", "相邻边编号");
	for (i = 0; i < GL->numNodes; i++)
	{
		printf("%4d %8d", i, GL->adjList[i].data);
		for (p = GL->adjList[i].firstedge; p != NULL; p = p->next)printf("%4d", p->adjvex);
		printf("\n");
	}
}

void catalogue()
{
	printf("1.创建无向邻接矩阵。\n2.创建无向邻接表。\n");
	printf("3.邻接矩阵的深度优先遍历。\n4.邻接表的深度优先遍历。\n");
	printf("5.邻接矩阵的广度优先遍历。\n6.邻接表的广度优先遍历。\n");
	printf("7.Floyd最短路径。\n8.Dijkstra最短路径。\n");
	printf("9.Prim最小生成树。\n10.Kruskal最小生成树。\n");
	printf("11.有向图的关键路径。\n");
}

int main()
{
	MGraph *Gmat;
	Gmat = (MGraph*)malloc(sizeof(MGraph));
	if (Gmat == NULL)return 0;
	GraphAdjList *Glist;
	Glist = (GraphAdjList*)malloc(sizeof(GraphAdjList));
	if (Glist == NULL)return 0;
	int P[MAXVEX][MAXVEX], D[MAXVEX][MAXVEX];
	catalogue();
	int n;
	while (~scanf("%d", &n))
	{
		if (n == 1)
		{
			CreateMGraph(Gmat);
			printf("Success!\n");
			OutPutGraph(Gmat);
		}
		else if (n == 2)
		{
			CreateALGraph(Glist);
			printf("Success!\n");
			OutPutLink(Glist);
		}
		else if (n == 3)
		{
			DFSTraverse(*Gmat);
		}
		else if (n == 4)
		{
			DFSTraverse_2(Glist);
		}
		else if (n == 5)
		{
			BFSTraverse(*Gmat);
		}
		else if (n == 6)
		{
			BFSTraverse_2(Glist);
		}
		else if (n == 7)
		{
			ShortestPath_Floyd(*Gmat, &P, &D);
		}
		else if (n == 8)
		{
			printf("请输入起始点v0：\n");
			int v0;
			scanf("%d", &v0);
			ShortestPath_Dijkstra(*Gmat, v0,P, D);
		}
		else if (n == 9)
		{
			MiniSpanTree_Prim(*Gmat);
		}
		else if (n == 10)
		{
			MinSpanTree_Kruskal(*Gmat);
		}
		else if (n == 11)
		{
			CriticalPath(Glist);
			printf("Success!\n");
		}
		printf("\n");
		catalogue();
	}
	return 0;
}

