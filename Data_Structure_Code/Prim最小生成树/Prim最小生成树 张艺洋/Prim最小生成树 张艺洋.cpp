#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//图储存结构
typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct
{
	VertexType vexs[MAXVEX];//顶点表：vexs[顶点编号]=顶点值
	EdgeType arc[MAXVEX][MAXVEX];//边表：arc[vi][vj]=vi与vj间边的权值
	int numNodes;//顶点数
	int numEdges;//边数
}MGraph;
//创建无向网图邻接矩阵
void CreatMGraph(MGraph* G)
{
	int i, j, k, w;
	printf("请输入顶点数和边数：\n");
	scanf("%d %d", &G->numNodes, &G->numEdges);
	printf("请输入顶点信息：\n");
	for (i = 0; i < G->numNodes; i++)
	{
		scanf("%d", &G->vexs[i]);
	}
	//初始化矩阵
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	printf("请输入边(vi,vj)的下标i,j及权值w：\n");
	for (k = 0; k< G->numEdges; k++)
	{
		scanf("%d%d%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = w;
	}
}

//输出矩阵
void PrintMGraph(MGraph* G)
{
	int i, j;
	printf("秀一下矩阵：\n   ");
	for (i = 0; i < G->numNodes; i++)
	{
		printf("%d   ", G->vexs[i]);
	}
	printf("\n");
	for (i = 0; i < G->numNodes; i++)
	{
		printf("%d", G->vexs[i]);
		for (j = 0; j < G->numNodes; j++)
		{
			if (G->arc[i][j] == INFINITY)
			{
				printf("  ∞");
			}
			else
			{
				printf("%3d", G->arc[i][j]);
			}
		}
		printf("\n");
	}
}

//Prim最小生成树
void MiniSpanTree_Prim(MGraph* G)
{
	int i, j;
	int min;//当前最小权值
	int k;//最小权值顶点下标
	int adjvex[MAXVEX];//与当前树中相连顶点下标:adjvex[树中顶点i]=未入树顶点j，
	//即i,j两顶点相连。
	int lowcost[MAXVEX];//与树中相连边的较小权值：lowcost[未入树顶点]=与各已经入树顶点的最小权值
	//若未相连，则为∞；若该顶点已经入树，则为0
	int w_min = 0;//最小生成树权值

	//初始化
	//默认v0入树
	adjvex[0] = 0;
	lowcost[0] = 0;
	//初始化其他顶点
	for (i = 1; i < G->numNodes; i++)
	{
		adjvex[i] = 0;//初始化假设都与v0相连
		lowcost[i] = G->arc[0][i];//初始化数值为：v0与各顶点的权值
	}

	//构造最小生成树
	for (i = 1; i < G->numNodes; i++)//重复G->numNodes-1次(v0已经入树了)，使每个顶点都入树
	{
		//找最小权值的顶点
		min = INFINITY;//初始化最小权值为∞
		k = 0;//初始化最小权值下标
		for (j = 1; j < G->numNodes; j++)
		{
			//如果vj没有入树 && 当前树中与vj相连顶点的权值较小
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];//更新最小权值
				k = j;//更新最小权值的下标
			}
		}
		lowcost[k] = 0;//将找到的最小权值顶点入树
		w_min += G->arc[adjvex[k]][k];
		printf("(%d , %d)\n", adjvex[k], k);//输出拥有最小权值边的两个顶点

		//更新最小生成树：加入k顶点,更新两数组，为下次循环准备
		for (j = 1; j < G->numNodes; j++)
		{
			//如果vj未入树 && k与j相连边的权值<原来树中顶点与vj的权值
			if (lowcost[j] != 0 && G->arc[k][j] < lowcost[j])
			{
				lowcost[j] = G->arc[k][j];//更新lowcost为最小权值
				adjvex[j] = k;//表示j与k相连
			}
		}
	}
	printf("最小生成树的总权值：%d\n", w_min);
}

int main()
{
	while (1)
	{
		MGraph* G;
		G = (MGraph*)malloc(sizeof(MGraph));
		CreatMGraph(G);
		PrintMGraph(G);
		printf("\n秀一下最小生成树：\n");
		MiniSpanTree_Prim(G);
		printf("\n");
	}
	return 0;
}