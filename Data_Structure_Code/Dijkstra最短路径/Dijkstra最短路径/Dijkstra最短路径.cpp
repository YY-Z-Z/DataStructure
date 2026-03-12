#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

typedef char VerexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct
{
	VerexType vexs[MAXVEX];//储存顶点信息：ves[顶点序号]=顶点值
	EdgeType arc[MAXVEX][MAXVEX];//储存边的权值信息：arc[顶点1][顶点2]=顶点1与顶点2间边的权值
	int numNodes, numEdges;//顶点数和边数
}MGraph, * pMGraph;
typedef int Patharc[MAXVEX];//储存最短路径下标数组
typedef int ShortPathTable[MAXVEX];//储存到各点最短路径权值和

void CreateMGraph(pMGraph G)
{
	int i, j, k, w;
	printf("输入顶点数和边数(逗号断开):\n");
	scanf("%d,%d", &G->numNodes, &G->numEdges);
	getchar();
	printf("输入顶点信息:\n");
	for (i = 0; i < G->numNodes; i++) {
		printf("顶点%d信息:\n", i);
		scanf("%c", &G->vexs[i]);
		getchar();
	}
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = INFINITY;
	for (k = 0; k < G->numEdges; k++) {
		printf("输入第%d条边(vi,vj)的下标i,下标j和权w(逗号断开):\n", k + 1);
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = w;
	}
}

//Dijkstra,求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v]
//P[v]=v的前驱顶点下标（前驱即最短路径是经过哪个顶点实现的），D[v]=v0~v的最短路径长度和
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
	int v, w, k, min;
	int final[MAXVEX];//final[w]=1表示已经求得v0~vw的最短路径
	//初始化数据
	for (v = 0; v < G.numNodes; v++)
	{
		final[v] = 0;//全部顶点初始化为未知路径状态
		(*D)[v] = G.arc[v0][v];//将与v0有连线的顶点加上权值
		(*P)[v] = -1;//初始化路径数组
	}
	(*D)[v0] = 0;//v0到v0路径为0
	final[v0] = 1;//v0到v0不需要求路径
	//主循环，每次求得v0到v的最短路径
	for (v = 1; v < G.numNodes; v++)
	{
		min = INFINITY;//min:当前已知离v的最短路径
		//找离v0相连的顶点
		for (w = 0; w < G.numNodes; w++)
		{
			if (!final[w] && (*D)[w] < min) //经过w顶点更近
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;//将目前找到的最近顶点至为1
		//更新当前最短路径及距离
		for (w = 0; w < G.numNodes; w++)
		{
			//如果经过k顶点的路径比当前短
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];//修改路径长度
				(*P)[w] = k;//修改当前路径
			}
		}
	}
}
int main() {
	MGraph G;
	int v0;
	Patharc P;
	ShortPathTable D;
	int i, j;
	CreateMGraph(&G);
	printf("输入起始顶点序号:\n");
	scanf("%d", &v0);
	ShortestPath_Dijkstra(G, v0, &P, &D);
	for (i = 0; i < G.numNodes; i++) {
		if (i != v0 && D[i] != INFINITY) {
			printf("%c->%c最短路径长度： %d\n", G.vexs[i], G.vexs[v0], D[i]);
			printf("最短路径：");
			j = i;
			printf("%c", G.vexs[i]);
			while (P[j] != -1) {
				printf("->%c", G.vexs[P[j]]);
				j = P[j];
			}
			printf("->%c\n", G.vexs[v0]);
		}
	}
	return 0;
}