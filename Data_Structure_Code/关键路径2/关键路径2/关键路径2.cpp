#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

typedef int VerexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct EdgeNode {
	int adjvex;
	EdgeType weight;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode {
	VerexType data;
	EdgeNode* firstedge;
	int in;
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numNodes, numEdges;
}GraphAdjList;
void CreateALGraph(GraphAdjList* G);
int* etv, * ltv;
int* stack2;
int top2;
int TopologicalSort(GraphAdjList* G);
void CriticalPath(GraphAdjList* G);
int main() {
	GraphAdjList G;
	CreateALGraph(&G);
	CriticalPath(&G);
	return 0;
}
void CreateALGraph(GraphAdjList* G) {
	int i, j, k, w;
	EdgeNode* e;
	printf("请输入顶点数和边数：\n");
	scanf("%d %d", &G->numNodes, &G->numEdges);
	for (i = 0; i < G->numNodes; i++) {
		printf("请输入序号为%d的顶点：", i);
		scanf("%d", &G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
		G->adjList[i].in = 0;
	}
	getchar();
	for (k = 0; k < G->numEdges; k++) {
		printf("输入边（vi,vj)上的顶点序号和权重：\n");
		scanf("%d %d %d", &i, &j, &w);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->weight = w;
		if (G->adjList[i].firstedge == NULL) {
			G->adjList[i].firstedge = e;
			e->next = NULL;
		}
		else {
			e->next = G->adjList[i].firstedge;
			G->adjList[i].firstedge = e;
		}
		G->adjList[j].in++;
	}
}
int TopologicalSort(GraphAdjList* G) {
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;
	int count = 0;
	int* stack;
	stack = (int*)malloc(G->numNodes * sizeof(int));
	for (i = 0; i < G->numNodes; i++) {
		if (0 == G->adjList[i].in)
			stack[++top] = i;
	}
	top2 = 0;
	etv = (int*)malloc(G->numNodes * sizeof(int));
	for (i = 0; i < G->numNodes; i++)
		etv[i] = 0;
	stack2 = (int*)malloc(G->numNodes * sizeof(int));
	while (top != 0) {
		gettop = stack[top--];
		count++;
		stack2[++top2] = gettop;
		for (e = G->adjList[gettop].firstedge; e; e = e->next) {
			k = e->adjvex;
			if (!(--G->adjList[k].in))
				stack[++top] = k;
			if ((etv[gettop] + e->weight) > etv[k])
				etv[k] = etv[gettop] + e->weight;
		}
	}
	if (count < G->numNodes)
		return 0;
	else
		return 1;
}
void CriticalPath(GraphAdjList* G) {
	EdgeNode* e;
	int i, gettop, k, j;
	int ete, lte;
	TopologicalSort(G);
	ltv = (int*)malloc(G->numNodes * sizeof(int));
	for (i = 0; i < G->numNodes; i++)
		ltv[i] = etv[G->numNodes - 1];
	while (top2 != 0) {
		gettop = stack2[top2--];
		for (e = G->adjList[gettop].firstedge; e; e = e->next) {
			k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	for (j = 0; j < G->numNodes; j++) {
		for (e = G->adjList[j].firstedge; e; e = e->next) {
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;
			if (ete == lte)
				printf("<v%d - v%d> length: %d \n", G->adjList[j].data, G->adjList[k].data, e->weight);
		}
	}
}
void Free(EdgeNode* x) {
	EdgeNode* head, * ptr;
	head = x;
	ptr = head->next;
	while (ptr != NULL) {
		free(head);
		head = ptr;
		ptr = head->next;
	}
}